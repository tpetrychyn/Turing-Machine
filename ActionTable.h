//
//  ActionTable.h
//  Assignment6
//
//  Created by Taylor Petrychyn on 2015-02-24.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//the symbol read from the tape, (3) the next state, (4) the symbol to be written to the tape, and (5) the direction to move the read/write pointer, respectively. That is, each item corresponds to a “command” with the following format:


#ifndef __Assignment6__ActionTable__
#define __Assignment6__ActionTable__

#include <stdio.h>

struct line {
    int currState;
    char readSymbol;
    int nextState;
    char writeSymbol;
    char direction; //L - left, - no move, R - right, H - halt
    
    friend class ActionTable;
};

class ActionTable {
    int length;
    int p;
    line* lineList = new line[100];
public:
    ActionTable();
    
    // sets p to point to the next element in the list
    // always call ResetP prior to the initial call to Iterate
    // always call IsPSet after each call to Iterate
    void Iterate();
    
    // sets p to -1
    void ResetP();
    
    // checks whether p points to an element in the list
    bool IsPSet();
    
    // returns the value of the element pointed to by p
    // p must be set prior to calling Read
    // always call IsPSet prior to calling Read
    line Read();
    
    // inserts a new element at the end of the list
    // always call IsFull prior to calling InsertUnsorted
    // sets p
    void InsertUnsorted(line x);
    
    // returns the number of elements in the list
    int Length() { return length; };
};

#endif /* defined(__Assignment6__ActionTable__) */
