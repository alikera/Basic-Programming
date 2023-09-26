#include <stdio.h>
#include "Functions.h"
#include"graphics.h"
void user_input(char table[9][9], int *counter, int *row, int *col, int whitescore, int blackscore) {

	char move = 'z', enter = ' ';
	int left = 35, up = 35, right = 55, down = 55;
	setcolor(RED);
	rectangle(left, up, right, down);
	setfillstyle(SOLID_FILL, RED);
	floodfill(40, 40, RED);
	int trashnumber = 0, badinput = 0;
	while (move != ' ') {
		if (badinput == 0) {
			scanf("%c%c", &move, &enter);
			if (move == '\n' || enter != '\n') {
				badinput = 1;
			}
			while (enter != '\n') {
				scanf("%c", &enter);
				if (enter != '\n')
					trashnumber++;
			}
			if (trashnumber > 0)
				badinput = 1;
			trashnumber = 0;
			if (move != 'w' && move != 's'&& move != 'a' && move != 'd' && move != ' ')
				badinput = 1;
		}
		while (badinput == 1) {
			badinput = 0;
			setcolor(RED);
			rectangle(left, up, right, down);
			setfillstyle(SOLID_FILL, RED);
			floodfill(left + 10, down - 10, RED);
			//setbkcolor(RED);
			setcolor(RED);
			setbkcolor(BLACK);
			settextstyle(1, 0, 500);
			outtextxy(750, 80, "INVALID INPUT!");
			scanf("%c%c", &move, &enter);
			if (move == '\n' || enter != '\n') {
				badinput = 1;
			}
			while (enter != '\n') {
				scanf("%c", &enter);
				if (enter != '\n')
					trashnumber++;
			}
			if (trashnumber > 0)
				badinput = 1;
			trashnumber = 0;
		}
		badinput = 1;
		if (move == 'w' && up != 35) {
			up -= 90;
			down -= 90;
			badinput = 0;
		}
		else if (move == 's' && down != 685) {
			up += 90;
			down += 90;
			badinput = 0;
		}
		else if (move == 'a' && left != 35) {
			left -= 90;
			right -= 90;
			badinput = 0;
		}
		else if (move == 'd' && right != 685) {
			left += 90;
			right += 90;
			badinput = 0;
		}
		clearviewport();
		drawboard(table, counter, whitescore, blackscore);
		if (badinput == 0) {
			setcolor(RED);
			rectangle(left, up, right, down);
			setfillstyle(SOLID_FILL, RED);
			floodfill(left + 5, up + 5, RED);
		}

	}
	*col = (left - 35) / 90 + 1;
	*row = (up - 35) / 90 + 1;
}
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
}
void lock(char table[9][9], int *counter) {
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
void playgame(char table[9][9], int *counter, int whitescore, int blackscore) {
	int row, col;
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
	while (flag != 1) {
		user_input(table, counter, &row, &col,whitescore,blackscore);
		j = row;
		i = col;
		if (table[i][j] != '.') {
			flag = 0;
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
	if (flag != 1) {
		setcolor(RED);
		setbkcolor(BLACK);
		settextstyle(1,0, 500);
		outtextxy(770, 80, "INVALID INPUT!");
	}
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
}

void drawboard(char table[9][9],int *counter,int whitescore, int blackscore) {
	clearviewport();
	setbkcolor(BLACK);
	setcolor(GREEN);
	rectangle(0, 0, 720, 720);
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(50, 50, GREEN);
	setcolor(DARKGRAY);
	for (int i = 0; i < 8; i++) {
		line(0, 90*i, 720, 90*i);
		line(90*i, 0, 90*i, 720);
	}
	line(720, 0, 720, 720);
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			if (table[i][j] == 'w') {
				setcolor(WHITE);
				circle((i-1) * 90 + 45, (j-1) * 90 + 45, 35);
				setfillstyle(SOLID_FILL, WHITE);
				floodfill((i-1) * 90 + 46, (j-1) * 90 + 46, WHITE);
			}
			if (table[i][j] == 'b') {
				setcolor(BLACK);
				circle((i-1) * 90 + 45, (j-1) * 90 + 45, 35);
				setfillstyle(SOLID_FILL, BLACK);
				floodfill((i-1) * 90 + 46, (j-1) * 90 + 46, BLACK);
			}
		}
	}
	setcolor(GREEN);
	setfillstyle(WIDE_DOT_FILL, GREEN);
	floodfill(800, 500, DARKGRAY);
	setcolor(GREEN);
	settextstyle(1, 0, 500);
	if (*counter % 2 == 1)
		outtextxy(750, 50, "BLACK Player's Turn");
	else
		outtextxy(750, 50, "WHITE Player's Turn");
	char blackscoree[20];
	char whitescoree[20];
	setcolor(DARKGRAY);
	circle(755, 200, 30);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(755, 200, DARKGRAY);
	sprintf(blackscoree, "%d", blackscore);
	setcolor(RED);
	settextstyle(1, 0, 110);
	outtextxy(755, 200, blackscoree);
	setcolor(WHITE);
	circle(755, 260, 30);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(755, 260, WHITE);
	sprintf(whitescoree, "%d", whitescore);
	setcolor(RED);
	setbkcolor(WHITE);
	settextstyle(1, 0, 110);
	outtextxy(755, 260, whitescoree);
}
void winner(int blackscore, int whitescore, int *finish) {
	initwindow(600, 400, "WINNER");
	rectangle(0, 0, 600, 400);
	setfillstyle(SOLID_FILL, LIGHTCYAN);
	floodfill(1, 1, WHITE);

	if (blackscore > whitescore) {
		settextstyle(5, 0, 4);
		setbkcolor(LIGHTCYAN);
		setcolor(RED);
		outtextxy(20, 30, "CONGRATULATIONS!!");
		settextstyle(2, 0, 6);
		setcolor(BLACK);
		outtextxy(20, 80, "BLACK PLAYER HAS WON THE GAME");

	}

	else if (whitescore > blackscore) {
		settextstyle(5, 0, 4);
		setbkcolor(LIGHTCYAN);
		setcolor(RED);
		outtextxy(20, 30, "CONGRATULATIONS!!");
		settextstyle(2, 0, 6);
		setcolor(BLACK);
		outtextxy(20, 80, "WHITE PLAYER HAS WON THE GAME");
	}
	else {
		settextstyle(2, 0, 8);
		setbkcolor(LIGHTCYAN);
		setcolor(RED);
		outtextxy(20, 80, "TIE TIE TIE ");
	}
	char bscore[20], wscore[20];
	setcolor(BLACK);
	settextstyle(3, 0, 3);
	sprintf(bscore, "Black = %d", blackscore);
	outtextxy(40, 120, bscore);
	setcolor(WHITE);
	sprintf(wscore, "White = %d", whitescore);
	outtextxy(40, 160, wscore);
	setcolor(BLACK);
	outtextxy(20, 200, "if you want to play again press 1");
	outtextxy(20, 230, "otherwise press 2");
	int end;
	scanf("%d", &end);
	(*finish) = end;
}
