#include <stdio.h>
#include "graphics.h"
#include "Functions.h"
int main()
{
	while (1) {
		char table[9][9] = { { ' ','1','2','3','4','5','6','7','8' },{ '1','.','.','.','.','.','.','.','.' },{ '2','.','.','.','.','.','.','.','.' },{ '3','.','.','.','.','.','.','.','.' },{ '4','.','.','.','w','b','.','.','.' },{ '5','.','.','.','b','w','.','.','.' },{ '6','.','.','.','.','.','.','.','.' },{ '7','.','.','.','.','.','.','.','.' },{ '8','.','.','.','.','.','.','.','.' } };
		int counter = 1, blackscore = 0, whitescore = 0, finish;
		initwindow(1000, 720, "OtheLLo");
		while (counter <= 60) {
			score(table, &blackscore, &whitescore);
			drawboard(table, &counter, whitescore, blackscore);
			lock(table, &counter);
			if (counter == 61)
				break;
			playgame(table, &counter, whitescore, blackscore);
			counter++;
		}
		score(table, &blackscore, &whitescore);
		drawboard(table, &counter, whitescore, blackscore);
		winner(blackscore, whitescore, &finish);
		if (finish == 2)
			break;
		if (finish == 1)
			closegraph();
	}
}