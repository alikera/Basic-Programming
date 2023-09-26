#pragma once
void score(char table[9][9], int* blackscore, int *whitescore);
void lock(char table[9][9], int *counter);
void playgame(char table[9][9], int *counter, int whitescore, int blackscore);
void drawboard(char table[9][9],int *counter, int whitescore, int blackscore);
void winner(int blackscore, int whitescore, int *finish);
void user_input(char table[9][9], int *counter, int *row, int *col, int whitescore, int blackscore);