#include "lexicon.h"

bool cmpAsc(const word& s1, const word& s2);	//for sort
bool cmpDec(const word& s1, const word& s2);	//for sort

lex::lex()
{
	ifstream in("lexicon.txt");
	if (!in.is_open())
	{
		cout << "Cannot open the lexicon.txt!" << endl;
		return;
	}
	int i = 0, tag = 0;
	char line[N], tmp[N], *move;
	while (true)
	{
		memset(line, 0, N);
		in.getline(line, N - 1);
		move = line;

		tag = getWord(move, tmp);
		if (strlen(tmp) > 0)
		{
			move += tag;
			words.push_back(word());
			words[i].token = string(tmp);
		}
		if (tag == 0)
			break;
		while (true)
		{
			tag = getWord(move, tmp);
			if (strlen(tmp) > 0)
				words[i].pro.push_back(string(tmp));

			if (tag == 0)
				break;
			move += tag;
		}
		words[i].lenPro = words[i].pro.size();
		i++;
	}
	lenWords = i;
	in.close();
	return;
}

lex::~lex()
{
	cout << "You are out the lex!" << endl;
	return;
}

int lex::getWord(char* line, char* tmp)
{
	int i = 0;
	for (;; i++)
	{
		switch (line[i])
		{
		case '\0':
			tmp[i] = '\0';
			return 0;
		case ' ':
		case 9:
			tmp[i] = '\0';
			return i + 1;
		default:
			tmp[i] = line[i];
			break;
		}
	}
}

int lex::getLenWords()
{
	return words.size();
	return lenWords;
}

void lex::sortByLenAsc()
{
	//sort(words.begin(), words.end(), less<word>());
	sort(words.begin(), words.end(), cmpAsc);
	if (indexAsc.empty())
	{
		unsigned int i, tmp;
		tmp = words[0].lenPro;
		indexAsc.push_back(0);
		for (i = 1; i < words.size(); i++)
		{
			if (tmp ^ words[i].lenPro)
			{
				tmp = words[i].lenPro;
				indexAsc.push_back(i);
			}
		}
		indexAsc.push_back(i);
	}
	return;
}

void lex::sortByLenDec()
{
	//sort(words.begin(), words.end(), greater<word>());
	sort(words.begin(), words.end(), cmpDec);
	if (indexDec.empty())
	{
		unsigned int i, tmp;
		tmp = words[0].lenPro;
		indexDec.push_back(0);
		for (i = 1; i < words.size(); i++)
		{
			if (tmp ^ words[i].lenPro)
			{
				tmp = words[i].lenPro;
				indexDec.push_back(i);
			}
		}
		indexDec.push_back(i);
	}
	return;
}

void lex::showPro(int n)
{
	for (unsigned int j = 0; j < words[n].lenPro; j++)
		cout << words[n].pro[j]<<" ";
	return;
}

void lex::showWords(int m, int n)
{
	for (int i = m; i < n; i++)
	{
		cout << words[i].token << ": " << words[i].token.size() << ">>" << words[i].lenPro << ">>";
		showPro(i);
		cout << endl;
	}
	return;
}

void lex::showIndexAsc()
{
	unsigned int i, len = indexAsc.size();
	for (i = 0; i < (len - 1); i++)
		cout << indexAsc[i] << ", ";
	cout << indexAsc[i] << endl;
	return;
}

void lex::showIndexDec()
{
	unsigned int i, len = indexDec.size();
	for (i = 0; i < (len - 1); i++)
		cout << indexDec[i] << ", ";
	cout << indexDec[i] << endl;
	return;
}

int lex::inLexicon(string& a)
{
	for (unsigned int i = 0; i<lenWords; i++)
		if (words[i].token == a)
			return i;
	return -1;
}

void lex::testLexicon()
{
	cout << "Wrong part of data is here:" << endl;
	for (unsigned int i = 0; i < lenWords; i++)
	{
		if (words[i].token.size() != (words[i].lenPro * 2))
		{
			cout << words[i].token << ": " << words[i].token.size() << ">>" << words[i].lenPro << ">>";
			showPro(i);
			cout << endl;
		}
	}
	return;
}

bool cmpAsc(const word& s1, const word& s2)	//for sort
{
	return s1.lenPro < s2.lenPro;
}

bool cmpDec(const word& s1, const word& s2)	//for sort
{
	return s1.lenPro > s2.lenPro;
}