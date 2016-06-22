#include "gb_table.h"

gb::gb()
{
	ifstream in("gb_table.txt");
	if (!in.is_open())
	{
		cout << "Cannot open the lexicon.txt!" << endl;
		return;
	}
	int i = 0;
	char line[M];
	while (!in.eof())
	{
		memset(line, 0, M);
		in.getline(line, M - 1);
		gb_table.push_back(string(line));
		i++;
	}
	lenTable = i;
	in.close();
	return;
}

gb::~gb()
{
	cout << "You are out of the gb!" << endl;
	return;
}

int gb::inGbTable(string& a)
{
	for (int i = 0; i < lenTable; i++)
		if (gb_table[i] == a)
			return i;
	return -1;
}

void gb::showGbTable(int m, int n)
{
	for (int i = m; i < n; i++)
		cout << gb_table[i] << " ";
	cout << endl;
	return;
}