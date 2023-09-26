#include<stdio.h>
#include<string.h>
#include"funcs.h"
#include<stdlib.h>
int main() {
	int admin = 0, userId = 1008000, exit = 0;
	user*head = headd();
	FILE*myfile = fopen("ibank.txt", "a");
	fclose(myfile);
	readfromfile(head);
	char command[20];
	char name[20];
	int flag = 0;
	while (exit == 0) {/*this loop continues until exit commnad*/
		/*admin commands*/
		while (admin == 0)
			login(head, &admin, name);
		while (admin == 1) {
			scanf("%s", command);
			if (strcmp(command, "add_user") == 0) 
				addNewcontact(head, &admin, &userId);
			else if (strcmp(command, "logout") == 0) 
				admin = 0;
			else if (strcmp(command, "exit") == 0) {
				exit = 1;
				flag = 1;
				break;
			}
			else if (strcmp(command, "view") == 0) 
				viewadmin(head);
			else if (strcmp(command, "deposit") == 0) 
				deposit(head);
			else if (strcmp(command, "withdraw") == 0)
				withdraw(head);
			else if (strcmp(command, "delete") == 0) 
				deletcontact(head);
			else
				printf("out of command");
		}
		if (flag == 1)
			break;
		/*user commands*/
		while (admin == 2) {
			scanf("%s", command);
			if (strcmp(command, "logout") == 0)
				admin = 0;
			else if (strcmp(command, "exit") == 0) {
				exit = 1;
				flag = 1;
				break;
			}
			else if (strcmp(command, "view") == 0)
				viewuser(head, name);
			else if (strcmp(command, "transfer") == 0) 
				transfer(head, name);
			else
				printf("out of command\n");
		}
		if (flag == 1)
			break;
	}
	writetofile(head);
}













