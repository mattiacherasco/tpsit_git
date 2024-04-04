
/*
author	Mattia Cherasco
date
esercizio
testo
*/
#include <stdio.h>
#include <stdlib.h>
#define DIM 5

void caricaVett(int vett[], int dim)
{
    for (int *i = vett; i < vett + dim; i++)
    {
        printf("inserisci un elemento: ");
        scanf("%d", i);
    }
}

void StampaVett(int vett[], int dim)
{
    for (int *i = vett; i < vett + dim; i++)
    {
        printf("%d \n", *i);
    }
}

int main()
{
    int *vett;
    vett = (int*) malloc (DIM * sizeof(int));

    caricaVett(vett, DIM);
    StampaVett(vett, DIM);

    //libero la memoria
    free(vett);
    return 0;
}