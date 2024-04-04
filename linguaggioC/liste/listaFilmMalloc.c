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
    char* titolo;
    char* genere;
    int anno_uscita;
    char* disponibilita;
} Struttura;
/*
int leggiFile(Struttura film[]) {
    FILE*fp=fopen("listafilm.csv","r");
    int k=0;
    char riga[LUNG_RIGA];
    char *tok;
    while(fgets(riga,LUNG_RIGA,fp)!=NULL) {
        tok=strtok(riga,",");
        film[k].n=atoi(tok);
        tok=strtok(NULL,",");
        strcpy(film[k].titolo,tok);
        tok=strtok(NULL,",");
        strcpy(film[k].genere,tok);
        tok=strtok(NULL,",");
        film[k].anno_uscita=atoi(tok);
        tok=strtok(NULL,",");
        strcpy(film[k].disponibilita,tok);
        k++;
    }
    fclose(fp);
    return k;
}
*/

void cercaAnno(int anno_scelta, Struttura film[], int cont){
    for(int k=0;k<cont;k++){
        if(anno_scelta==(film+k)->anno_uscita){
            printf("%d %s %s %d %s\n",(film+k)->n,(film+k)->titolo,(film+k)->genere,(film+k)->anno_uscita,(film+k)->disponibilita);
        }
    }
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

int main() {
    char fileName[]="./listafilm.csv";
    Struttura *film;
    int contlung=contalunghezzaFile(fileName);
    film = (Struttura*) malloc (contlung * sizeof(Struttura));
    char *riga;
    riga = (char*) malloc (LUNG_RIGA * sizeof(char));
    FILE* fp;
    char* campo;
    int cont=0;
    int scelta;
    fp=fopen(fileName,"r");
    if(fp==NULL){
        printf("Il file non esiste! \n");
        exit(1);
    }
    while(fgets(riga,LUNG_RIGA,fp)){
        campo=strtok(riga,",");
        (film+cont)->n=atoi(campo);
        campo=strtok(NULL,",");
        (film+cont)->titolo=strdup(campo);
        campo=strtok(NULL,",");
        (film+cont)->genere=strdup(campo);
        campo=strtok(NULL,",");
        (film+cont)->anno_uscita=atoi(campo);
        campo=strtok(NULL,",");
        (film+cont)->disponibilita=strdup(campo);
        cont++;
    }
    
    for(int k=0; k<cont; k++) {
        printf("%d %s %s %d %s\n",(film+k)->n,(film+k)->titolo,(film+k)->genere,(film+k)->anno_uscita,(film+k)->disponibilita);
    }
    
    printf("Inserisci un anno: \n");
    scanf("%d",&scelta);
    cercaAnno(scelta,film,cont);
    return 0;
}