#pragma once
#if !defined GB_TABLE_H
#define GB_TABLE_H

#include "stdafx.h"
#define M 9
using namespace std;

class gb
{
public:
	gb();
	~gb();
	int inGbTable(string& a);
	void showGbTable(int m, int n);
private:
	int lenTable;
	vector<string> gb_table;
};

#endif