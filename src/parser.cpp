//
// Created by Ennis Massey on 21/12/16.
//

#include "parser.h"


Parser::Parser(const char *file_name) {
    // Create new file variable
    midi_file.open(file_name,
                   std::ios_base::in | std::ios_base::binary);
    // Check to see if the file is open
    if (!midi_file.is_open()) {
        char temp[200];
        snprintf(temp, sizeof(temp), "Unable to open file: %s",
                        file_name);
        midi_file.close();
        return;
    } else {
        return;
    }
}


Parser::~Parser() {
    if (midi_file.is_open()) {
        midi_file.close();
    }
}