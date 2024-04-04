
/*
author	Mattia Cherasco
date
esercizio
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 100

int chiediDim(int dim_max)
{
    int dim;
    do
    {
        printf("inserire la dimensione tra 0 e %d:", dim_max);
        scanf("%d", &dim);
    } while (dim < 0 || dim > dim_max);
    return dim;
}
void caricaVett(int v[], int n)
{

    for (int *p = v; p < v + n; p++)
    {
        printf("\ninserisci il numero in posizioe %d ", p);
        scanf("%d", p);
    }
}

void scambio(int *x, int *y)
{
    int *z;
    *z = *x;
    *x = *y;
    *y = *z;
}

void bubbleSort3(int vett[], int n){
    int *p, j, sup, sca;
    sup = n - 1;
    while (sup > 0){
        sca = 0;
        j = 0;
        for (p = vett; p < vett + sup; p++){
            j++;
            if (*p > *(p + 1)){
                scambio(p, p + 1);
                sca = j;
            }
            j++;
        }
        sup = sca;
    }
}

int main()
{

    int dim, x;
    dim = chiediDim(DIM);
    int vett[dim];
    caricaVett(vett, dim);
    bubbleSort3(vett, dim);
    for (int *p = vett; p < vett + dim; p++)
    {
        printf("%d", *p);
    }
    return 0;
}