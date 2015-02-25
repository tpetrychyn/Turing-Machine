//
//  main.cpp
//  Assignment6
//
//  Created by Taylor Petrychyn on 2015-02-24.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

#include "main.h"

using namespace std;

int currPos;
int lineCount = 0;

int currState = 0;
int nextState = 0;

int main() {
    
    //initialize tape and actiontable
    Tape tape;
    ActionTable table;
    
    //populate them with the instructions from the file
    readFile("subtraction.txt", tape, table);
    
    table.ResetP();
    table.Iterate();
    while (table.Read().direction != 'H') {
        printTape(tape);
        //put tape in right spot
        tape.ResetP();
        for (int i=0;i<currPos;i++)
            tape.IterateRight();
        
        //table
        table.ResetP();
        table.Iterate();
        while (table.IsPSet()) { //loop through actiontable until our current state and symbol match
            if (table.Read().currState == currState && table.Read().readSymbol == tape.Read()) {
                tape.Write(table.Read().writeSymbol); //write the symbol
                currState = table.Read().nextState; //update our state
                if (table.Read().direction == 'R') { //move the head
                    if (tape.IsPSet()) {
                        tape.IterateRight();
                        currPos++;
                        break; //start over so we can get a proper print update
                    }
                } else if (table.Read().direction == 'L') {
                    if (tape.IsPSet()) {
                        tape.IterateLeft();
                        currPos--;
                        break;
                    }
                } else if (table.Read().direction == 'H')
                    break;
            }
            table.Iterate();
        }
    }
    
    cout << endl;
}

void readFile(string filename, Tape& tape, ActionTable& table) {
    //open file
    ifstream inData;
    inData.open(filename);
    if (!inData.is_open()) {
        cout << "Indata not found. Terminating." << endl;
        return;
    }
    
    tape.ResetP();
    tape.IterateRight();
    
    //Read in initial state
    string skip;
    char x;
    inData >> currState;
    getline(inData, skip);
    
    //read initial tape values
    inData >> x;
    tape.InsertHead(x);
    while (inData >> x) {
        if (x == '/')
            break;
        else
            tape.InsertTail(x);
    }
    getline(inData,skip);
    
    //fill in actionTable
    while (!inData.eof()) {
        //reset x
        char x;
        inData >> x;
        if (x == '/' || x == '\n') {
            getline(inData, skip);
            continue;
        }
        if (x == '-') {
            getline(inData, skip);
            break;
        }
        line newLine;
        newLine.currState = atoi(&x);
        inData >> newLine.readSymbol;
        //we do this to read in and convert our char to an int properly
        char nextState;
        inData >> nextState;
        newLine.nextState = atoi(&nextState);
        inData >> newLine.writeSymbol;
        inData >> newLine.direction;
        table.InsertUnsorted(newLine);
    }
    
    inData >> currPos;
    inData.close();
}

void printTape(Tape& tape) {
    //print out tape
    tape.ResetP();
    tape.IterateRight();
    while (tape.IsPSet()) {
        cout << tape.Read() << " ";
        tape.IterateRight();
    }
    cout << endl;
    cout << setw(currPos*2 - 1) << "^" << endl;
}
