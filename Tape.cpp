//
//  Tape.cpp
//  Assignment6
//
//  Created by Taylor Petrychyn on 2015-02-24.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//

#include "Tape.h"

#include <stdlib.h>

Tape::Tape() {
    p = NULL;
    head = NULL;
    length = 0;
    //prevP = NULL;
}

bool Tape::IsPSet() {
    if (p == NULL)
        return false;
    return true;
}

void Tape::IterateRight() {
    if (p == NULL)
        p = head;
    else
        p = p -> next;
    return;
}

void Tape::IterateLeft() {
    p = p -> previous;
}

void Tape::ResetP() {
    p = NULL;
    return;
}

char Tape::Read() {
    return p->cell;
}

void Tape::InsertSorted(const char& letter) {
    if (letter < p -> cell)
        return InsertSortedLeft (letter);
        // else x > p -> value
    else
        return InsertSortedRight (letter);
}

void Tape::InsertTail(const char& letter) {
    node* q = new node;
    q -> cell = letter;
    q -> next = NULL;
    prevP = p -> previous;
    while (p != NULL) {
        prevP = p;
        p = p -> next;
    }
    prevP -> next = q;
    q -> previous = prevP;
    p = q;
    length ++;
    return;
}

void Tape::InsertSortedRight(const char& letter) {
    node* q = new node;
    q -> cell = letter;
    prevP = p -> previous;
    while (p != NULL && letter >= p -> cell) {
        prevP = p;
        p = p -> next;
    }
    prevP -> next = q;
    q -> previous = prevP;
    q -> next = p;
    if (p != NULL)
        p -> previous = q;
    p = q;
    length ++;
    return;
}

void Tape::InsertSortedLeft(const char& letter) {
    node* q = new node;
    q -> cell = letter;
    prevP = p -> next;
    while (p != NULL && letter < p -> cell) {
        prevP = p;
        p = p -> previous;
    }
    prevP -> previous = q;
    q -> next = prevP;
    q -> previous = p;
    if (p == NULL)
        head = q;
    else
        p -> next = q;
    p = q;
    length ++;
    return;
}

void Tape::InsertHead(const char& letter) {
    node* q = new node;
    q -> cell = letter;
    q -> previous = NULL;
    if (head == NULL)
        q -> next = NULL;
    else
        head -> previous = q;
    q -> next = head;
    head = q;
    p = head;
    length ++;
    return;
}

void Tape::Write(const char& letter) {
    p->cell = letter;
}








