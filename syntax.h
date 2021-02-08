#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"header.h"

enum ERREURS{
  PROGRAM_ERREUR,CONST_ERREUR,VAR_ERREUR,BEGIN_ERREUR,END_ERREUR,IF_ERREUR,THEN_ERREUR,WHILE_ERREUR,
  DO_ERREUR,READ_ERREUR,WRITE_ERREUR,PV_ERREUR,PT_ERREUR,PLUS_ERREUR,MOINS_ERREUR,MULT_ERREUR,
  DIV_ERREUR,VIR_ERREUR,AFF_ERREUR,
  PO_ERREUR,PF_ERREUR,ID_ERREUR,NUM_ERREUR,CONST_VAR_BEGIN_ERR,INST_ERR,COND_ERR,EG_ERREUR
};
void Symbole_Suiv();
void Test_Symbole(char stoken[],enum ERREURS erreur);
void Lancement();
void BLOCK();
void CONSTS() ;
void VARS();
void INSTS();
void INST();
void AFFEC();
void EXPR();
void TERM();
void FACT();
void SI();
void COND();
void TANTQUE();
void LIRE();
void ECRIRE();

int myvar ;