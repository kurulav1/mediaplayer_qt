#pragma once

#include <QUrl>

class Track {
public:
    explicit Track(QUrl file);
    QUrl file() const;

    std::string title;
    std::string artist;
    std::string album;

private:
    QUrl file_;

};
