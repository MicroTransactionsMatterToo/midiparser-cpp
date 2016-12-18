//
// Created by Ennis Massey on 16/12/16.
//

#ifndef MIDIPARSER_C_EVENTS_H
#define MIDIPARSER_C_EVENTS_H

#include "midiparser.h"

// Enums
/**
 * The MIDI File type of the parsed file, e.g. Multi-track, Multi-file e.t.c
 */
enum FileType {
    SINGLE_TRACK,  /**<A single track MIDI file */
    MULTI_TRACK,   /**<A multi track MIDI file */
    MULTI_FILE     /**<A multi file MIDI file */
};


/// Time format used by file
/**
 * The time format used by the given file
 */
enum TimeFormat {
    METRIC_TIME_FORMAT,  /**< Default time format */
    SMPTE_TIME_FORMAT    /**< SMPTE base time format */
};


/// Type of header
enum HeaderType {
    FILE_HEADER,  /**< MIDI file header */
    TRACK_HEADER  /**< Track header */
};


// Class defs

/// MIDI Pitch Wheel event
class PitchWheelEvent {
public:
    uint8_t absolute;  /**<Absolute value of pitch */
    uint8_t channel;   /**<Channel event applies to */
    int16_t relative;  /**<Relative value of pitch */

    /// Constructor
    PitchWheelEvent(uint8_t absolute, uint8_t channel);
};


/// Generic for Notes
class NoteEvent {
};


/// NoteOn MIDI message
class NoteOn : public NoteEvent {
public:
    uint8_t pitch;  /**<Pitch value between 0-255*/
    uint8_t velocity;  /**<Velocity, or volume of note */
    uint8_t channel;   /**<Channel note is played on*/
    uint32_t time;  /**<MIDI timecode */

    /// Constructor
    NoteOn(uint8_t pitch, uint8_t velocity, uint32_t time, uint8_t channel);
};

/// NoteOff MIDI message
class NoteOff : public NoteEvent {
public:
    uint8_t pitch;      /**<Pitch value between 0-255*/
    uint8_t velocity;   /**<Velocity, or volume of note */
    uint8_t channel;    /**<Channel note is played on*/
    uint32_t time;      /**<MIDI timecode */

    /// Constructor
    NoteOff(uint8_t pitch, uint8_t velocity, uint32_t time, uint8_t channel);
};

/// Polyphonic after-touch MIDI message
class PolyphonicAfterTouch {
public:
    uint8_t pressure; /**<Pressure of note*/
    uint8_t pitch;    /**<Pitch value between 0-255*/
    uint8_t channel;  /**<Channel note is played on*/
    uint32_t time;    /**<MIDI timecode */

    /// Constructor
    PolyphonicAfterTouch(uint8_t pitch, uint8_t pressure, uint32_t time,
                         uint8_t channel);
};

/// MIDI Control change event
class ControlChange {
public:
    uint8_t controller;  /**<Controller to use */
    uint8_t value;       /**<Value to write to controller */
    uint8_t channel;     /**<Channel message applies to */
    uint32_t time; /**<MIDI timecode */

    /// Constructor
    ControlChange(uint8_t controller, uint8_t value, uint32_t time,
                  uint8_t channel);
};


/// Channel-wide aftertouch
class ChannelAfterTouch {
public:
    uint8_t pressure;  /**<Pressure of after-touch */
    uint8_t channel;   /**<Channel event applies to */
    uint32_t time;     /**<MIDI timcode */

    /// Constructor
    ChannelAfterTouch(uint8_t pressure, uint32_t time, uint8_t channel);
};


#endif //MIDIPARSER_C_EVENTS_H
