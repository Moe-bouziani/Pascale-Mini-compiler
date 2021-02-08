#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "syntax.h"

void Symbole_Suiv(){
head=head->next ;
}


void Erreur(enum ERREURS erreur){
	switch(erreur){
case 0: printf("ERREUR----->PROGRAM\n");break;
case 1: printf("ERREUR----->CONST_ERREUR\n");break;
case 2: printf("ERREUR----->VAR_ERREUR\n");break;
case 3: printf("ERREUR----->BEGIN_ERREUR\n");break;
case 4: printf("ERREUR----->END_ERREUR\n");break;
case 5: printf("ERREUR----->IF_ERREUR\n");break;
case 6: printf("ERREUR----->THEN_ERREUR\n");break;
case 7: printf("ERREUR----->WHILE_ERREUR\n");break;
case 8: printf("ERREUR----->DO_ERREUR\n");break;
case 9: printf("ERREUR----->READ_ERREUR\n");break;
case 10: printf("ERREUR----->WRITE_ERREUR\n");break;
case 11: printf("ERREUR----->PV_ERREUR\n");break; 
case 12: printf("ERREUR----->PT_ERREUR\n");break;
case 13: printf("ERREUR----->PLUS_ERREUR\n");break;
case 14: printf("ERREUR----->MOINS_ERREUR\n");break;
case 15: printf("ERREUR----->MULT_ERREUR\n");break;
case 16: printf("ERREUR----->DIV_ERREUR\n");break;
case 17: printf("ERREUR----->VIR_ERREUR\n");break;
case 18: printf("ERREUR----->AFF_ERREUR\n,");break;
case 19: printf("ERREUR----->PO_ERREUR\n");break;
case 20: printf("ERREUR----->PF_ERREUR\n");break;
case 21: printf("ERREUR----->ID_ERREUR\n");break;
case 22: printf("ERREUR----->NUM_ERREUR\n");break;
case 23: printf("ERREUR----->CONST_VAR_BEGIN_ERR\n");break;
case 24: printf("ERREUR----->INST_ERR\n");break;
case 25: printf("ERREUR----->COND_ERR\n");break;
case 26: printf("ERREUR----->EG_ERREUR\n");break;


}
}


void Test_Symbole(char  stoken[],enum ERREURS erreur) {

  if(strcmp(stoken,head->data)==0) {
    
  	
    Symbole_Suiv();
    
  }

  else {
  	
  	myvar=1;
    Erreur(erreur);
  }
}


void Lancement() {
  Test_Symbole("PROGRAM_TOKEN",PROGRAM_ERREUR);
  Test_Symbole("ID_TOKEN",ID_ERREUR);
  Test_Symbole("PV_TOKEN",PV_ERREUR);
  BLOCK();
  Test_Symbole("PT_TOKEN",PT_ERREUR);
}


void BLOCK() {
  CONSTS();
  VARS();
  INSTS();
}

void CONSTS() {
	

    if(strcmp("CONST_TOKEN",head->data)==0){Symbole_Suiv();
   
                       Test_Symbole("ID_TOKEN",ID_ERREUR);
                       Test_Symbole("EG_TOKEN",EG_ERREUR);
                       Test_Symbole("NUM_TOKEN",NUM_ERREUR);
                       Test_Symbole("PV_TOKEN",PV_ERREUR);
                      
                       while(strcmp("ID_TOKEN",head->data)==0) {

                           
                         
                         Test_Symbole("ID_TOKEN",ID_ERREUR);
                         Test_Symbole("EG_TOKEN",EG_ERREUR);
                         Test_Symbole("NUM_TOKEN",NUM_ERREUR);
                         Test_Symbole("PV_TOKEN",PV_ERREUR);
                             
            
                       }

                       } 
     else if(strcmp("VAR_TOKEN",head->data)==0){ int x=1;}
     else if(strcmp("BEGIN_TOKEN",head->data)==0){  int x=1;}
    else {Erreur(CONST_VAR_BEGIN_ERR) ;}

  }

 void VARS() {
  
     if(strcmp("VAR_TOKEN",head->data)==0){  Symbole_Suiv();

                     Test_Symbole("ID_TOKEN",ID_ERREUR);
                     
                     while(strcmp("VIR_TOKEN",head->data)==0) {
                     	
                        Symbole_Suiv();
                        Test_Symbole("ID_TOKEN",ID_ERREUR);
                     }
                     Test_Symbole("PV_TOKEN",PV_ERREUR);
                  }
     else if(strcmp("BEGIN_TOKEN",head->data)==0){ int x=1;}
    else{  Erreur(CONST_VAR_BEGIN_ERR) ;}
     
  }

void INSTS() {
	
  Test_Symbole("BEGIN_TOKEN",BEGIN_ERREUR);
  INST();
  
  while(strcmp(head->data,"PV_TOKEN")==0) {
    Symbole_Suiv();
    INST();
  }
  
  Test_Symbole("END_TOKEN",END_ERREUR);
}
void INST() {
	
  
     if(strcmp(head->data,"BEGIN_TOKEN")==0){ INSTS() ;}
     else if(strcmp(head->data,"ID_TOKEN")==0) { AFFEC() ; }
     else if(strcmp(head->data,"IF_TOKEN" )==0)  {SI() ; }
     else if(strcmp(head->data,"WHILE_TOKEN")==0) {TANTQUE();}
     else if(strcmp(head->data,"WRITE_TOKEN" )==0) {ECRIRE(); }
     else if(strcmp(head->data,"READ_TOKEN" )==0)  {LIRE()  ;}
     else if(strcmp(head->data,"END_TOKEN" )==0)  {int x=1;} 
    else{Erreur(INST_ERR);} 
}


void AFFEC() {
	
  Test_Symbole("ID_TOKEN",ID_ERREUR);
  Test_Symbole("AFF_TOKEN",AFF_ERREUR);
  
  EXPR();
  
}

void EXPR() {
	
  TERM();

  while( (strcmp(head->data,"PLUS_TOKEN")==0) || (strcmp(head->data,"MOINS_TOKEN")==0) ) {
  
    Symbole_Suiv();
    TERM();
  }
}

void TERM() {
	
  FACT();
  
  while(  (strcmp(head->data,"MULT_TOKEN")==0) || (strcmp(head->data,"DIV_TOKEN")==0) ){
    Symbole_Suiv();
    FACT();
  }
}
void FACT() {
	
     if(strcmp(head->data,"ID_TOKEN")==0 || strcmp(head->data,"NUM_TOKEN")==0) {Symbole_Suiv(); }
    else if(strcmp(head->data,"PO_TOKEN")==0) {EXPR(); Test_Symbole("PF_TOKEN",PF_ERREUR);}
                            
 
}

void SI() {
	
  Test_Symbole("IF_TOKEN",IF_ERREUR);
  COND();
  Test_Symbole("THEN_TOKEN",THEN_ERREUR);
  INST();
}

void COND() {
	
  EXPR();
 
  
  
    if(strcmp(head->data,"EG_TOKEN")==0) {Symbole_Suiv();EXPR();Symbole_Suiv();}
    else if(strcmp(head->data ,"DIFF_TOKEN")==0) {Symbole_Suiv();EXPR();Symbole_Suiv();}
    else if(strcmp(head->data  ,"INF_TOKEN")==0) {EXPR();Symbole_Suiv()  ;}
    else if(strcmp(head->data  ,"SUP_TOKEN" )==0){EXPR();Symbole_Suiv() ;}
    else if(strcmp(head->data  ,"INFEG_TOKEN")==0) {Symbole_Suiv();EXPR();Symbole_Suiv();}
    else if(strcmp(head->data ,"SUPEG_TOKEN")==0) {Symbole_Suiv();EXPR();Symbole_Suiv();}
    else {Erreur(COND_ERR) ;}
  

  EXPR();
}

void TANTQUE() {
	
  Test_Symbole("WHILE_TOKEN",WHILE_ERREUR);
  COND();
  Test_Symbole("DO_TOKEN",DO_ERREUR);
  if(strcmp(head->data,"BEGIN_TOKEN")==0){
    INSTS();
  }
  else INST();
  
}

 
 void ECRIRE() {
 	
  Test_Symbole("WRITE_TOKEN",WRITE_ERREUR);
  Test_Symbole("PO_TOKEN",PO_ERREUR);
  EXPR();
  
  while(strcmp(head->data,"VIR_TOKEN")==0) {
    Symbole_Suiv();
    EXPR();
  }
  
  Test_Symbole("PF_TOKEN",PF_ERREUR);
  
}



void LIRE() {
	
  Test_Symbole("READ_TOKEN",READ_ERREUR);
  Test_Symbole("PO_TOKEN",PO_ERREUR);
  Test_Symbole("ID_TOKEN",ID_ERREUR);
  
  while(strcmp(head->data,"VIR_TOKEN")==0) {
    Symbole_Suiv();
    Test_Symbole("ID_TOKEN",ID_ERREUR);
  }
  
  Test_Symbole("PF_TOKEN",PF_ERREUR);
  
}
