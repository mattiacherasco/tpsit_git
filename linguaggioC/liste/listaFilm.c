/*
author	Mattia Cherasco
date
esercizio
testo
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 200 //lunghezza massima delle stringhe
#define DIM 30 //numero di film presenti nella lista



typedef struct {
    int numero;
    char titolo[LUNG];
    char genere[LUNG];
    int anno;
    char dispo[LUNG];
} Film;

int leggiFilm(int dim, Film lista[]) {
    FILE *fp;
    char riga[LUNG];  //variabile che salva una riga intera del csv
    int k = 0;
    fp = fopen("listafilm.csv", "r");
    if(fp == NULL) {
        printf("file inesistente");
    } else {
        while(fgets(riga, LUNG, fp)) {//salvo la riga del csv in riga

            lista[k].numero = atoi(strtok(riga, ",")); //con strtok prendo le parole fino alla ','; con atoi trasformo la stringa in una variabile intera
            strcpy(lista[k].titolo, strtok(NULL, ","));
            strcpy(lista[k].genere, strtok(NULL, ","));
            lista[k].anno = atoi(strtok(NULL, ","));
            strcpy(lista[k].dispo, strtok(NULL, ","));
            k++;
        }
    }
    fclose(fp);
    return k;
}

void stampaTutto(Film lis[], int dim) {

    for(int k = 0; k < dim; k++) {
        printf("%d %s %s %d %s", lis[k].numero, lis[k].titolo, lis[k].genere, lis[k].anno, lis[k].dispo);
    }
}

void controlloAnno(Film lis[], int dim){
    int controllo;
    printf("\n\nche hanno vuoi controllae?");
    scanf("%d", &controllo);
    for(int k = 0; k < dim; k++){
        if(lis[k].anno==controllo)
         printf("\n%d %s %s %d %s", lis[k].numero, lis[k].titolo, lis[k].genere, lis[k].anno, lis[k].dispo);
    }
}

int main() {

    Film tab_film[DIM];
    int n= leggiFilm(DIM, tab_film);
    stampaTutto(tab_film, n);
    controlloAnno(tab_film, DIM);
return 0;
}
