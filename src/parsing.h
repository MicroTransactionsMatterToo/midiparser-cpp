//
// Created by Ennis Massey on 18/12/16.
//

#ifndef MIDIPARSER_C_PARSING_H
#define MIDIPARSER_C_PARSING_H

#include <vector>
#include <tuple>
#include "events.h"

// Define macros

#endif //MIDIPARSER_C_PARSING_H

#ifndef MIDIPARSER_C_STREAM_IMPORTS_H
#define MIDIPARSER_C_STREAM_IMPORTS_H

#include <iostream>
#include <fstream>
#include <ostream>
#include <istream>
#include <ios>


#endif //MIDIPARSER_C_STREAM_IMPORTS_H

// Namespace midiparser

namespace midiparser {

// UINT Parsing
/// Parses a 32bit unsigned integer
uint32_t ParseUint32(std::ifstream &input_file);

/// Parses a 24bit unsigned integer
uint32_t ParseUint24(std::ifstream &input_file);

/// Parses a 16bit unsigned integer
uint16_t ParseUint16(std::ifstream &input_file);

/// Parses a 7bit unsigned integer
uint8_t ParseUint7(std::ifstream &input_file);

/// Parses two 7bit unsigned integers
std::tuple<uint8_t, uint8_t> ParseTwoUint7(std::ifstream &input_file);

/// Parses an 8bit unsigned integer
uint8_t ParseUint8(std::ifstream &input_file);

// INT Parsing
/// Parse an 8bit signed integer
int8_t ParseInt8(std::ifstream &input_file);


// Other parsing
/// Parses a Pitch Wheel MIDI value
uint16_t ParsePitchWheelValue(std::ifstream &input_file);

/// Parses a variable length MIDI value
uint32_t ParseVariableLengthValue(std::ifstream &input_file);

/// Parses a MIDI status byte
std::tuple<uint8_t, uint8_t> ParseStatusByte(std::ifstream &input_file);

}