//
// Created by Ennis Massey on 21/12/16.
//

#ifndef MIDIPARSER_C_PARSER_H
#define MIDIPARSER_C_PARSER_H

#include "events.h"
#include "parsing.h"
#include "components.h"

// Namespace midiparser
namespace midiparser {

enum LEX_STATE {
    EXPECT_HEADER,
    EXPECT_CHUNK,
    EXPECT_TRACK_EVENT
};

class Parser {
public:
    std::ifstream midi_file;

    /// Constructor
    Parser(const char *file_name);

    /// Deconstructor
    ~Parser();

    /// Performs parsing
    /*!
     * Uses internally stored data and parses it, storing the
     * parsed data in Parser.data
     *
     * error_code will be negative if an error occured, positive otherwise
     * @return error_code
     */
    int Parse();

private:
    LEX_STATE state_;

    int ParseTrackEvent();
};


}
#endif //MIDIPARSER_C_PARSER_H
