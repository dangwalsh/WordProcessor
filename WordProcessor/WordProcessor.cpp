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
#ifdef _DEBUG
    cout << "default const\n";
#endif
}

WordProcessor::WordProcessor(const WordProcessor &rhs)
{
#ifdef _DEBUG
    cout << "copy const\n";
#endif
}

WordProcessor::~WordProcessor()
{
#ifdef _DEBUG
    cout << "destructor\n";
#endif
}

void WordProcessor::print()
{
	for (list<string>::iterator it = _processor.begin(); it != _processor.end(); ++it)
		cout << distance(_processor.begin(), it) << " " << *it << endl;
}

void WordProcessor::insertLine(int n, string st)
{
	list<string>::iterator pos = _processor.begin();
	advance(pos, n);
	_processor.insert(pos, st);
}

void WordProcessor::appendLine(string st)
{
	_processor.push_back(st);
}

void WordProcessor::moveLine(int start, int end, int target)
{
	list<string>::iterator pos = _processor.begin();
	list<string>::iterator targ = _processor.begin();
	advance(pos, start);
	advance(targ, ++target);
	for (int i = 0; i <= end - start; ++i){
		_processor.insert(targ, *pos);
		_processor.erase(pos++);
	}
}

void WordProcessor::findLine(string st)
{
	for (list<string>::iterator it = _processor.begin(); it != _processor.end(); ++it) {
		size_t found = it->find(st);
		if (found != string::npos) cout << distance(_processor.begin(), it) << " " << *it << endl;
	}
}

void WordProcessor::deleteLine(int n)
{
	list<string>::iterator pos = _processor.begin();
	advance(pos, n);
	_processor.erase(pos);
}

void WordProcessor::sortLines()
{
	_processor.sort();
	copy(_processor.begin(), _processor.end(), ostream_iterator<string>(cout, "\n"));
}