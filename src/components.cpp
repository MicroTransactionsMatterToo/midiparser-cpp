//
// Created by Ennis Massey on 16/12/16.
//

#include "components.h"


// Implementation


/// Constructor
midiparser::MIDIHeader::MIDIHeader(int32_t length, FileType type, int64_t time_division,
                       int32_t number_of_tracks) :
        length(length),
        type(type),
        time_division_(time_division) {
    if ((time_division & 0x8000) == 0x0000) {
        time_format = METRIC_TIME_FORMAT;
        ticks_per_quarter_note = time_division & 0x7FFF;
    } else {
        std::cout << "SMPTE timecodes not yet supported" << std::endl;
        exit(1);
    }
}




/// Constructor
midiparser::TrackHeader::TrackHeader(int32_t length) : length(length) {}