#include "mainwindow.h"
#include "metadata.h"

#include <QApplication>
#include <QFileDialog>
#include <QFileInfo>
#include <QLayout>
#include <QWidget>
#include <QSlider>
#include <QGridLayout>
#include <QStandardPaths>
#include <QMediaMetaData>
#include <QTime>
#include <QDirIterator>
#include <QHeaderView>

MainWindow::MainWindow()
: volumeSlider(Qt::Horizontal), trackSlider(Qt::Horizontal)
{
    playButton.setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    muteButton.setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    nextButton.setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    prevButton.setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));

    miniPlay.setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    miniNext.setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    miniPrev.setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    miniSwitch.setText("Full player");

    miniPlayerButton.setText("Mini player");
    volumeSlider.setRange(0, 100);
    volumeSlider.setValue(100);
    trackSlider.setRange(0, 100);

    connect(&playButton, &QPushButton::clicked, this, &MainWindow::play);
    connect(&volumeSlider, &QSlider::valueChanged, this, &MainWindow::setVolume);
    connect(&player, &QMediaPlayer::positionChanged, this, &MainWindow::onPositionChanged);
    connect(&player, &QMediaPlayer::durationChanged, this, &MainWindow::onDurationChanged);
    connect(&player, &QMediaPlayer::currentMediaChanged, this, &MainWindow::mediaChanged);
    connect(&trackSlider, &QSlider::sliderReleased, this, &MainWindow::trackSliderReleased);
    connect(&trackSlider, &QSlider::valueChanged, this, &MainWindow::setPosition);
    connect(&muteButton, &QPushButton::clicked, this, &MainWindow::mutePlayer);
    connect(&nextButton, &QPushButton::clicked, this, &MainWindow::nextTrack);
    connect(&prevButton, &QPushButton::clicked, this, &MainWindow::prevTrack);
    connect(&trackListView, &QTableWidget::cellDoubleClicked, this, &MainWindow::cellClicked);
    connect(&miniPlayerButton,&QPushButton::clicked,this,&MainWindow::miniPlayerClicked);

    connect(&miniPlay,&QPushButton::clicked,this,&MainWindow::play);
    connect(&miniNext,&QPushButton::clicked,this,&MainWindow::nextTrack);
    connect(&miniPrev,&QPushButton::clicked,this,&MainWindow::prevTrack);
    connect(&miniSwitch,&QPushButton::clicked,this,&MainWindow::miniPlayerClicked);

    QGridLayout * layout = new QGridLayout;
    layout->addWidget(&trackSlider, 0, 0, 1, 4);
    layout->addWidget(&labelDuration, 0, 4, 1, 1);

    layout->addWidget(&prevButton, 1, 0, 1, 1);
    layout->addWidget(&playButton, 1, 1, 1, 1);
    layout->addWidget(&nextButton, 1, 2, 1, 1);
    layout->addWidget(&muteButton, 1, 3, 1, 1);
    layout->addWidget(&volumeSlider, 1, 4, 1, 1);
    layout->addWidget(&miniPlayerButton,4,0,1,1);
    layout->addWidget(&metadataLabel, 2, 0, 1, 5);
    layout->addWidget(&trackListView, 3, 0, 1, 5);

    trackListView.setColumnCount(4);
    trackListView.setHorizontalHeaderLabels({"", "Title", "Artist", "Album"});
    trackListView.setSelectionBehavior(QTableWidget::SelectRows);
    trackListView.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QGridLayout * miniLayout = new QGridLayout;
    miniLayout->addWidget(&miniPrev,0,0,1,1);
    miniLayout->addWidget(&miniPlay,0,1,1,1);
    miniLayout->addWidget(&miniNext,0,2,1,1);
    miniLayout->addWidget(&miniSwitch,0,3,1,1);
    miniLayout->addWidget(&miniMetadata,1,0,1,3);
    miniLayout->addWidget(&miniDuration,1,3,1,1);

    QWidget * window = new QWidget;
    miniWindow  = new QWidget();

    // QWidget takes ownership of layout
    miniWindow->setLayout(miniLayout);
    window->setLayout(layout);

    setCentralWidget(window);           // QMainWindow takes ownership of central widget

    player.setPlaylist(&playlist);
}

void MainWindow::selectDirectory() {
    QStringList locations = QStandardPaths::standardLocations(QStandardPaths::MusicLocation);
    QUrl location = QFileDialog::getExistingDirectoryUrl(
        this,
        "",
        QUrl::fromLocalFile(locations[0]));
    loadFiles(location);
    updatePlaylist();
    updateTrackListView();
}

void MainWindow::loadFiles(QUrl location) {
    QDirIterator files(
        location.toLocalFile(),
        {"*.mp3", "*.mp4", "*.wav", "*.flac"},
        QDir::Files | QDir::Readable,
        QDirIterator::Subdirectories | QDirIterator::FollowSymlinks);

    while (files.hasNext()) {
        QUrl file = QUrl::fromLocalFile(files.next());
        Track track(file);
        fillTrackMetadata(&track);
        tracks.push_back(track);
    }
}

void MainWindow::updatePlaylist() {
    playlist.clear();

    for (size_t i = 0; i < tracks.size(); i++) {
        playlist.addMedia(tracks[i].file());
    }
}

void MainWindow::updateTrackListView() {
    trackListView.setRowCount(tracks.size());

    for (size_t i = 0; i < tracks.size(); i++) {
        QString title(tracks[i].title.c_str());
        QString artist(tracks[i].artist.c_str());
        QString album(tracks[i].album.c_str());

        // The table takes ownership of its items
        QTableWidgetItem* playingItem = new QTableWidgetItem("");
        playingItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        QTableWidgetItem* titleItem = new QTableWidgetItem(title);
        titleItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        QTableWidgetItem* artistItem = new QTableWidgetItem(artist);
        artistItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        QTableWidgetItem* albumItem = new QTableWidgetItem(album);
        albumItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        trackListView.setItem(i, 0, playingItem);
        trackListView.setItem(i, 1, titleItem);
        trackListView.setItem(i, 2, artistItem);
        trackListView.setItem(i, 3, albumItem);
    }
}

void MainWindow::play() {
    if(player.state() != 1) {
        player.play();
        playButton.setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        miniPlay.setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    }
    else {
        player.pause();
        playButton.setIcon(style() -> standardIcon(QStyle::SP_MediaPlay));
        miniPlay.setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }

}

void MainWindow::setVolume(int volume)
{
    qreal linearVolume = QAudio::convertVolume(volume / qreal(100.0),
                                                QAudio::LogarithmicVolumeScale,
                                                QAudio::LinearVolumeScale);
    player.setVolume(qRound(linearVolume * 100));

    if (player.volume() <= 0 && !playerMuted) {
        muted_volume = 0;
        mutePlayer();
    }
    else if (player.volume() > 0 && playerMuted) {
        muted_volume = volumeSlider.value();
        mutePlayer();
    }
}

void MainWindow::mutePlayer() {

    if (playerMuted && muted_volume == 0)
        return;
    playerMuted = !playerMuted;
    if (playerMuted){
        muted_volume = volumeSlider.value();
        player.setVolume(0);
        volumeSlider.setValue(0);
        muteButton.setIcon(style() -> standardIcon(QStyle::SP_MediaVolumeMuted));
    }
    else {
        player.setVolume(muted_volume);
        volumeSlider.setValue(muted_volume);
        muteButton.setIcon(style() -> standardIcon(QStyle::SP_MediaVolume));
    }
}

void MainWindow::onPositionChanged(qint64 position)
{
    trackSlider.setValue(position);
    setDurationLabel(position / 1000);
}

void MainWindow::onDurationChanged(qint64 position)
{
    trackSlider.setMaximum(position);
}

void MainWindow::setPosition(int newPosition)
{
    position = newPosition;
}

void MainWindow::trackSliderReleased()
{
    player.setPosition(position);
}

void MainWindow::setMetadataLabel(const Track& current)
{
    QString label = "Now playing: ";
    QString miniLabel ;
    label.append(current.title.c_str());
    miniLabel.append(current.title.c_str());
    label.append(" by ");
    miniLabel.append(" by " );
    label.append(current.artist.c_str());
    miniLabel.append(current.artist.c_str());
    metadataLabel.setText(label);
    miniMetadata.setText(miniLabel);
}

void MainWindow::setDurationLabel(qint64 duration) {
    auto mil = player.duration();
    auto min = mil / 60000;
    mil = mil - 60000 * min;
    auto sec = mil / 1000;
    mil = mil - 1000 * sec;

    QString timeStr;
    QTime current((duration / 3600) % 60, (duration / 60) % 60, duration % 60, (duration * 1000) % 1000);
    QTime total(0, min, sec);
    QString format = "mm:ss";
    timeStr = current.toString(format) + " / " + total.toString(format);
    labelDuration.setText(timeStr);
    miniDuration.setText(timeStr);
}

void MainWindow::nextTrack() {
    playlist.next();
    trackListView.hide();
    trackListView.show();
}

void MainWindow::prevTrack() {
    playlist.previous();
}

void MainWindow::mediaChanged(const QMediaContent& media) {
    Track track(media.canonicalUrl());
    fillTrackMetadata(&track);
    setMetadataLabel(track);
    int row = playlist.currentIndex();
    trackListView.selectRow(row);

    for (int i = 0; i < trackListView.rowCount(); i++) {
        auto item = trackListView.item(i, 0);

        if (item != nullptr) {
            item->setIcon(QIcon());
        }
    }

    auto item = trackListView.item(row, 0);

    if (item != nullptr) {
        item->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }
}

void MainWindow::cellClicked(int row, int column) {
    playlist.setCurrentIndex(row);
}

void MainWindow::miniPlayerClicked() {
    if (!mini) {
        mini = true;
        window()->hide();
        miniWindow->show();
    }
    else {
        window()->show();
        mini = false;
        miniWindow->hide();
    }
}

MainWindow::~MainWindow(){
    // attriute to free the memory of miniWindow(QWidget) when it's closed.
    miniWindow->setAttribute(Qt::WA_DeleteOnClose, true);
    miniWindow->close();            // close miniWindow upon destruction.
}
