#include<stdio.h>
#include<string.h>
#include"funcs.h"
#include<stdlib.h>
void readfromfile(user*head) {
	FILE* myfile = fopen("ibank.txt", "r");
	char username[20];
	int i = 0;
	if (myfile == NULL) {
		printf("cannot open the file");
		return;
	}
	for (;;) {
		if (fscanf(myfile, "%s", username) == EOF)
			break;
		else {
			user*newuser = (user*)malloc(sizeof(user));
			newuser->next = head->next;
			newuser->next = NULL;
			head->next = newuser;
			strcpy(head->next->username, username);
			fscanf(myfile, " %s &s %ld %lf %d", head->next->userpass, head->next->userphonenum, &(head->next->userid), &(head->next->accountbalance), &(head->next->numsoftransaction));
			if (head->next->numsoftransaction>=0) {
				head->next->firstransaction= (transaction*)malloc(sizeof(transaction));
				head->next->firstransaction->next = NULL;
			}
			while (i < head->next->numsoftransaction) {
				newtransaction(head->next->firstransaction);
				fscanf(myfile, "%s %lf", head->next->firstransaction->next->transaction_type, &(head->next->firstransaction->next->amount));
				i++;
			}
		}
	}
	fclose(myfile);
}

void writetofile(user*head) {
	FILE *myfile = fopen("ibank.txt","w");
	user* current = head->next;
	transaction*trans;
	int i;
	if (myfile == NULL) {
		printf("cant open the file\n");
		return;
	}
	while (current != NULL) {
		fprintf(myfile, "%s %s %s %ld %lf %d", current->username, current->userpass, current->userphonenum, current->userid, current->accountbalance, current->numsoftransaction);
		if (current->numsoftransaction > 0) {
			trans = current->firstransaction->next;
			for (i = 0;i < current->numsoftransaction;i++) {
				while (trans != NULL) {
					fprintf(myfile, "%s %lf", trans->transaction_type, trans->amount);
					trans = trans->next;
				}
			}
		}
		fprintf(myfile, "\n");
		current = current->next;
	}
	//deletenode(head);
}
void deletenode(user*head) {
	user*current = head->next;
	user*delete1;
	user*delete2;
	user*delete3;
	while (current != NULL) {
		delete1 = current->next;
		if (current->numsoftransaction > 0) {
			delete2 = current->firstransaction;
			while (delete2 != NULL) {
				delete3 = delete2->next;
				free(delete2);
				delete2 = delete3;

			}
		}
		free(current);
		current = delete1;
	}
}



/*making admin as head of our user node*/
user*headd() {
	user*head = (user*)malloc(sizeof(user));
	/*allocates memory*/
	char username[20] = "admin";
	char userphonenum[20] = "00000000000";
	char userpass[20] = "123";
	strcpy(head->username, username);
	strcpy(head->userphonenum, userphonenum);
	strcpy(head->userpass, userpass);
	head->userid = 0;
	head->accountbalance = 0.0000;
	head->firstransaction = NULL;
	head->numsoftransaction = 0;
	head->next = NULL;
	return head;
}

void newtransaction(transaction* current) {
	transaction* newtransaction = (transaction*)malloc(sizeof(transaction));
	newtransaction->next = NULL;
	newtransaction->next = current->next;
	current->next = newtransaction;
}

void addNewcontact(user*head, int *admin, int *userId) /* add new user function*/
{
	user*current = head->next;
	user*newuser;
	char username[20], userpass[20], userphonenum[20];
	scanf(" %s %s %s", username, userpass, userphonenum);
	getchar();
	while (current != NULL) {
		/* searching loop through records*/
		if (strcmp(current->username, username) == 0) {
			printf("this username already exist\n");
			break;
		}
		if (strcmp(userphonenum, current->userphonenum) == 0) {
			printf("this phonenumber already exist\n");
			break;
		}
		current = current->next;
	}
	if (current == NULL) {
		newuser = (user*)malloc(sizeof(user)); /*allocates memory for new user structure*/
		newuser->next = head->next;/*adding new user to the begining of linked list*/
		head->next = newuser;
		strcpy(newuser->username, username);
		strcpy(newuser->userphonenum, userphonenum);
		strcpy(newuser->userpass, userpass);
		(*userId)++;/*userId is used to give unique account numbers*/
		newuser->userid = *userId;
		newuser->accountbalance = 0.0000000;
		newuser->numsoftransaction = 0;
		printf("user added\n");
	}
}

void login(user*head, int *admin, char name[20]) {
	user*current = head->next;
	int wrongpass;
	printf("login ");
	char input[20];
	char pass[20];
	scanf("%s %s", input, pass);
	getchar();
	if (strcmp(input, "admin") == 0) {
		if (strcmp(pass, "123") == 0) {
			printf("admin succestfully logged in! \n");
			*admin = 1;
		}
		else {
			printf("worng password for admin\n");
			wrongpass = 1;
		}
	}
	else {
		while (current != NULL) {
			if (strcmp(current->username, input) == 0) {
				if (strcmp(current->userpass, pass) == 0) {
					printf("user succestfully logged in!\n");
					*admin = 2;
					strcpy(name, input);
				}
				else {
					printf("wrong password for %s\n", input);
					wrongpass = 1;
				}
			}
			/*searching for username*/
			current = current->next;
		}

	}
	if (*admin == 0 && wrongpass != 1) {
		printf("username is incorrect\n");
	}

}
void deletcontact(user*head) {
	char deletinguser[20];
	char*deleteuser = deletinguser;
	user* previousa = head;/*previousa is for deleting a node. actually previousa jumps from a node so it will be deleted*/
	user*current = head->next;
	transaction*currenttrans;
	scanf(" %s", deletinguser);
	if (current == NULL)
	{
		printf("There are no contacts to delete!\n");
		return;
	}
	while (current != NULL)
	{
		if (strcmp(current->username,deletinguser)==0)
		{
			if (current->next == NULL) 
				previousa->next = NULL;/*if current user is the last guy, this is how we delete him*/
			else
				previousa->next = current->next;/*deleting current user*/
			if (current->numsoftransaction > 0) {/*deleting his transactions too*/
				while (current->firstransaction->next != NULL) {
					currenttrans = current->firstransaction->next->next;
					free(current->firstransaction->next);
					current->firstransaction->next = currenttrans;
				}
				free(current->firstransaction);/*frees memory*/

			}
			free(current); /*frees memory <deletes>*/
			printf("user deleted\n");
			return;
		}
		else
		{
			previousa = current;
			current = current->next;
		}
	}
	printf("contact %s not found!\n", deleteuser);

}

void deposit(user*head) {
	transaction*headtrans = (transaction*)malloc(sizeof(transaction));
	headtrans->next = NULL;
	user*current = head->next;
	char username[20];
	double amount;
	scanf(" %s %lf", username, &amount);
	while (current != NULL) {
		if (strcmp(username, current->username) == 0) {
			if (current->numsoftransaction == 0) { 
				current->firstransaction = (transaction*)malloc(sizeof(transaction));
				current->firstransaction->next = NULL;
			}

			newtransaction(current->firstransaction);
			current->numsoftransaction++;
			/*char what[5];
			itoa(current->numsoftransaction, what, 10);
			strcpy(current->firstransaction->next->transaction_type,what);*/
			strcpy(current->firstransaction->next->transaction_type, "deposit");
			current->accountbalance += amount;
			current->firstransaction->next->amount = amount;
			printf("deposit done\n");
			return;
		}
		current = current->next;
	}
	printf("no user found\n");
}

void withdraw(user*head) {
	user*current = head->next;
	char username[20];
	double amount;
	scanf(" %s %lf", username, &amount);
	//getchar();
	while (current != NULL) {
		if (strcmp(username, current->username) == 0) {
			if (current->accountbalance >= amount) {
				if (current->numsoftransaction == 0) { 
					current->firstransaction = (transaction*)malloc(sizeof(transaction));
					current->firstransaction->next = NULL;
				}

				newtransaction(current->firstransaction);
				strcpy(current->firstransaction->next->transaction_type, "withdraw");
				current->numsoftransaction++;
				current->accountbalance -= amount;
				current->firstransaction->next->amount = amount;
				printf("withdraw is done\n");
				return;
			}
			printf("not enough money to withdraw\n");
			return;
		}
		current = current->next;
	}
	printf("no user found\n");
}

void viewadmin(user*head) {
	user*current = head->next;
	transaction* current2;
	char username[20];
	scanf(" %s", username);
	getchar();
	while (current != NULL) {
		if (strcmp(current->username, username) == 0) {
			printf("User ID:%ld User Name:%s User PhoneNumber:%s Balance:%lf\n", current->userid, current->username, current->userphonenum, current->accountbalance);

			if (current->numsoftransaction >0) {
				current2 = current->firstransaction->next;
				while (current2 != NULL) {
					printf("%s : %lf\n", current2->transaction_type, current2->amount);
					current2 = current2->next;
				}
			}
			return;
		}
		current = current->next;
	}
	printf("no user found\n");
}
void viewuser(user*head, char name[20]) {
	user*current = head->next;
	transaction* current2;
	//getchar();
	while (current != NULL) {
		if (strcmp(current->username, name) == 0) {
			printf("User ID:%ld User Name:%s User PhoneNumber:%s Balance:%lf\n", current->userid, current->username, current->userphonenum, current->accountbalance);
			if (current->numsoftransaction > 0) {
				current2 = current->firstransaction->next;
				while (current2 != NULL) {
					printf("%s : %lf\n", current2->transaction_type, current2->amount);
					current2 = current2->next;
				}
			}
			break;
		}
		current = current->next;
	}
}

void transfer(user*head,char name[20]) {
	user*current = head->next;
	user*current_IN = head->next;
	char username_IN[20];
	double amount;
	int finduser=0;
	scanf(" %s %lf", username_IN, &amount);
	while (current_IN != NULL) {
		if (strcmp(current_IN->username, username_IN) == 0) {
			finduser = 1;
			break;
		}
		current_IN = current_IN->next;
	}

	while (current != NULL) {
		if (strcmp(current->username, name) == 0) {
			if (current->accountbalance <= amount) {
				printf("Not enough money to transfer\n");
				finduser = 0;
				return;
			}
			break;
		}
		current = current->next;
	}

	if (finduser == 1) {/*transfer in codes*/
		if (current_IN->numsoftransaction == 0) {
			current_IN->firstransaction = (transaction*)malloc(sizeof(transaction));
			current_IN->firstransaction->next = NULL;
		}

		newtransaction(current_IN->firstransaction);
		current_IN->accountbalance += amount;
		current_IN->firstransaction->next->amount = amount;
		strcpy(current_IN->firstransaction->next->transaction_type, "transferIN");
		current_IN->numsoftransaction++;

		if (current->numsoftransaction == 0) {/*transfer out codes*/
			current->firstransaction = (transaction*)malloc(sizeof(transaction));
			current->firstransaction->next = NULL;
		}
		newtransaction(current->firstransaction);
		current->accountbalance -= amount;
		current->firstransaction->next->amount = amount;
		strcpy(current->firstransaction->next->transaction_type, "transferOUT");
		current->numsoftransaction++;
		printf("transfer is done\n");
	}
	else
		printf("user for transferIN not found\n");
}