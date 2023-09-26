#include <stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct transaction transaction;
typedef struct usersecureinf user;
struct usersecureinf {
	char username[20];
	char userpass[20];
	char userphonenum[20];
	int userid;
	float accountbalance;
	int numsoftransaction;
	user*next;
	transaction*firstransaction;

};

struct transaction {
	char transaction_type[20];
	double amount;
	transaction* next;
};
void addNewcontact(user*head, int *admin, int *userId);
void login(user*head, int *admin, char name[20]);
user*headd();
void viewadmin(user*head);
void viewuser(user*head, char name[20]);
void newtransaction(transaction* current);
//transaction* headTransaction();
void deposit(user*head);
void withdraw(user*head);
void transfer(user*head, char name[20]);
void deletcontact(user*head);
void readfromfile(user*head);
void writetofile(user*head);
void deletenode(user*head);





