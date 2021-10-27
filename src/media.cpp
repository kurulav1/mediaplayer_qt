#include "media.h"

Track::Track(QUrl file) : file_(file), title("N/A"), artist("N/A"), album("N/A") {}

QUrl Track::file() const {
    return file_;
}
