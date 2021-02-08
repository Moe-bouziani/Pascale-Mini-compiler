#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> 
#include <stdbool.h>
#include"header.h"
#include"syntax.h"

int main(){
    analyse(head);
    printList(head);
    Lancement();
    determiner(head2);
    stocker_const(head2);
    stocker_tout(head2);
    rule_2(head2);
    rule_3(head2);
    rule_4(head2);
    rule_5(head2);

}