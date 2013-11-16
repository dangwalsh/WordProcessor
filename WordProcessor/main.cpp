//
//  main.cpp
//  WordProcessor
//
//  Created by Daniel Walsh on 11/15/13.
//  Copyright (c) 2013 Daniel Walsh. All rights reserved.
//
//#define MICROSOFT
#define __DEBUG
#define MAX 40

#include <iostream>

#include "WordProcessor.h"

using namespace std;

int main()
{
    WordProcessor processor;
    char comm;
    int start, end, target, count;
    string entry;
    
	cout << "Begin typing:\n\n";
    
	while (count < MAX) {
		getline(cin, entry);
        if (entry == "#") break;
		processor.appendLine(entry);
		++count;
	}
    
    cout << "\nThese are the lines in your document:\n" << endl;
	processor.print();
    
    while (1) {
        cout << "\nEnter a command: ";
        getline(cin, entry);
        comm = entry[0];
		switch(comm) {
            case 'I':
				cout << "\nInsert phrase: ";
				getline(cin, entry);
                cout << "\nAt line: ";
                getline(cin, entry);
                start = atoi(entry.c_str());
                processor.insertLine(start, entry);
                break;
            case 'A':
                cout << "\nAppend phrase: ";
                getline(cin, entry);
                processor.appendLine(entry);
                break;
            case 'M':
                cout << "\nMove lines: ";
                getline(cin, entry);
                start = atoi(entry.c_str());
                cout << "\nThrough: ";
                getline(cin, entry);
                end = atoi(entry.c_str());
                cout << "\nTo line: ";
                getline(cin, entry);
                target = atoi(entry.c_str());
                processor.moveLine(start, end, target);
                break;
            case 'F':
                cout << "\nFind: ";
                getline(cin, entry);
                processor.findLine(entry);
                break;
            case 'D':
                cout << "\nDelete line: ";
                getline(cin, entry);
                start = atoi(entry.c_str());
                processor.deleteLine(start);
                break;
            case 'Q':
                //cout << "\nExiting..." << endl;
                break;
            default:
                cout << "\nCommand not supported!\n" << endl;
                break;
		}
        
		if (comm == 'Q') break;
#ifdef __DEBUG
		cout << endl;
		processor.print();
#endif
	}
    
	cout << "\nSorting phrases...\n" << endl;
	processor.sortLines();
	cout << endl;
    
#ifdef MICROSOFT
	system("PAUSE");
#endif
    
    return EXIT_SUCCESS;
}

/*
list<string> processor;

void print();
void insertLine(int n, string st);
void appendLine(string st);
void moveLine(int start, int end, int target);
void deleteLine(int n);
void findLine(string st);
void sortLines();

int main()
{
	string phrase; 
	size_t count = 0;

	cout << "Begin typing:\n\n";

	while (count < MAX) {
		getline(cin, phrase);
        if (phrase == "#") break;
		processor.push_back(phrase);
		++count;
	}

	cout << "\nThese are the lines in your document:\n" << endl;
	print();

	char comm; int start, end, target;  string str; string entry;
	while (1) {
        cout << "\nEnter a command: ";
        getline(cin, entry);
        comm = entry[0];
		switch(comm) {
            case 'I':
				cout << "\nInsert phrase: ";
				getline(cin, str);
                cout << "\nAt line: ";
                getline(cin, entry);
                start = atoi(entry.c_str());
                insertLine(start, str);
                break;
            case 'A':
                cout << "\nAppend phrase: ";
                getline(cin, entry);
                appendLine(entry);
                break;
            case 'M':
                cout << "\nMove lines: ";
                getline(cin, entry);
                start = atoi(entry.c_str());
                cout << "\nThrough: ";
                getline(cin, entry);
                end = atoi(entry.c_str());
                cout << "\nTo line: ";
                getline(cin, entry);
                target = atoi(entry.c_str());
                moveLine(start, end, target);
                break;
            case 'F':
                cout << "\nFind: " << endl;
                getline(cin, entry);
                findLine(entry);
                break;
            case 'D':
                cout << "\nDelete line: ";
                getline(cin, entry);
                start = atoi(entry.c_str());
                deleteLine(start);
                break;
            case 'Q':
                cout << "\nExiting..." << endl;
                break;
            default:
                cout << "\nCommand not supported!\n" << endl;
                break;
		}

		if (comm == 'Q') break;
#ifdef __DEBUG
		cout << endl;
		print();
#endif
	}

	cout << "\nSorting phrases...\n" << endl;
	sortLines();
	cout << endl;
#ifdef MICROSOFT
	system("PAUSE");
#endif

    return EXIT_SUCCESS;
}

void print()
{
	for (list<string>::iterator it = processor.begin(); it != processor.end(); ++it)
		cout << distance(processor.begin(), it) << " " << *it << endl;
}

void insertLine(int n, string st)
{
	list<string>::iterator pos = processor.begin();
	advance(pos, n);
	processor.insert(pos, st);
}

void appendLine(string st)
{
	processor.push_back(st);
}

void moveLine(int start, int end, int target)
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

void findLine(string st)
{
	for (list<string>::iterator it = processor.begin(); it != processor.end(); ++it) {
		size_t found = it->find(st);
		if (found != string::npos) cout << distance(processor.begin(), it) << " " << *it << endl;
	}
}

void deleteLine(int n)
{
	list<string>::iterator pos = processor.begin();
	advance(pos, n);
	processor.erase(pos);
}

void sortLines()
{
	processor.sort();
	copy(processor.begin(), processor.end(), ostream_iterator<string>(cout, "\n"));
}
*/
