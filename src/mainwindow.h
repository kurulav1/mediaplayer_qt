#pragma once

#include "media.h"

#include <QMainWindow>
#include <QPushButton>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSlider>
#include <QLabel>
#include <QTableWidget>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    void selectDirectory();
    ~MainWindow();

private slots:
    void play();
    void setVolume(int volume);
    void onPositionChanged(qint64 position);
    void onDurationChanged(qint64 position);
    void setPosition(int position);
    void trackSliderReleased();
    void mutePlayer();
    void nextTrack(); // slot to handle the next and previous button functionalities.
    void prevTrack();
    void mediaChanged(const QMediaContent& media);
    void cellClicked(int row, int column);
    void miniPlayerClicked();

private:
    void updatePlaylist();
    void updateTrackListView();
    void loadFiles(QUrl location);
    void setMetadataLabel(const Track& track);
    void setDurationLabel(qint64 duration);

    QMediaPlaylist playlist;
    QMediaPlayer player;
    QPushButton playButton;
    QPushButton nextButton;
    QPushButton prevButton;
    QPushButton miniPlayerButton;
    bool playerMuted = false;
    QPushButton muteButton;
    QLabel labelDuration;
    QLabel metadataLabel;
    QSlider volumeSlider;
    QSlider trackSlider;
    QTableWidget trackListView;

    QPushButton miniPlay;
    QPushButton miniNext;
    QPushButton miniPrev;
    QLabel miniDuration;
    QLabel miniMetadata;
    QPushButton miniSwitch;
    QWidget * miniWindow;

    std::vector<Track> tracks;

    int position = 0;
    int muted_volume;
    bool mini = false;

};
