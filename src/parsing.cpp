// Copyright Ennis Massey 18/12/16
//
// Created by Ennis Massey on 18/12/16.
//

#include "parsing.h"


uint32_t midiparser::ParseUint32(std::ifstream &input_file) {
    // If the file isn't open, return 0
    if (!input_file.is_open()) {
        return (uint32_t) 0;
    }
    // Create buffer
    char buffer[4];
    // Read from stream
    input_file.read(buffer, 4);
    // If we couldn't read 4 bytes, we just return 0
    if (input_file.eof()) {
        return (uint32_t) 0;
    }
    uint32_t value = (uint32_t) 0x00;
    value |= (uint32_t) buffer[3] << 0;
    value |= (uint32_t) buffer[2] << 8;
    value |= (uint32_t) buffer[1] << 16;
    value |= (uint32_t) buffer[0] << 24;

    return value;
}


uint32_t midiparser::ParseUint24(std::ifstream &input_file) {
    // If the file isn't open, return 0
    if (!input_file.is_open()) {
        return (uint32_t) 0;
    }
    // Create buffer
    char buffer[3];
    // Read from stream
    input_file.read(buffer, 3);
    // If we couldn't read 3 bytes, return 0
    if (input_file.eof()) {
        return (uint32_t) 0;
    }
    uint32_t value = 0x00;
    value |= (uint32_t) buffer[2] << 0;
    value |= (uint32_t) buffer[1] << 8;
    value |= (uint32_t) buffer[0] << 16;

    return value;
}

uint16_t midiparser::ParseUint16(std::ifstream &input_file) {
    // If the file isn't open, return 0
    if (!input_file.is_open()) {
        return (uint16_t) 0;
    }
    // Create buffer
    char buffer[2];
    // Read from stream
    input_file.read(buffer, 2);
    if (input_file.eof()) {
        return (uint16_t) 0;
    }
    uint16_t value = 0x00;
    value |= (uint16_t) buffer[1] << 0;
    value |= (uint16_t) buffer[0] << 8;

    return value;
}

uint8_t midiparser::ParseUint7(std::ifstream &input_file) {
    if (!input_file.is_open()) {
        return (uint8_t) 0;
    }
    char buffer[1];
    input_file.read(buffer, 1);
    if (input_file.eof()) {
        return (uint8_t) 0;
    }
    uint8_t value = 0x00;
    value = (uint8_t) (buffer[0] & 0x7F);

    return value;
}

std::tuple<uint8_t, uint8_t> midiparser::ParseTwoUint7(std::ifstream &input_file) {
    if (!input_file.is_open()) {
        return std::make_tuple((uint8_t) 0, (uint8_t) 0);
    }
    char buffer[2];
    input_file.read(buffer, 2);
    if (input_file.eof()) {
        return std::make_tuple((uint8_t) 0, (uint8_t) 0);
    }
    uint8_t value_one = (uint8_t) (buffer[0] & 0x7F);
    uint8_t value_two = (uint8_t) (buffer[1] & 0x7F);
    std::tuple<uint8_t, uint8_t> value = std::make_tuple(value_one, value_two);

    return value;
}

uint8_t midiparser::ParseUint8(std::ifstream &input_file) {
    if (!input_file.is_open()) {
        return (uint8_t) 0;
    }
    char buffer[1];
    input_file.read(buffer, 1);
    if (input_file.eof()) {
        return (uint8_t) 0;
    }
    return (uint8_t) buffer[0];
}

int8_t midiparser::ParseInt8(std::ifstream &input_file) {
    if (!input_file.is_open()) {
        return (int8_t) 0;
    }
    char buffer[1];
    input_file.read(buffer, 1);
    if (input_file.eof()) {
        return (int8_t) 0;
    }

    return (int8_t) buffer[0];
}

uint16_t midiparser::ParsePitchWheelValue(std::ifstream &input_file) {
    if (!input_file.is_open()) {
        return (uint16_t) 0;
    }
    char buffer[2];
    input_file.read(buffer, 2);
    if (input_file.eof()) {
        return (uint16_t) 0;
    }
    uint16_t value = 0x00;
    value = (uint16_t) (buffer[1] & 0x7F);
    value <<= 7;
    value |= (uint16_t) (buffer[0] & 0x7F);

    return value;
}

uint32_t midiparser::ParseVariableLengthValue(std::ifstream &input_file) {
    if (!input_file.is_open()) {
        return (uint32_t) 0;
    }
    char buffer[1];
    bool did_return = false;
    uint32_t value = 0x00;
    bool first = true;
    while (first || (((buffer[0] & 0x80) == 0x80) && (did_return))) {
        value <<= 7;
        input_file.read(buffer, 1);
        if (input_file.eof()) {
            did_return = false;
            break;
        }
        did_return = true;
        value |= (uint32_t) buffer[0] & 0x7F;
        first = false;
    }

    return value;
}