#include "metadata.h"

#include <taglib/tag.h>
#include <taglib/fileref.h>
#include <taglib/tstring.h>

void fillTrackMetadata(Track* track) {
    TagLib::FileRef file(track->file().path().toUtf8());

    if (!file.isNull() && file.tag()) {
        TagLib::String title = file.tag()->title();
        TagLib::String artist = file.tag()->artist();
        TagLib::String album = file.tag()->album();

        track->title = title.to8Bit(true);
        track->artist = artist.to8Bit(true);
        track->album = album.to8Bit(true);
    }
}
