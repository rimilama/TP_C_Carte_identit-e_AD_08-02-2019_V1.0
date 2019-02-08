#include <stdio.h>
#include <stdlib.h>
#include "lire.h"


//**************************************************************************************************************//
//
//  Description : Procédure qui lit l'ensemble des cartes d'identités présentent dans le fichier carte_identité.txt
//
//  Entrées : /
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void lire_carte(){
    int nCompt=0, nI;
    char cCarac;
    FILE* fichier = NULL;
    fichier = fopen("Carte_identite.txt", "r");
    if(fichier!=NULL){
        do{
            cCarac = fgetc(fichier);
            if(cCarac=='~'){
                nCompt++;
            }
        }while(feof(fichier)==0);
        nCompt = nCompt/2;
        Carte *carte;
        carte = malloc(nCompt*sizeof(Carte));
        fseek(fichier, 7, SEEK_SET);
        for(nI=0;nI<nCompt;nI++){
            fscanf(fichier, "%d", &carte[nI].nID);
            fseek(fichier, 7, SEEK_CUR);
            fscanf(fichier, "%s", carte[nI].cNom);
            fseek(fichier, 10, SEEK_CUR);
            fscanf(fichier, "%s", carte[nI].cPrenom);
            fseek(fichier, 11, SEEK_CUR);
            fgets(carte[nI].cAdresse, 50, fichier);
            fseek(fichier, 14, SEEK_CUR);
            fscanf(fichier, "%d", &carte[nI].nPostal);
            fseek(fichier, 9, SEEK_CUR);
            fgets(carte[nI].cVille, 50, fichier);
            fseek(fichier, 13, SEEK_CUR);
        }
        afficher_carte(carte, nCompt);
        free(carte);

    }else{
        printf("Aucun fichier n'existe !");
    }
}


//**************************************************************************************************************//
//
//  Description : Procédure qui affiche l'ensemble des cartes d'identité lu dans le fichier texte
//
//  Entrées : 1 tableau de structure + 1 entier
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void afficher_carte(Carte *carte, int nNb_carte){
    int nI;
    for(nI=0;nI<nNb_carte;nI++){
        printf("\nID - %d\nNom - %s\nPrenom - %s\nAdresse - %sCode postal - %d\nVille - %s\n", carte[nI].nID, carte[nI].cNom, carte[nI].cPrenom, carte[nI].cAdresse, carte[nI].nPostal, carte[nI].cVille);
    }
}
