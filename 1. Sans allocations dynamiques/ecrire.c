#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ecrire.h"


//**************************************************************************************************************//
//
//  Description : Proc�dure qui cr�e le nombre de cartes d'identit�es (choisie par l'utilisateur) rentr�es par l'utilisateur
//
//  Entr�es : 1 tableau de structure + 1 entier
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void cree_carte(Carte *carte, int nNb_carte){
    int nI;
    srand(time(NULL));
    for(nI=0;nI<nNb_carte;nI++){
        system("cls");
        printf("Creation de la carte numero %d :\n", nI);
        carte[nI].nID = rand();
        printf("Nom - ");
        fflush(stdin);
        gets(carte[nI].cNom);
        printf("Prenom - ");
        fflush(stdin);
        gets(carte[nI].cPrenom);
        printf("Adresse - ");
        fflush(stdin);
        gets(carte[nI].cAdresse);
        printf("Code postal - ");
        scanf("%d", &carte[nI].nPostal);
        printf("Ville - ");
        fflush(stdin);
        gets(carte[nI].cVille);
    }
}


//**************************************************************************************************************//
//
//  Description : Proc�dure qui ecrit les diff�rentes cartes d'identit�es dans un fichier texte
//
//  Entr�es : 1 tableau de structure + 1 entier
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void ecrire_carte(Carte *carte, int nNb_carte){
    int nI;
    FILE* fichier = NULL;
    fichier = fopen("Carte_identite.txt", "a");
    for(nI=0;nI<nNb_carte;nI++){
        fprintf(fichier, "~\nID - %d\nNom - %s\nPrenom - %s\nAdresse - %s\nCode postal - %d\nVille - %s\n~\n\n", carte[nI].nID, carte[nI].cNom, carte[nI].cPrenom, carte[nI].cAdresse, carte[nI].nPostal, carte[nI].cVille);
    }
    fclose(fichier);
}
