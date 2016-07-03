#pragma once
#if !defined NINE_SIX_H
#define NINE_SIX_H

#include "stdafx.h"
#include <map>
#include <queue>
#define L 39
#define MAXL 36900

using namespace std;

class nineSix
{
public:
	nineSix();						// to let the year, month and day initial
	~nineSix();						//clean the current source gotten from system
	void getRefer();	//for initial
	void getSymbol();	//for initial
	void readNext();				//to get the content of the text
	bool isSymbol(string tmp);
	void getNextState();
	void preHandle(char* dataArea);	//to get the content to put into container
	void getContent();
	void handleSymbolPos(char* source, char* eachPart);
	int getSerialOne(char byte);
	void fMM();						//forward max matching method
	void bMM();						//backward max matching method
	void bM();						//bi-direction max matching method
	void showSymbol();	//for test
	void showRefer();	//for test
private:
	int endTag;
	int month;
	int day;
	vector<string> refer;			//to store the reference
	vector<string> symbol;			//to store the symbol
	queue<char*> position;			//to store the head pointer of each part
	vector<string> container;		//to store the content of the text
	map<string, int> wordsCounter;	//to store the total number of the words
};

#endif