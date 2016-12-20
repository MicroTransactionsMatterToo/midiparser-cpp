//
// Created by Ennis Massey on 21/12/16.
//

#ifndef MIDIPARSER_C_PARSER_H
#define MIDIPARSER_C_PARSER_H

#include "events.h"
#include "parsing.h"
#include "components.h"



class Parser {
public:
    std::ifstream midi_file;

    Parser(const char* file_name);
    ~Parser();
};


#endif //MIDIPARSER_C_PARSER_H
