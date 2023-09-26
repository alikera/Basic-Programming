#include <stdio.h>
#include "Functions.h"
int main()
{
	char table[9][9] = { { ' ','1','2','3','4','5','6','7','8' },{ '1','.','.','.','.','.','.','.','.' },{ '2','.','.','.','.','.','.','.','.' },{ '3','.','.','.','.','.','.','.','.' },{ '4','.','.','.','w','b','.','.','.' },{ '5','.','.','.','b','w','.','.','.' },{ '6','.','.','.','.','.','.','.','.' },{ '7','.','.','.','.','.','.','.','.' },{ '8','.','.','.','.','.','.','.','.' } };
	print_table(table);
	int counter = 1, blackscore = 0, whitescore = 0;
	score(table, &blackscore, &whitescore);
	while (counter <= 60) {
		lock(table, &counter);
		if (counter == 61)
			break;
		playgame(table, &counter);
		score(table, &blackscore, &whitescore);
		counter++;
	}
	printf("\n");
	score(table, &blackscore, &whitescore);
	if (blackscore>whitescore)
		printf("The BLACK player has won");
	if (whitescore>blackscore)
		printf("The WHITE player has won");
}