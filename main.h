//
//  main.h
//  Assignment6
//
//  Created by Taylor Petrychyn on 2015-02-24.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//

#ifndef Assignment6_main_h
#define Assignment6_main_h
#include "Tape.h"
#include "ActionTable.h"

//prints a tape object to the screen
//sets p to the end of the list
void printTape(Tape& tape);

//reads the data from a given file in proper format and stores it
//in a tape object and ActionTable object
//always ensure the given file is in proper turing machine assignment 6 format
void readFile(string filename, Tape& tape, ActionTable& table);


#endif
