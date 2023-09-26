#pragma once
void score(char table[9][9], int* blackscore, int *whitescore);
void print_table(char table[9][9]);
int lock(char table[9][9], int *counter);
int playgame(char table[9][9], int *counter);