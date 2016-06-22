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
	int i = 0;
	char line[N], tmp[N], *move;
	while (!in.eof())
	{
		memset(line, 0, N);
		in.getline(line, N - 1);
		move = line;

		move += getWord(move, tmp);
		words.push_back(word());
		//if (i >= 12459 && i < 12479)
		//	cout << line << ": " << tmp << " ";
		words[i].token = string(tmp);
		while (*move != '\0')
		{
			move += getWord(move, tmp);
			words[i].pro.push_back(string(tmp));
			//if (i >= 12459 && i < 12479)
			//	cout << tmp << " ";
		}

		//if (i >= 12459 && i < 12479)
		//	cout << endl;

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
		case '0':
		case ' ':
		case 9:
		case '\n':
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
	return;
}

void lex::sortByLenDec()
{
	//sort(words.begin(), words.end(), greater<word>());
	sort(words.begin(), words.end(), cmpDec);
	return;
}

void lex::showPro(int n)
{
	for (int j = 0; j < words[n].lenPro; j++)
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

int lex::inLexicon(string& a)
{
	for (int i = 0; i<lenWords; i++)
		if (words[i].token == a)
			return i;
	return -1;
}

bool cmpAsc(const word& s1, const word& s2)	//for sort
{
	return s1.lenPro < s2.lenPro;
}

bool cmpDec(const word& s1, const word& s2)	//for sort
{
	return s1.lenPro > s2.lenPro;
}