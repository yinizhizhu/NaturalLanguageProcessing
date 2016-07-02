#include "lexicon.h"
#include "gb_table.h"
#define TEST

int main()
{
	lex c;
#ifdef TEST
	c.showWords(0, 10);
	cout << endl;

	c.sortByLenAsc();
	c.showWords(0, 10);
	cout << endl;

	c.sortByLenDec();
	c.showWords(0, 10);
	cout << endl;

	c.testLexicon();
	cout << endl;
	cout << endl << c.getLenWords() << endl;
#endif
	gb d;
	d.showGbTable(0, 10);
	return 0;
}