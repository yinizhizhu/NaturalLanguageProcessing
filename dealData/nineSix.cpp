#include "nineSix.h"


nineSix::nineSix()
{
	endTag = 0;
	month = 1;
	day = 1;
	char tmp[L];
	string number;
	for (int i = 1; i < 32; i++)
	{
		if (i >= 10)
			number = "";
		else
			number = "0";
		_itoa(i, tmp, 10);
		number += string(tmp);
		change.push_back(number);
	}
	ifstream in("symbol.txt");
	if (!in.is_open())
	{
		cout << "Cannot open the symbol.txt!" << endl;
		return;
	}
	char line[L];
	while (!in.eof())
	{
		memset(line, 0, L);
		in.getline(line, L - 1);
		symbol.push_back(string(line));
	}
	in.close();
}

nineSix::~nineSix()
{
	return;
}

void nineSix::readNext()
{
	string fileName = "96" + change[month - 1] + change[day - 1];
	ifstream in(fileName);
	if (!in.is_open())
	{
		cout << "Cannot open the " << fileName << "\"" << endl;
		return;
	}
	char dataArea[MAXL];
	queue<string> partArea;
	while (!in.eof())
	{
		memset(dataArea, MAXL, sizeof(char));
		in.read(dataArea, MAXL - 1);
		preHandle(dataArea);
	}
	getNextState();
	return;
}

bool nineSix::isSymbol(string tmp)
{
	for (unsigned int i = 0; i < symbol.size(); i++)
	{
		if (tmp == symbol[i])
			return true;
	}
	return false;
}

void nineSix::showSymbol()
{
	for (unsigned int i = 0; i < symbol.size(); i++)
		cout << symbol[i] << symbol[i].size() << endl;
	return;
}

void nineSix::getNextState()
{
	if (month <= 12)
	{
		if (day <= 31)
			day++;
		else if (day == 31)
		{
			day = 1;
			month++;
		}
	}
	else
		endTag = 1;
	return;
}

void nineSix::preHandle(char* dataArea)
{
	char tmp[6];
	for (unsigned int i = 0; i < strlen(dataArea); i+=2)
	{
		tmp[0] = dataArea[i];
		tmp[1] = dataArea[i + 1];
		tmp[2] = '\0';
		if (isSymbol(string(tmp)))
		{
			dataArea[i] = '\0';
			dataArea[i + 1] = '\0';
		}
	}
	return;
}