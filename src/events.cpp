//
// Created by Ennis Massey on 16/12/16.
//

#include "events.h"


// Implementation of classes

PitchWheelEvent::PitchWheelEvent(uint8_t absolute, uint8_t channel) :
        absolute(absolute), channel(channel) {
    relative = (uint16_t) (absolute - 0x2000);
}


NoteOn::NoteOn(uint8_t pitch,
               uint8_t velocity,
               uint32_t time,
               uint8_t channel) :
        pitch(pitch),
        velocity(velocity),
        channel(channel),
        time(time) {}


NoteOff::NoteOff(uint8_t pitch,
               uint8_t velocity,
               uint32_t time,
               uint8_t channel) :
        pitch(pitch),
        velocity(velocity),
        channel(channel),
        time(time) {}

PolyphonicAfterTouch::PolyphonicAfterTouch(uint8_t pitch, uint8_t pressure,
                                           uint32_t time, uint8_t channel) :
        pressure(pressure),
        pitch(pitch),
        channel(channel),
        time(time) {}


ControlChange::ControlChange(uint8_t controller, uint8_t value, uint32_t time,
                             uint8_t channel) :
        controller(controller),
        value(value),
        time(time),
        channel(channel) {}

ChannelAfterTouch::ChannelAfterTouch(uint8_t pressure, uint32_t time,
                                     uint8_t channel) :
        pressure(pressure),
        time(time),
        channel(channel) {}

