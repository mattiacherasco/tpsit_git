/*
author	Mattia Cherasco
date
esercizio
testo
Scrivere un programma in C che calcoli la somma degli
elementi di un array utilizzando l'aritmetica dei puntatori. Nel programma deve
essere implementata una funzione calcolaSomma()
che riceva due argomenti (la lunghezza dell'array e un puntatore), calcola la
somma degli elementi dell'array utilizzando un puntatore e
restituisce la somma calcolata. Il main()
dichiara un array, utilizza la funzione calcolaSomma() e stampa il risultato
restituito dalla funzione.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 5

int sommaVett(int vett[]){
int s=0;
for(int *p=vett; p<vett+DIM; p++){
    s+=*p;
}
return s;
}

int main() {

    int vett[DIM];
    for(int *p=vett; p<vett+DIM; p++){
        printf("\ninserisci il numero in poszione %d ", p);
        scanf("%d", p);
    }
    int somma=sommaVett(vett);
    printf("la somma e' %d", somma);
return 0;
}
