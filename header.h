#ifndef HEADER_FILE
#define HEADER_FILE
#include<stdbool.h>

struct Node 
{ 
  char data[30];
  struct Node *next; 
}; 
struct Node2 {
  char Nom_token[30];
  char Type_token[30];
  char Type_of[30];
  struct Node2 *next;
};
struct Node2* head2;
struct Node* head;
struct Node* constantes;
struct Node* tout;
void append(struct Node** head_ref,char new_data[]);
void printList(struct Node *node);
bool isNumber(char *s);
void verifictaion_function(char *verification);
void analyse();
void append_token_Nom(struct Node2** head_ref, char new_data[],char new_data2[]);
void determiner(struct Node2* node);
void printSem(struct Node2* node);
void rule_5(struct Node2* node);
void rule_4(struct Node2* node);
void stocker_const(struct Node2* node);
void rule_3(struct Node2* node);
void rule_2(struct Node2* node);
void stocker_tout(struct Node2* node);
#endif