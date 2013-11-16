//
//  main.cpp
//  WordProcessor
//
//  Created by Daniel Walsh on 11/15/13.
//  Copyright (c) 2013 Daniel Walsh. All rights reserved.
//
//#define MICROSOFT
#define _DEBUG
#define MAX 5

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

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

	cout << "Begin typing:\n";
	getline(cin, phrase);
	while (count < MAX) {
		getline(cin, phrase);
        if (phrase == "#") break;
		processor.push_back(phrase);
		++count;
	}

	print();

	cout << "Enter a command:\n";
	char comm; int start, end, target;  string str; string entry;
	while (1) {
        cout << "Enter a command: ";
        getline(cin, entry);
        comm = entry[0];
		switch(comm) {
            case 'I':
                cout << "At line: ";
                getline(cin, entry);
                start = atoi(entry.c_str());
                cout << "Insert phrase:";
                getline(cin, str);
                insertLine(start, str);
                break;
            case 'A':
                cout << "Append phrase: " << endl;
                getline(cin, entry);
                appendLine(entry);
                break;
            case 'M':
                cout << "Move lines: " << endl;
                getline(cin, entry);
                start = atoi(entry.c_str());
                cout << "Through: " << endl;
                getline(cin, entry);
                end = atoi(entry.c_str());
                cout << "To line: " << endl;
                getline(cin, entry);
                target = atoi(entry.c_str());
                moveLine(start, end, target);
                break;
            case 'F':
                cout << "Find: " << endl;
                getline(cin, entry);
                findLine(entry);
                break;
            case 'D':
                cout << "Delete line: ";
                getline(cin, entry);
                start = atoi(entry.c_str());
                deleteLine(start);
                break;
            case 'Q':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Command not supported!" << endl;
                break;
		}

		if (comm == 'Q') break;
#ifdef _DEBUG
		print();
#endif
	}

	sortLines();

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
