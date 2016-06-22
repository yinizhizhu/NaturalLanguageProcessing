#include "lexicon.h"
#include "gb_table.h"
//#define TEST

int main()
{
	lex c;
	c.showWords(0, 8);
	cout << endl;

	c.sortByLenAsc();
	c.showWords(0, 8);
	cout << endl;

	c.sortByLenDec();
	c.showWords(0, 8);

	cout << endl << c.getLenWords() << endl;
	
	gb d;
	d.showGbTable(0, 10);
	return 0;
}