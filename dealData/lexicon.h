#pragma once
#if !defined LEXICON_H
#define LEXICON_H

#include "stdafx.h"
#include <functional>
#include <algorithm>

#define N 189


typedef struct word
{
	string token;
	unsigned int lenPro;
	vector<string> pro;
	bool operator<(const word& rhs) const	//for asc
	{
		return lenPro < rhs.lenPro;
	}
	bool operator>(const word& rhs) const	//for dec
	{
		return lenPro > rhs.lenPro;
	}
} word;

class lex
{
public:
	lex();
	~lex();
	unsigned int lenWords;
	vector<word> words;
	vector<int> indexDec;
	vector<int> indexAsc;
	void clean(char* line);
	int getWord(char* line, char* tmp);
	int getLenWords();
	word getWordPos(int pos);
	void sortByLenAsc();
	void sortByLenDec();
	void showPro(int n);
	void showWords(int m, int n);
	void showIndexDec();
	void showIndexAsc();
	int inLexicon(string& a);	//return the index of the string 'a'
	void testLexicon();
};

#endif
