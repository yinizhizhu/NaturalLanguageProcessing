#include "nineSix.h"

//Done
nineSix::nineSix()
{
	endTag = 0;
	month = 1;
	day = 1;
	getRefer();
	getSymbol();
	return;
}
//Done
nineSix::~nineSix()
{
	return;
}
//Done
void nineSix::getRefer()
{
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
		refer.push_back(number);
	}
	return;
}
//Done
void nineSix::getSymbol()
{
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
	return;
}

void nineSix::readNext()
{
	string fileName = "96" + refer[month - 1] + refer[day - 1];
	ifstream in(fileName);
	if (!in.is_open())
	{
		cout << "Cannot open the " << fileName << "\"" << endl;
		return;
	}
	int len, lastStart = 0;
	string last = "";
	char dataArea[MAXL];
	while (!in.eof())
	{
		container.clear();
		memset(dataArea, MAXL, sizeof(char));
		in.read(dataArea, MAXL - 2);		//the '\n' needs a tag, and the end of the string also needs the tag.

		preHandle(dataArea);
		fMM();
		//bMM();
		//bM();
		getContent();

		container[0] = last + container[0]; //add the forward last one into the this part
		last = container[container.size() - 1];
		len = last.size();
		if (len == 1)
			last = "";
		else
			last = last.erase(len - 1, 1);
	}
	getNextState();
	return;
}
//Done
bool nineSix::isSymbol(string tmp)
{
	unsigned int i = 0, len = symbol.size();
	for (; i < len; i++)
	{
		if (tmp == symbol[i])
			return true;
	}
	return false;
}
//Done
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
//Done
void nineSix::preHandle(char* dataArea)
{
	int j, step;
	char tmp[6];
	unsigned int i = 0, len = strlen(dataArea) + 1;
	dataArea[len-1] = 255;
	for (; i < len;)
	{
		step = getSerialOne(dataArea[i]);
		if (step == 0)
		{
			if (dataArea[i] == '\n')
				dataArea[i] = 254;
			i++;
		}
		else if (step == 8)
			break;
		else
		{
			for (j = 0; j < step; j++)
				tmp[j] = dataArea[i + j];
			tmp[j] = '\0';
			if (j == 3 && isSymbol(string(tmp)))
			{
				position.push(dataArea + i);//store the head pointer of each part
				for (j = 0; j < step; j++)
					dataArea[i + j] = '\0';
			}
			i += j;
		}
	}
	return;
}
//Done
void nineSix::getContent()
{
	int len;
	char* move;
	char eachPart[99];
	while (!position.empty())
	{
		move = position.front();
		handleSymbolPos(move, eachPart);
		len = strlen(eachPart);
		if (len >= 1)
			container.push_back(string(eachPart));
		position.pop();
	}
	return;
}
//Done
void nineSix::handleSymbolPos(char* source, char* eachPart)
{
	int i = 0, j = 0;
	int len = strlen(source);
	for (; i < len; i++)
	{
		if (source[i] != 254)
			eachPart[j++] = source[i];
	}
	return;
}
//Done
int nineSix::getSerialOne(char byte)
{
	int counter = 0;
	unsigned int tag = 1 << 7;
	while (byte & tag)
	{
		counter++;
		tag = tag >> 1;
	}
	return counter;
}

void nineSix::fMM()
{
	//cut up each part in container, and store the result of handle
	return;
}

void nineSix::bMM()
{
	//cut up each part in container, and store the result of handle
	return;
}

void nineSix::bM()
{
	//cut up each part in container, and store the result of handle
	return;
}
//Done
void nineSix::showSymbol()			//for test
{
	unsigned int i = 0, len = symbol.size() - 1;
	cout << endl << "The symbol is:" << endl;
	for (; i < len; i++)
		cout << symbol[i] << symbol[i].size() << ", ";
	cout << symbol[i] << symbol[i].size() << endl;
	return;
}
//Done
void nineSix::showRefer()			//for test
{
	unsigned int i = 0, len = refer.size() - 1;
	cout << endl << "The reference is:" << endl;
	for (; i < len; i++)
		cout << refer[i] << ", ";
	cout << refer[i] << endl;
	return;
}
