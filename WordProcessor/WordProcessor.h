//
//  WordProcessor.h
//  WordProcessor
//
//  Created by Daniel Walsh on 11/16/13.
//  Copyright (c) 2013 Daniel Walsh. All rights reserved.
//

#ifndef __WordProcessor__WordProcessor__
#define __WordProcessor__WordProcessor__

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

class WordProcessor {
    
private:
    list<string> processor;
    
public:
    // constructors
    WordProcessor();
    WordProcessor(const WordProcessor &);
    
    // destructor
    ~WordProcessor();
    
    // member functions
    void print();
    void insertLine(int n, string st);
    void appendLine(string st);
    void moveLine(int start, int end, int target);
    void deleteLine(int n);
    void findLine(string st);
    void sortLines();
};

#endif /* defined(__WordProcessor__WordProcessor__) */
