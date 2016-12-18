//
// Created by Ennis Massey on 16/12/16.
//

#ifndef MIDIPARSER_C_COMPONENTS_H
#define MIDIPARSER_C_COMPONENTS_H

#include "events.h"

// Class stubs

/// MIDI file header
class MIDIHeader {
public:
    int32_t length;  /**<Length of header in bytes */
    int32_t ticks_per_quarter_note; /**<Ticks per quarter note*/
    int32_t number_of_tracks; /**<Number of tracks */
    TimeFormat time_format; /**<Format of timecodes */
    FileType type; /**<Type of file */

    /// Constructor
    MIDIHeader(int32_t length, FileType type, int64_t time_division, int32_t
    number_of_tracks);



private:
    int64_t time_division_;

};


/// MIDI track header
class TrackHeader {
public:
    int32_t length; /**<Length of header in bytes */

    /// Constructor
    TrackHeader(int32_t length);

};

#endif //MIDIPARSER_C_COMPONENTS_H
