#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

typedef struct Carte{
    int nID;
    char cNom[25];
    char cPrenom[25];
    char cAdresse[50];
    int nPostal;
    char cVille[50];

}Carte;

char menu();

#endif // MAIN_H_INCLUDED
