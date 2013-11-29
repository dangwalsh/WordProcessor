//
//  main.cpp
//  WordProcessor
//
//  Created by Daniel Walsh on 11/15/13.
//  Copyright (c) 2013 Daniel Walsh. All rights reserved.
//
//#define MICROSOFT
//#define _DEBUG
#define MAX 40

#include <iostream>
#include "WordProcessor.h"

using namespace std;

int main()
{
    WordProcessor processor;
    char comm;
    int start, end, target, count = 0;
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
        cout << "\nEnter a command (type ? for help): ";
        getline(cin, entry);
        comm = entry[0];
		switch(comm) {
            case 'I':
                cout << "\nAt line: ";
                getline(cin, entry);
                start = atoi(entry.c_str());
				cout << "\nInsert phrase: ";
				getline(cin, entry);
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
                break;
            case '?':
                cout << "\n"
                     << "I\tInsert phrase at specified line number.\n"
                     << "A\tAppend phrase to the end of document.\n"
                     << "M\tMove range of lines to new line number.\n"
                     << "F\tFind the line(s) containing specified word.\n"
                     << "D\tDelete specified line number.\n"
                     << "Q\tQuit.\n";
                break;
            default:
                cout << "\nCommand not supported!\n" << endl;
                break;
		}
        
		if (comm == 'Q') break;
#ifdef _DEBUG
		cout << endl;
		processor.print();
#endif
	}
    cout << "\nFinal document:\n" << endl;
    processor.print();
	cout << "\nSorted phrases:\n" << endl;
	processor.sortLines();
	cout << endl;
    
#ifdef MICROSOFT
	system("PAUSE");
#endif
    
    return EXIT_SUCCESS;
}
