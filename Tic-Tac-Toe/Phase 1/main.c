#include <stdio.h>
int main() {
	int gameover = 0;
	int play = 1;
	while (play == 1) {
		char corner1 = '-';
		char up = '-';
		char corner2 = '-';
		char left = '-';
		char middle = '-';
		char right = '-';
		char corner3 = '-';
		char down = '-';
		char corner4 = '-';
		int player1Num, player2Num;
		int gameover = 0;
		printf("%c | %c | %c\n", corner1, up, corner2);
		printf("---------\n");
		printf("%c | %c | %c\n", left, middle, right);
		printf("---------\n");
		printf("%c | %c | %c\n", corner3, down, corner4);
		while (gameover < 9) {
			player1Num = 0;
			player2Num = 0;
			/*check for number out of range 1to9*/
			while (player1Num != 1 && player1Num != 2 && player1Num != 3 && player1Num != 4 && player1Num != 5 && player1Num != 6 && player1Num != 7 && player1Num != 8 && player1Num != 9) {
				printf("player one's turn:\n");
				printf("please choose a number between 1 to 9\n");
				scanf("%d", &player1Num);
			}
			/*check for empty space*/
			while (((corner1 == 'x' || corner1 == 'o') && (player1Num == 1 || player2Num == 1)) || ((up == 'x' || up == 'o') && (player1Num == 2 || player2Num == 2)) || ((corner2 == 'x' || corner2 == 'o') && (player1Num == 3 || player2Num == 3)) || ((left == 'x' || left == 'o') && (player1Num == 4 || player2Num == 4)) || ((middle == 'x' || middle == 'o') && (player1Num == 5 || player2Num == 5)) || ((right == 'x' || right == 'o') && (player1Num == 6 || player2Num == 6)) || ((corner3 == 'x' || corner3 == 'o') && (player1Num == 7 || player2Num == 7)) || ((down == 'x' || down == 'o') && (player1Num == 8 || player2Num == 8)) || ((corner4 == 'x' || corner4 == 'o') && (player1Num == 9 || player2Num == 9))) {
				player1Num = 0;
				printf("this place is occupied\n");
				printf("please carefully choose a number between 1 to 9\n");
				scanf("%d", &player1Num);
				player2Num = 0;
				while (player1Num != 1 && player1Num != 2 && player1Num != 3 && player1Num != 4 && player1Num != 5 && player1Num != 6 && player1Num != 7 && player1Num != 8 && player1Num != 9) {
					printf("please carefully choose a number between 1 to 9\n");
					scanf("%d", &player1Num);
				}
			}
			if (player1Num == 1) {
				corner1 = 'x';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			if (player1Num == 2) {
				up = 'x';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			if (player1Num == 3) {
				corner2 = 'x';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			if (player1Num == 4) {
				left = 'x';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			if (player1Num == 5) {
				middle = 'x';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			if (player1Num == 6) {
				right = 'x';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			if (player1Num == 7) {
				corner3 = 'x';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			if (player1Num == 8) {
				down = 'x';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			if (player1Num == 9) {
				corner4 = 'x';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			gameover = gameover + 1;
			/*check for X wins*/
			if ((corner1 == 'x' && up == 'x' && corner2 == 'x') || (left == 'x' && middle == 'x' && right == 'x') || (corner3 == 'x' && down == 'x' && corner4 == 'x') || (corner1 == 'x' && left == 'x' && corner3 == 'x') || (up == 'x' && middle == 'x' && down == 'x') || (corner2 == 'x' && right == 'x' && corner4 == 'x') || (corner1 == 'x' && middle == 'x' && corner4 == 'x') || (corner2 == 'x' && middle == 'x' && corner3 == 'x')) {
				printf("Congratulations !\n");
				printf("Player 1 has won the game !\n");
				gameover = gameover + 10;
				break;
			}
			if (gameover == 9) {
				printf("The game is over\n");
				printf("No one has won the game\n");
				break;
			}
			player1Num = 0;
			player2Num = 0;
			/*check for number out of range 1to9*/
			while (player2Num != 1 && player2Num != 2 && player2Num != 3 && player2Num != 4 && player2Num != 5 && player2Num != 6 && player2Num != 7 && player2Num != 8 && player2Num != 9) {
				printf("player two's turn:\n");
				printf("please choose a number between 1 to 9\n");
				scanf("%d", &player2Num);
			}
			/*check for empty space*/
			while (((corner1 == 'x' || corner1 == 'o') && (player1Num == 1 || player2Num == 1)) || ((up == 'x' || up == 'o') && (player1Num == 2 || player2Num == 2)) || ((corner2 == 'x' || corner2 == 'o') && (player1Num == 3 || player2Num == 3)) || ((left == 'x' || left == 'o') && (player1Num == 4 || player2Num == 4)) || ((middle == 'x' || middle == 'o') && (player1Num == 5 || player2Num == 5)) || ((right == 'x' || right == 'o') && (player1Num == 6 || player2Num == 6)) || ((corner3 == 'x' || corner3 == 'o') && (player1Num == 7 || player2Num == 7)) || ((down == 'x' || down == 'o') && (player1Num == 8 || player2Num == 8)) || ((corner4 == 'x' || corner4 == 'o') && (player1Num == 9 || player2Num == 9))) {
				player2Num = 0;
				printf("this place is occupied\n");
				printf("please carefully choose a number between 1 to 9\n");
				scanf("%d", &player2Num);
				player1Num = 0;
				while (player2Num != 1 && player2Num != 2 && player2Num != 3 && player2Num != 4 && player2Num != 5 && player2Num != 6 && player2Num != 7 && player2Num != 8 && player2Num != 9) {
					printf("please carefully choose a number between 1 to 9\n");
					scanf("%d", &player2Num);
				}

			}
			if (player2Num == 1) {
				corner1 = 'o';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			if (player2Num == 2) {
				up = 'o';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			if (player2Num == 3) {
				corner2 = 'o';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			if (player2Num == 4) {
				left = 'o';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			if (player2Num == 5) {
				middle = 'o';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			if (player2Num == 6) {
				right = 'o';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			if (player2Num == 7) {
				corner3 = 'o';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			if (player2Num == 8) {
				down = 'o';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			if (player2Num == 9) {
				corner4 = 'o';
				printf("%c | %c | %c\n", corner1, up, corner2);
				printf("---------\n");
				printf("%c | %c | %c\n", left, middle, right);
				printf("---------\n");
				printf("%c | %c | %c\n", corner3, down, corner4);
			}
			gameover = gameover + 1;
			/*check for O wins*/
			if ((corner1 == 'o' && up == 'o' && corner2 == 'o') || (left == 'o' && middle == 'o' && right == 'o') || (corner3 == 'o' && down == 'o' && corner4 == 'o') || (corner1 == 'o' && left == 'o' && corner3 == 'o') || (up == 'o' && middle == 'o' && down == 'o') || (corner2 == 'o' && right == 'o' && corner4 == 'o') || (corner1 == 'o' && middle == 'o' && corner4 == 'o') || (corner2 == 'o' && middle == 'o' && corner3 == 'o')) {
				printf("Congratulations !\n");
				printf("Player 2 has won the game !\n");
				gameover = gameover + 10;
			}
		}
		printf("press 1 if you want to start a new game. otherwise press 2\n ");
		scanf("%d", &play);
		while (play != 1 && play != 2) {
			printf("press 1 if you want to start a new game. otherwise press 2\n ");
			scanf("%d", &play);
		}
	}

}










