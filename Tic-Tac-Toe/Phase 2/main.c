#include <stdio.h>
int player1_game(int player1Num, int player2Num, char room[], int *gameover);
int player2_game(int player2Num, int player1Num, char room[], int *gameover);
int checkXwins(char room[], int *gameover);
int checkOwins(char room[], int *gameover);
int restart(int *play, int play_helper);
void print_board(char room[]);
void print_board(char room[]) {
	/*khane haye barname baraye inke arraye shavad b room taghir karde ast*/
	printf("%c | %c | %c\n", room[0], room[1], room[2]);
	printf("---------\n");
	printf("%c | %c | %c\n", room[3], room[4], room[5]);
	printf("---------\n");
	printf("%c | %c | %c\n", room[6], room[7], room[8]);

}
int player1_game(int player1Num, int player2Num, char room[], int *gameover) {
	player1Num = 0;
	player2Num = 0;
	while (player1Num != 1 && player1Num != 2 && player1Num != 3 && player1Num != 4 && player1Num != 5 && player1Num != 6 && player1Num != 7 && player1Num != 8 && player1Num != 9) {
		printf("player one's turn:\n");
		printf("please choose a number between 1 to 9\n");
		scanf("%d", &player1Num);
	}
	/*check for empty space*/
	while (((room[0] == 'x' || room[0] == 'o') && (player1Num == 1 || player2Num == 1)) || ((room[1] == 'x' || room[1] == 'o') && (player1Num == 2 || player2Num == 2)) || ((room[2] == 'x' || room[2] == 'o') && (player1Num == 3 || player2Num == 3)) || ((room[3] == 'x' || room[3] == 'o') && (player1Num == 4 || player2Num == 4)) || ((room[4] == 'x' || room[4] == 'o') && (player1Num == 5 || player2Num == 5)) || ((room[5] == 'x' || room[5] == 'o') && (player1Num == 6 || player2Num == 6)) || ((room[6] == 'x' || room[6] == 'o') && (player1Num == 7 || player2Num == 7)) || ((room[7] == 'x' || room[7] == 'o') && (player1Num == 8 || player2Num == 8)) || ((room[8] == 'x' || room[8] == 'o') && (player1Num == 9 || player2Num == 9))) {
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
		room[0] = 'x';
		print_board(room);
	}
	if (player1Num == 2) {
		room[1] = 'x';
		print_board(room);
	}
	if (player1Num == 3) {
		room[2] = 'x';
		print_board(room);
	}
	if (player1Num == 4) {
		room[3] = 'x';
		print_board(room);
	}
	if (player1Num == 5) {
		room[4] = 'x';
		print_board(room);
	}
	if (player1Num == 6) {
		room[5] = 'x';
		print_board(room);
	}
	if (player1Num == 7) {
		room[6] = 'x';
		print_board(room);
	}
	if (player1Num == 8) {
		room[7] = 'x';
		print_board(room);
	}
	if (player1Num == 9) {
		room[8] = 'x';
		print_board(room);
	}
	*gameover = *gameover + 1;
	player1Num = 0;


}
int player2_game(int player2Num, int player1Num, char room[], int *gameover) {
	player1Num = 0;
	player2Num = 0;
	while (player2Num != 1 && player2Num != 2 && player2Num != 3 && player2Num != 4 && player2Num != 5 && player2Num != 6 && player2Num != 7 && player2Num != 8 && player2Num != 9) {
		printf("player two's turn:\n");
		printf("please choose a number between 1 to 9\n");
		scanf("%d", &player2Num);
	}
	/*check for empty space*/
	while (((room[0] == 'x' || room[0] == 'o') && (player1Num == 1 || player2Num == 1)) || ((room[1] == 'x' || room[1] == 'o') && (player1Num == 2 || player2Num == 2)) || ((room[2] == 'x' || room[2] == 'o') && (player1Num == 3 || player2Num == 3)) || ((room[3] == 'x' || room[3] == 'o') && (player1Num == 4 || player2Num == 4)) || ((room[4] == 'x' || room[4] == 'o') && (player1Num == 5 || player2Num == 5)) || ((room[5] == 'x' || room[5] == 'o') && (player1Num == 6 || player2Num == 6)) || ((room[6] == 'x' || room[6] == 'o') && (player1Num == 7 || player2Num == 7)) || ((room[7] == 'x' || room[7] == 'o') && (player1Num == 8 || player2Num == 8)) || ((room[8] == 'x' || room[8] == 'o') && (player1Num == 9 || player2Num == 9))) {
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
		room[0] = 'o';
		print_board(room);
	}
	if (player2Num == 2) {
		room[1] = 'o';
		print_board(room);
	}
	if (player2Num == 3) {
		room[2] = 'o';
		print_board(room);
	}
	if (player2Num == 4) {
		room[3] = 'o';
		print_board(room);
	}
	if (player2Num == 5) {
		room[4] = 'o';
		print_board(room);
	}
	if (player2Num == 6) {
		room[5] = 'o';
		print_board(room);
	}
	if (player2Num == 7) {
		room[6] = 'o';
		print_board(room);
	}
	if (player2Num == 8) {
		room[7] = 'o';
		print_board(room);
	}
	if (player2Num == 9) {
		room[8] = 'o';
		print_board(room);
	}
	*gameover = *gameover + 1;
	player2Num = 0;


}
int checkXwins(char room[], int *gameover) {
	if ((room[0] == 'x' && room[1] == 'x' && room[2] == 'x') || (room[3] == 'x' && room[4] == 'x' && room[5] == 'x') || (room[6] == 'x' && room[7] == 'x' && room[8] == 'x') || (room[0] == 'x' && room[3] == 'x' && room[6] == 'x') || (room[1] == 'x' && room[4] == 'x' && room[7] == 'x') || (room[2] == 'x' && room[5] == 'x' && room[8] == 'x') || (room[0] == 'x' && room[4] == 'x' && room[8] == 'x') || (room[2] == 'x' && room[4] == 'x' && room[6] == 'x')) {
		printf("Congratulations !\n");
		printf("Player 1 has won the game !\n");
		*gameover = *gameover + 10;
	}

}
int checkOwins(char room[], int *gameover) {
	/*check for O wins*/
	if ((room[0] == 'o' && room[1] == 'o' && room[2] == 'o') || (room[3] == 'o' && room[4] == 'o' && room[5] == 'o') || (room[6] == 'o' && room[7] == 'o' && room[8] == 'o') || (room[0] == 'o' && room[3] == 'o' && room[6] == 'o') || (room[1] == 'o' && room[4] == 'o' && room[7] == 'o') || (room[2] == 'o' && room[5] == 'o' && room[8] == 'o') || (room[0] == 'o' && room[4] == 'o' && room[8] == 'o') || (room[2] == 'o' && room[4] == 'o' && room[6] == 'o')) {
		printf("Congratulations !\n");
		printf("Player 2 has won the game !\n");
		*gameover = *gameover + 10;
	}

}
int restart ( int *play, int play_helper) {
	/*play_helper komaki baraye play hast k bazi restart shavad ya na*/
	printf("press 1 if you want to start a new game. otherwise press 2\n ");
	scanf("%d", &play_helper);
	while (play_helper != 1 && play_helper != 2) {
		printf("press 1 if you want to start a new game. otherwise press 2\n ");
		scanf("%d", &play_helper);
	}
	if (play_helper == 1)
		*play = 1;
	if (play_helper == 2)
		*play = 2;
}


int main() {
	int play = 1;
	char room[9];
	int player1Num = 0, player2Num = 0;
	int gameover = 0;
	int play_helper = 0;
	while (play == 1) {
		room[0] = '-';
		room[1] = '-';
		room[2] = '-';
		room[3] = '-';
		room[4] = '-';
		room[5] = '-';
		room[6] = '-';
		room[7] = '-';
		room[8] = '-';
		gameover = 0;
		print_board(room);
		while (gameover < 9) {
			player1_game(player1Num, player2Num, room, &gameover);
			checkXwins(room, &gameover);
			if (gameover > 10) {/*X has won the game so the loop must break*/
				break;
			}
			if (gameover == 9) {
				printf("TIE!!! The game is over\n");
				printf("No one has won the game\n");
				break;
			}
			player2_game(player2Num, player1Num, room, &gameover);
			checkOwins(room, &gameover);
			if (gameover > 10) {/*O has won the game so the loop must break*/
				break;
			}
		}
		restart(&play, play_helper);

	}

}









