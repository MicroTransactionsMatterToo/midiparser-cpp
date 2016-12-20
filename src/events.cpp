// Copyright Ennis Massey 16/12/16
//
// Created by Ennis Massey on 16/12/16.
//

#include "events.h"


// Implementation of classes

midiparser::PitchWheelEvent::PitchWheelEvent(uint16_t absolute, uint8_t
        channel) :
        absolute(absolute), channel(channel) {
    relative = (uint16_t) (absolute - 0x2000);
}


midiparser::NoteOn::NoteOn(uint8_t pitch,
               uint8_t velocity,
               uint32_t time,
               uint8_t channel) :
        pitch(pitch),
        velocity(velocity),
        channel(channel),
        time(time) {}


midiparser::NoteOff::NoteOff(uint8_t pitch,
               uint8_t velocity,
               uint32_t time,
               uint8_t channel) :
        pitch(pitch),
        velocity(velocity),
        channel(channel),
        time(time) {}

midiparser::PolyphonicAfterTouch::PolyphonicAfterTouch(uint8_t pitch, uint8_t pressure,
                                           uint32_t time, uint8_t channel) :
        pressure(pressure),
        pitch(pitch),
        channel(channel),
        time(time) {}


midiparser::ControlChange::ControlChange(uint8_t controller, uint8_t value, uint32_t time,
                             uint8_t channel) :
        controller(controller),
        value(value),
        channel(channel),
        time(time) {}

midiparser::ChannelAfterTouch::ChannelAfterTouch(uint8_t pressure, uint32_t time,
                                     uint8_t channel) :
        pressure(pressure),
        channel(channel),
        time(time) {}

