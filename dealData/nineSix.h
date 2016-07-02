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
	void readNext();				//to get the content of the text
	bool isSymbol(string tmp);
	void showSymbol();
	void getNextState();
	void preHandle(char* dataArea);	//to get the content to put into container
	void fMM();						//forward max matching method
	void bMM();						//backward max matching method
	void bM();						//bi-direction max matching method
private:
	int endTag;
	int month;
	int day;
	vector<string> change;
	vector<string> symbol;
	vector<string> container;		//to store the content of the text
	map<string, int> wordsCounter;	//to get the total number of the words
};

#endif