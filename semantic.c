#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> 
#include <stdbool.h>
#include"header.h"

void append(struct Node** head_ref,char new_data[]) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    struct Node *last = *head_ref;
    strcpy(new_node->data,new_data); 
    new_node->next = NULL; 
  
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    }   
    while (last->next != NULL) 
        last = last->next; 
    last->next = new_node; 
    return;     

}
void printList(struct Node *node) 
{ 
  while (node != NULL) 
  { 
     printf("%s\n", node->data); 
     node = node->next; 
  } 
}
bool isNumber(char *s)
{
    for (int i = 0; i < strlen(s); i++){
        if (isdigit(s[i]) == 0){
            return false;
    		}
}
    return true;
}
void verifictaion_function(char *verification){
if(strcmp(verification,"program")==0){
		verification[0]='\0';
            strcpy(verification,"PROGRAM_TOKEN");
}
else if(strcmp(verification,"=")==0){
		verification[0]='\0';
             strcpy(verification, "EG_TOKEN");
 }
 else if(strcmp(verification,"const")==0){
 		verification[0]='\0';
             strcpy(verification, "CONST_TOKEN");
 }
 else if(strcmp(verification,"var")==0){
 	verification[0]='\0';
              strcpy(verification, "VAR_TOKEN");

 }
 else if(strcmp(verification,"Begin")==0){verification[0]='\0';
              strcpy(verification, "BEGIN_TOKEN");

}

 else if(strcmp(verification,"end")==0){verification[0]='\0';
            strcpy(verification,"END_TOKEN");

 }
 else if (strcmp(verification,"if")==0){verification[0]='\0';
             strcpy(verification, "IF_TOKEN");

   }

 else if(strcmp(verification,"then")==0){verification[0]='\0';
              strcpy(verification,"THEN_TOKEN");

  }

 else if(strcmp(verification,"while")==0){verification[0]='\0';
             strcpy(verification, "WHILE_TOKEN");

   }

 else if(strcmp(verification,"Do")==0){verification[0]='\0';
              strcpy(verification,"DO_TOKEN");

   }

 else if(strcmp(verification,"read")==0){verification[0]='\0';
              strcpy(verification,"READ_TOKEN");

   }

 else if (strcmp(verification,"write")==0){verification[0]='\0';
             strcpy(verification,"WRTIE_TOKEN");


   }
 else if (strcmp(verification,";")==0){verification[0]='\0';
              strcpy(verification, "PV_TOKEN");

     }

 else if(strcmp(verification,".")==0){verification[0]='\0';
              strcpy(verification,"PT_TOKEN");

     }

 else if(strcmp(verification,"+")==0){verification[0]='\0';
              strcpy(verification,"PLUS_TOKEN");

             }
 else if(strcmp(verification,"-")==0){verification[0]='\0';
              strcpy(verification, "MOINS_TOKEN");

             }
 else if(strcmp(verification,"*")==0){verification[0]='\0';
              strcpy(verification,"MULT_TOKEN");

             }
 else if(strcmp(verification,"/")==0){verification[0]='\0';
            strcpy(verification,"DIV_TOKEN");

             }
 else if(strcmp(verification,",")==0){verification[0]='\0';
             strcpy(verification,"VIR_TOKEN");
             }
 else if(strcmp(verification,":=")==0){verification[0]='\0';
             strcpy(verification,"AFF_TOKEN");

             }
  else if(strcmp(verification,"program")==0){verification[0]='\0';
              strcpy(verification, "PROGRAM_TOKEN");

             }
 else if(strcmp(verification,"read")==0){verification[0]='\0';
              strcpy(verification,"READ_TOKEN");

             }
 else if(strcmp(verification,"<")==0){verification[0]='\0';
              strcpy(verification, "INF_TOKEN");
 }
 else if(strcmp(verification,"<=")==0){verification[0]='\0';
              strcpy(verification, "INFEG_TOKEN");
             }
 else if(strcmp(verification,">=")==0){verification[0]='\0';
              strcpy(verification, "SUPEG_TOKEN");

             }
 else if(strcmp(verification,">")==0){verification[0]='\0';
             strcpy(verification, "SUP_TOKEN");

             }
 else if(strcmp(verification,"<>")==0){verification[0]='\0';
              strcpy(verification, "DIFF_TOKEN");

 }
 else if(strcmp(verification,"(") ==0){verification[0]='\0';
              strcpy(verification, "PO_TOKEN");

             }
 else if(strcmp(verification,")")==0){verification[0]='\0';
              strcpy(verification,"PF_TOKEN");

             }
 else if(strcmp(verification,"EOF")==0){verification[0]='\0';
             strcpy(verification,"FIN_TOKEN");
 }
 else if(strcmp(verification,"")==0){verification[0]='\0';
             strcpy(verification, "Hello");
 }
 else {
     if(isNumber(verification)){verification[0]='\0';
       strcpy(verification,  "NUM_TOKEN");
     }
     else{verification[0]='\0';
       strcpy(verification, "ID_TOKEN");
     }
}

}

void append_token_Nom(struct Node2** head_ref, char new_data[],char new_data2[]){
  struct Node2* new_node = (struct Node2*) malloc(sizeof(struct Node2)); 
    struct Node2 *last = *head_ref;
    strcpy(new_node->Nom_token,new_data); 
    strcpy(new_node->Type_token,new_data2);
    new_node->next = NULL; 
  
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    }   
    while (last->next != NULL) 
        last = last->next; 
    last->next = new_node; 
    return;     
}

void printSem(struct Node2* node){
  while(node !=NULL){
    printf("%s ---> %s --> %s\n",node->Nom_token,node->Type_token,node->Type_of);
    node = node->next; 
  }
}
void determiner(struct Node2* node){
  int a=0,b=0,c=0,d=0;
  while(node !=NULL){
    if(strcmp(node->Type_token,"PROGRAM_TOKEN")==0){
      a=1;
    }
    if(strcmp(node->Type_token,"CONST_TOKEN")==0){
      b=1;
    }
    if(strcmp(node->Type_token,"VAR_TOKEN")==0){
      c=1;
    }
    if(strcmp(node->Type_token,"BEGIN_TOKEN")==0){
      d=1;
    }
    if(strcmp(node->Type_token,"ID_TOKEN")==0){
      if(a==1 && b==0 && c==0){
        strcpy(node->Type_of,"PROGRAM_TOKEN");
      }
      if(a==1 && b==1 && c==0){
        strcpy(node->Type_of,"CONST_TOKEN");
      }
      if(a==1 && b==1 && c==1){
        strcpy(node->Type_of,"VAR_TOKEN");
      }
      if(a==1 && b==1 && c==1 && d==1){
        strcpy(node->Type_of,"BEGIN_TOKEN");
      }
    }

node = node->next; 
  }
}
void rule_5(struct Node2* node){
  char var[30];
   while(node!=NULL){
       if(strcmp(node->Type_of,"PROGRAM_TOKEN")==0){
         strcpy(var,node->Nom_token);
          node = node->next; 
       }
       if(strcmp(node->Nom_token,var)==0){
         printf("ERREUR :PROGRAM NAME %s CANT BE REPEATED\n",var);
       }
      node = node->next;
   }
}
void stocker_const(struct Node2* node){
  while(node!=NULL){
    if(strcmp(node->Type_of,"CONST_TOKEN")==0){
      append(&constantes,node->Nom_token);
    }
    node  = node->next; 
  }
}
void rule_4(struct Node2* node){
  while(node!=NULL){
    if( strcmp(node->Type_of,"BEGIN_TOKEN")==0 ){
      struct Node* reset = constantes;
         while(reset!=NULL){
             if(strcmp(reset->data,node->Nom_token)==0){
                node = node->next;
                if(strcmp(node->Type_token,"NUM_TOKEN")==0){
                  printf("ERREUR CONSTANT %s CANNOT BE MODIFIED\n",reset->data);
                }
             }
             reset = reset->next;
           }

    }
    if(strcmp(node->Type_token,"READ_TOKEN")==0){
      node=node->next;
      struct Node* reset2 = constantes;
      while(reset2!=NULL){
        if(strcmp(node->Nom_token,reset2->data)==0){
          printf("ERREUR CONSTANT %s CANNOT BE MODIFIED\n",reset2->data);
        }
        reset2=reset2->next;
      }
    }
    node = node->next;
  }
}
void stocker_tout(struct Node2* node){
  while(node!=NULL){
    if(strcmp(node->Type_of,"CONST_TOKEN")==0 || strcmp(node->Type_of,"VAR_TOKEN")==0 || strcmp(node->Type_of,"PROGRAM_TOKEN")==0){
      append(&tout,node->Nom_token);
    }
    node  = node->next; 
  }
}

void rule_3(struct Node2* node){
    while(node!=NULL){
      int a=0;
      if(strcmp(node->Type_of,"BEGIN_TOKEN")==0){
        struct Node* reset = tout;
        while(reset!=NULL){
          if(strcmp(reset->data,node->Nom_token)==0){
            a=1;
          }
          reset = reset->next;
        }
        if(a==0){
          printf("ERROR %s IS UNDECLARED\n",node->Nom_token);
        }
      }
    node = node->next;
    }
}
void rule_2(struct Node2* node){
  while(node!=NULL){
    if(strcmp(node->Type_of,"VAR_TOKEN")==0){
      struct Node* reset = constantes;
      while(reset!=NULL){
        if(strcmp(reset->data,node->Nom_token)==0){
          printf("ERROR %s IS ALREADY DECLARED AS CONSTANT\n",node->Nom_token);
        }
        reset=reset->next;
      }
    }
    node=node->next;
  }
}