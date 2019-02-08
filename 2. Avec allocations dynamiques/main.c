#include <stdio.h>
#include <stdlib.h>
#include "main.h"


int main()
{
    int nNb_carte;
    char cChoix;
    cChoix = menu();
    if(cChoix=='1'){
        printf("Combien de carte d'identite voulez-vous cree ?\n");
        scanf("%d", &nNb_carte);
        Carte *carte;
        carte = malloc(nNb_carte*sizeof(Carte));
        cree_carte(carte, nNb_carte);
        ecrire_carte(carte, nNb_carte);
        free(carte);
    }else{
        lire_carte();
    }
}


//**************************************************************************************************************//
//
//  Description : Fonction qui affiche un menu et retourne le choix de l'utilisateur
//
//  Entrées : /
//
//  Sorties : 1 caractère
//
//  Notes : /
//
//***************************************************************************************************************//
char menu(){
    char cChoix;
    printf("Que voulez vous faire ?\n\n");
    printf("1 - Ecrire\n");
    printf("2 - Lire\n");
    fflush(stdin);
    cChoix = getchar();
    while(cChoix!='1' && cChoix!='2'){
        printf("\nERREUR\n");
        fflush(stdin);
        cChoix = getchar();
    }
    system("cls");
    return cChoix;
}
