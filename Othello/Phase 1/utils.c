#include <stdio.h>
#include "Functions.h"
void score(char table[9][9], int* blackscore, int *whitescore) {
	int i = 0, j = 0;
	*blackscore = 0, *whitescore = 0;

	for (i = 0; i <= 8; i++) {
		for (j = 0; j <= 8; j++) {
			if (table[i][j] == 'b')
				(*blackscore)++;
			if (table[i][j] == 'w')
				(*whitescore)++;
		}
	}
	printf("[b=%d w=%d] \n", *blackscore, *whitescore);
}
void print_table(char table[9][9]) {
	int i = 0, j = 0;
	for (i = 0; i <= 8; i++) {
		printf("\n");
		for (j = 0; j <= 8; j++) {
			printf("%c  ", table[i][j]);
		}
	}
}
int lock(char table[9][9], int *counter) {
	int flag = 0, i, j, k, l;
	int validmove_up = 0, validmove_down = 0, validmove_left = 0, validmove_right = 0, validmove_downleft = 0, validmove_upleft = 0, validmove_downright = 0, validmove_upright = 0;
	char samecolor, oppositecolor;
	if (*counter % 2 == 1) {
		samecolor = 'b';
		oppositecolor = 'w';
	}
	else {
		samecolor = 'w';
		oppositecolor = 'b';
	}

	for (i = 1; i <= 8; i++) {
		for (j = 1; j <= 8; j++) {
			/*check for available valid move in rows*/
			if (table[i][j] == '.') {
				flag = 0;
				k = j - 1;
				while (table[i][k] == oppositecolor) {
					k--;
					flag = 1;
				}
				if (flag == 1 && table[i][k] == samecolor)
					validmove_right++;

				k = j + 1;
				while (table[i][k] == oppositecolor) {
					k++;
					flag = 1;
				}
				if (flag == 1 && table[i][k] == samecolor)
					validmove_left++;
			}
		}
	}

	for (j = 1; j <= 8; j++) {
		for (i = 1; i <= 8; i++) {
			/*check for available valid move in columns*/
			if (table[i][j] == '.') {
				flag = 0;
				k = i - 1;
				while (table[k][j] == oppositecolor) {
					k--;
					flag = 1;
				}
				if (flag == 1 && table[k][j] == samecolor)
					validmove_down++;

				flag = 0;
				k = i + 1;
				while (table[k][j] == oppositecolor) {
					k++;
					flag = 1;
				}
				if (flag == 1 && table[k][j] == samecolor)
					validmove_up++;
			}
		}
	}

	for (j = 1; j <= 8; j++) {
		for (i = 1; i <= 8; i++) {
			/*check for available valid move in diameters*/
			if (table[i][j] == '.') {
				flag = 0;
				k = i - 1;
				l = j + 1;
				while (table[k][l] == oppositecolor) {
					k--;
					l++;
					flag = 1;
				}
				if (flag == 1 && table[k][l] == samecolor)
					validmove_downleft++;

				flag = 0;
				k = i + 1;
				l = j + 1;
				while (table[k][l] == oppositecolor) {
					k++;
					l++;
					flag = 1;
				}
				if (flag == 1 && table[k][l] == samecolor)
					validmove_upleft++;

				flag = 0;
				k = i - 1;
				l = j - 1;
				while (table[k][l] == oppositecolor) {
					k--;
					l--;
					flag = 1;
				}
				if (flag == 1 && table[k][l] == samecolor)
					validmove_downright++;

				flag = 0;
				k = i + 1;
				l = j - 1;
				while (table[k][l] == oppositecolor) {
					k++;
					l--;
					flag = 1;
				}
				if (flag == 1 && table[k][l] == samecolor)
					validmove_upright++;
			}
		}
	}

	if (validmove_upleft == 0 && validmove_downleft == 0 && validmove_upright == 0 && validmove_downright == 0 && validmove_up == 0 && validmove_down == 0 && validmove_left == 0 && validmove_right == 0)
		(*counter) = 61;

}
int playgame(char table[9][9], int *counter) {
	int i = 0, j = 0, k = 0, l = 0, flag, up, down, left, right, diagonal_leftup, diagonal_upleft, diagonal_leftdown, diagonal_downleft, diagonal_rightup, diagonal_upright, diagonal_rightdown, diagonal_downright;
	int input;
	char samecolor, oppositecolor;
	if (*counter % 2 == 1) {
		samecolor = 'b';
		oppositecolor = 'w';
	}
	else {
		samecolor = 'w';
		oppositecolor = 'b';
	}
	/*check for valid input*/
	flag = 0;
	int outofrange = 0, occupiedd = 0, wrongmove = 0;
	while (flag != 1) {
		if (*counter % 2 == 1)
			printf("BLACK player's turn:");
		else
			printf("WHITE player's turn:");

		while (1) {
			int character = scanf("%d", &input);
			if (character == 0) {
				printf("Bad input");
				while (1) {
					char c = getchar();
					if (c == '\n')
						break;
				}
			}
			else
				break;
		}

		outofrange = 0, occupiedd = 0, wrongmove = 0;
		while (outofrange == 0 || occupiedd == 0 || wrongmove == 0) {
			while (input>88 || input<11 || input == 20 || input == 30 || input == 40 || input == 50 || input == 60 || input == 70 || input == 80) {
				printf("invalid number");
				int character = scanf("%d", &input);
				if (character == 0) {
					printf("Bad input\n");
					while (1) {
						char c = getchar();
						if (c == '\n')
							break;
					}
				}
			}

			outofrange = 1;
			j = input % 10;
			i = input / 10;

			while (table[i][j] != '.') {
				printf("occupied");
				int character = scanf("%d", &input);
				if (character == 0) {
					printf("Bad input\n");
					while (1) {
						char c = getchar();
						if (c == '\n')
							break;
					}
				}
				j = input % 10;
				i = input / 10;
			}
			occupiedd = 1;

			while (table[i - 1][j] != oppositecolor && table[i + 1][j] != oppositecolor && table[i][j + 1] != oppositecolor && table[i][j - 1] != oppositecolor && table[i + 1][j + 1] != oppositecolor&& table[i + 1][j - 1] != oppositecolor&& table[i - 1][j + 1] != oppositecolor&& table[i - 1][j - 1] != oppositecolor) {
				printf("invalid move");
				int character = scanf("%d", &input);
				if (character == 0) {
					printf("Bad input\n");
					while (1) {
						char c = getchar();
						if (c == '\n')
							break;
					}
				}
				j = input % 10;
				i = input / 10;
				occupiedd = 0;
			}
			wrongmove = 1;
		}

		/*checking for validmove with flag=1*/
		/*variables down, up... are for saving the address of the last same color in table*/
		down = i + 2;
		while (down <= 8) {
			if (table[down - 1][j] == oppositecolor) {
				if (table[down][j] == samecolor) {
					flag = 1;
					break;
				}
			}
			else {
				down = 9;
				break;
			}
			down++;
		}
		up = i - 2;
		while (up >= 1) {
			if (table[up + 1][j] == oppositecolor) {
				if (table[up][j] == samecolor) {
					flag = 1;
					break;
				}
			}
			else {
				up = 0;
				break;
			}
			up--;
		}
		right = j + 2;
		while (right <= 8) {
			if (table[i][right - 1] == oppositecolor) {
				if (table[i][right] == samecolor) {
					flag = 1;
					break;
				}
			}
			else {
				right = 9;
				break;
			}
			right++;
		}
		left = j - 2;
		while (left >= 1) {
			if (table[i][left + 1] == oppositecolor) {
				if (table[i][left] == samecolor) {
					flag = 1;
					break;
				}
			}
			else {
				left = 0;
				break;
			}
			left--;
		}
		diagonal_leftup = j - 2;
		diagonal_upleft = i - 2;
		while (diagonal_leftup >= 1 && diagonal_upleft >= 1) {
			if (table[i - 1][j - 1] == oppositecolor) {
				if (table[diagonal_upleft][diagonal_leftup] == samecolor) {
					flag = 1;
					break;
				}
			}
			else {
				diagonal_leftup = 0;
				diagonal_upleft = 0;
				break;
			}
			diagonal_upleft--;
			diagonal_leftup--;
		}
		diagonal_leftdown = j - 2;
		diagonal_downleft = i + 2;
		while (diagonal_leftdown >= 1 && diagonal_downleft <= 8) {
			if (table[i + 1][j - 1] == oppositecolor) {
				if (table[diagonal_downleft][diagonal_leftdown] == samecolor) {
					flag = 1;
					break;
				}
			}
			else {
				diagonal_downleft = 9;
				diagonal_leftdown = 0;
				break;
			}
			diagonal_downleft++;
			diagonal_leftdown--;
		}
		diagonal_rightdown = j + 2;
		diagonal_downright = i + 2;
		while (diagonal_rightdown <= 8 && diagonal_downright <= 8) {
			if (table[i + 1][j + 1] == oppositecolor) {
				if (table[diagonal_downright][diagonal_rightdown] == samecolor) {
					flag = 1;
					break;
				}
			}
			else {
				diagonal_downright = 9;
				diagonal_rightdown = 9;
				break;
			}
			diagonal_downright++;
			diagonal_rightdown++;
		}
		diagonal_rightup = j + 2;
		diagonal_upright = i - 2;
		while (diagonal_rightup <= 8 && diagonal_upright >= 1) {
			if (table[i - 1][j + 1] == oppositecolor) {
				if (table[diagonal_upright][diagonal_rightup] == samecolor) {
					flag = 1;
					break;
				}
			}
			else {
				diagonal_rightup = 9;
				diagonal_upright = 0;
				break;
			}
			diagonal_upright--;
			diagonal_rightup++;
		}
		if (flag != 1)
			printf("invalid move\n");
	}


	table[i][j] = samecolor;

	/*now the address that we've already saved will be used for fliping pieces*/
	if (right != 9 && right != 10) {
		for (right; right >= j; right--) {
			if (table[i][right] == oppositecolor)
				table[i][right] = samecolor;
		}
	}
	if (left != 0 && left != -1) {
		for (left; left <= j; left++) {
			if (table[i][left] == oppositecolor)
				table[i][left] = samecolor;
		}
	}
	if (down != 9 && down != 10) {
		for (down; down >= i; down--) {
			if (table[down][j] == oppositecolor)
				table[down][j] = samecolor;
		}
	}
	if (up != 0 && up != -1) {
		for (up; up <= i; up++) {
			if (table[up][j] == oppositecolor)
				table[up][j] = samecolor;
		}
	}
	if (diagonal_leftup != 0 && diagonal_upleft != 0 && diagonal_leftup != -1 && diagonal_upleft != -1) {
		while (diagonal_upleft <= i && diagonal_leftup <= j) {
			if (table[diagonal_upleft][diagonal_leftup] == oppositecolor) {
				table[diagonal_upleft][diagonal_leftup] = samecolor;
			}
			diagonal_upleft++, diagonal_leftup++;
		}
	}
	if (diagonal_leftdown != 0 && diagonal_downleft != 9 && diagonal_leftdown != -1 && diagonal_downleft != 10) {
		while (diagonal_downleft >= i && diagonal_leftdown <= j) {
			if (table[diagonal_downleft][diagonal_leftdown] == oppositecolor) {
				table[diagonal_downleft][diagonal_leftdown] = samecolor;
			}
			diagonal_downleft--, diagonal_leftdown++;
		}
	}
	if (diagonal_rightdown != 9 && diagonal_downright != 9 && diagonal_rightdown != 10 && diagonal_downright != 10) {
		while (diagonal_downright >= i && diagonal_rightdown >= j) {
			if (table[diagonal_downright][diagonal_rightdown] == oppositecolor) {
				table[diagonal_downright][diagonal_rightdown] = samecolor;
			}
			diagonal_downright--, diagonal_rightdown--;
		}
	}
	if (diagonal_rightup != 9 && diagonal_upright != 0 && diagonal_rightup != 10 && diagonal_upright != -1) {
		while (diagonal_upright <= i && diagonal_rightup >= j) {
			if (table[diagonal_upright][diagonal_rightup] == oppositecolor) {
				table[diagonal_upright][diagonal_rightup] = samecolor;
			}
			diagonal_upright++, diagonal_rightup--;
		}
	}
	print_table(table);
}