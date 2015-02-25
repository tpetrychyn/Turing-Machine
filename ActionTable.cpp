//
//  ActionTable.cpp
//  Assignment6
//
//  Created by Taylor Petrychyn on 2015-02-24.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//

#include "ActionTable.h"

ActionTable::ActionTable() {
    length = 0;
    p = -1;
}

void ActionTable::ResetP() {
    p = -1;
    return;
}

void ActionTable::Iterate() {
    p++;
    return;
}

bool ActionTable::IsPSet() {
    if (p < 0 || p > length - 1)
        return false;
    return true;
}

line ActionTable::Read() {
    return lineList[p];
}

void ActionTable::InsertUnsorted(line x) {
    p = length;
    lineList[p] = x;
    length ++;
    return;
}