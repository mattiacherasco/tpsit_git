/*
author	Mattia Cherasco
date
esercizio
testo
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define LUNG_MAX 150
#define DIM 20000
#define LUNG_RIGA 200

typedef struct {
    int n;
    char* cognome;
    char* nome;
    int anno;
    int mese;
    int giorno;
} Struttura;

int leggiFile(Struttura elenco[]) {
    FILE*fp=fopen("prova.csv", "r");
    int cont=0;
    char riga[LUNG_RIGA];
    char *campo;
    char *tok;
    while(fgets(riga,LUNG_RIGA,fp)!=NULL) {
        campo=strtok(riga,",");
        (elenco+cont)->cognome=strdup(campo);
        campo=strtok(NULL,",");
        (elenco+cont)->nome=strdup(campo);
        campo=strtok(NULL,",");
        (elenco+cont)->anno=atoi(campo);
        campo=strtok(NULL,",");
        (elenco+cont)->mese=atoi(campo);
        campo=strtok(NULL,",");
        (elenco+cont)->giorno=atoi(campo);
        cont++;
    }
    fclose(fp);
    return cont;
}


int contalunghezzaFile(char fileName[]){
    int cont=0;
    char *riga;
    riga=(char*) malloc(LUNG_RIGA * sizeof(char));
    FILE *fp=fopen(fileName,"r");
    if(fp==NULL){
        printf("Il file non esiste! \n");
        exit(1);
    }
    while(fgets(riga,LUNG_RIGA,fp)!=NULL){
        cont++;
    }
    fclose(fp);
    return cont;
}

void scambio(Struttura *n1, Struttura *n2)
{
    Struttura z;
    z = *n1;
    *n1 = *n2;
    *n2 = z;
}


void ordinaElenco(Struttura elenco[], int n)
{
     
    int j, sup, sca;
    sup = n - 1;
    while (sup > 0)
    {
        sca = 0;
        j = 0;
        for (Struttura *cont = elenco; cont < elenco + n; cont++)
        {
            j++;
             if ((cont->anno < (cont+1)->anno) ||
                (cont->anno == (cont+1)->anno && (cont)->mese < (cont+1)->mese) ||
                (cont->anno == (cont+1)->anno && (cont)->mese == (cont+1)->mese && (cont)->giorno < (cont+1)->giorno)) {
                scambio(cont, (cont+1));
                sca = j;
            }
            j++;
        }
        sup = sca;
    }
}

int main() {
    char fileName[]="prova.csv";
    Struttura *elenco;
    int contlung=contalunghezzaFile(fileName);
    elenco = (Struttura*) malloc (contlung * sizeof(Struttura));
    FILE* fp;
    fp=fopen(fileName,"r");
    if(fp==NULL){
        printf("Il file non esiste! \n");
        exit(1);
    }
    
    ordinaElenco(elenco, contlung);
    
    //stampa
    for(Struttura *k=elenco; k<elenco+contlung; k++) {
        printf("%s %s %d %d %d\n", k->cognome, k->nome, k->anno, k->mese, k->giorno);
    }

    return 0;
}