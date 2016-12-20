// Copyright Ennis Massey 16/12/16
//
// Created by Ennis Massey on 16/12/16.
//

#include "operator_overrides.h"


std::ostream &operator<<(std::ostream &os, midiparser::MIDIHeader const &obj) {
    char temp_buffer[200];
    int error;
    error = snprintf(temp_buffer, sizeof(temp_buffer),
                     "Length: %d; Type: %d; TPQN: %d; Time Format: %d",
                     obj.length,
                     obj.type,
                     obj.ticks_per_quarter_note,
                     obj.time_format);

    if (error < 0) {
        std::cout << "String formatting fucked up" << std::endl;
        return os;
    } else {
        os << temp_buffer;
        return os;
    }
}

std::ostream &operator<<(std::ostream &os, midiparser::TrackHeader const &obj) {
    char temp_buffer[200];
    int error;
    error = snprintf(temp_buffer, sizeof(temp_buffer),
                     "Length: %d",
                     obj.length);

    if (error < 0) {
        std::cout << "String formatting fucked up" << std::endl;
        return os;
    } else {
        os << temp_buffer;
        return os;
    }
}

std::ostream &operator<<(std::ostream &os, midiparser::NoteOn const &obj) {
    char temp_buffer[200];
    int error;
    error = snprintf(temp_buffer, sizeof(temp_buffer),
                     "NoteOn Pitch: %d, Velocity: %d",
                     obj.pitch,
                     obj.velocity
    );
    if (error < 0) {
        std::cout << "String formatting fucked up" << std::endl;
        return os;
    } else {
        os << temp_buffer;
        return os;
    }
}

std::ostream &operator<<(std::ostream &os, midiparser::NoteOff const &obj) {
    char temp_buffer[200];
    int error;
    error = snprintf(temp_buffer, sizeof(temp_buffer),
                     "NoteOff Pitch: %d, Velocity: %d",
                     obj.pitch,
                     obj.velocity
    );
    if (error < 0) {
        std::cout << "String formatting fucked up" << std::endl;
        return os;
    } else {
        os << temp_buffer;
        return os;
    }
}

std::ostream &operator<<(std::ostream &os, midiparser::PolyphonicAfterTouch const &obj) {
    char temp_buffer[200];
    int error;
    error = snprintf(temp_buffer, sizeof(temp_buffer),
                     "Polyphonic Aftertouch, Pressure: %d, Pitch: %d",
                     obj.pressure,
                     obj.pitch
    );
    if (error < 0) {
        std::cout << "String formatting fucked up" << std::endl;
        return os;
    } else {
        os << temp_buffer;
        return os;
    }
}

std::ostream &operator<<(std::ostream &os, midiparser::ControlChange const &obj) {
    char temp_buffer[200];
    int error;
    error = snprintf(temp_buffer, sizeof(temp_buffer),
                     "Control Change from %d to %d",
                     obj.controller,
                     obj.value
    );
    if (error < 0) {
        std::cout << "String formatting fucked up" << std::endl;
        return os;
    } else {
        os << temp_buffer;
        return os;
    }
}