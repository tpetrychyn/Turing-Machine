//
//  Tape.h
//  Assignment6
//
//  Created by Taylor Petrychyn on 2015-02-24.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//

#ifndef __Assignment6__Tape__
#define __Assignment6__Tape__

using namespace std;

class node {
    char cell;
    node *next;
    node *previous;
    
    friend class Tape;
};

class Tape {
private:
    node *p;
    node *head;
    int length;
    node *prevP;
public:
    Tape();
    
    // sets p to point to the next element in the list
    // always call ResetP prior to the initial call to Iterate
    // always call IsPSet after each call to Iterate
    void IterateRight();
    
    void IterateLeft();
    
    // sets p to -1
    void ResetP();
    
    // checks whether p points to an element in the list
    bool IsPSet();
    
    // returns the value of the element pointed to by p
    // p must be set prior to calling Read
    // always call IsPSet prior to calling Read
    char Read();
    
    // inserts a new element into the list in sorted order
    // always call IsFull prior to calling InsertSorted
    // p will point to where the new element should be inserted
    // moves all elements to the right of p one element to the right to make space for the new element
    // sets p
    void InsertSortedRight(const char& letter);
    
    void InsertHead(const char& letter);
    
    void InsertTail(const char& letter);
    
    // inserts a new element into the list in sorted order
    // always call IsFull prior to calling InsertSorted
    // p will point to where the new element should be inserted
    // moves all elements to the right of p one element to the right to make space for the new element
    // sets p
    void InsertSortedLeft(const char& letter);
    
    // inserts a new node in the list
    // always call IsEmpty prior to calling InsertSorted
    // always call IsFull prior to calling InsertSorted
    // always call IsPSet prior to calling InsertSorted
    void InsertSorted(const char& letter);
    
    // deletes element pointed to by p
    // p must be set prior to calling DeleteSorted
    // always call IsPSet prior to calling DeleteSorted
    // all elements following the one pointed to by p are moved one element to the left
    // sets p
    void DeleteSorted();
    
    // writes a new value into the node pointed to by p
    // p must be set prior to calling Write
    // always call IsPSet prior to calling Write
    // will cause a problem in a sorted list if the key is changed
    void Write(const char& letter);
    
    node *GetP() { return p; }
    
};

#endif /* defined(__Assignment6__Tape__) */
