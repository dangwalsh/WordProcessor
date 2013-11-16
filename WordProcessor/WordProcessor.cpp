//
//  WordProcessor.cpp
//  WordProcessor
//
//  Created by Daniel Walsh on 11/16/13.
//  Copyright (c) 2013 Daniel Walsh. All rights reserved.
//

#include "WordProcessor.h"

WordProcessor::WordProcessor()
{
    
}

WordProcessor::WordProcessor(const WordProcessor &rhs)
{
    
}

WordProcessor::~WordProcessor()
{
    
}

void WordProcessor::print()
{
	for (list<string>::iterator it = processor.begin(); it != processor.end(); ++it)
		cout << distance(processor.begin(), it) << " " << *it << endl;
}

void WordProcessor::insertLine(int n, string st)
{
	list<string>::iterator pos = processor.begin();
	advance(pos, n);
	processor.insert(pos, st);
}

void WordProcessor::appendLine(string st)
{
	processor.push_back(st);
}

void WordProcessor::moveLine(int start, int end, int target)
{
	list<string>::iterator pos = processor.begin();
	list<string>::iterator targ = processor.begin();
	advance(pos, start);
	advance(targ, ++target);
	for (int i = 0; i <= end - start; ++i){
		processor.insert(targ, *pos);
		processor.erase(pos++);
	}
}

void WordProcessor::findLine(string st)
{
	for (list<string>::iterator it = processor.begin(); it != processor.end(); ++it) {
		size_t found = it->find(st);
		if (found != string::npos) cout << distance(processor.begin(), it) << " " << *it << endl;
	}
}

void WordProcessor::deleteLine(int n)
{
	list<string>::iterator pos = processor.begin();
	advance(pos, n);
	processor.erase(pos);
}

void WordProcessor::sortLines()
{
	processor.sort();
	copy(processor.begin(), processor.end(), ostream_iterator<string>(cout, "\n"));
}