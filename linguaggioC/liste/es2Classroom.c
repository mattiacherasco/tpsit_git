/*
author: Mattia Cherasco
date: 13/11/2023
es. lista 
testo Supponendo
date le seguenti definizioni:
typedef
struct El {int s;
      struct El *next;}
ElementoLista;
 typedef ElementoLista *ListaDiInteri;
• definire una funzione FirstEven che, data
una ListaDiInteri restituisce la posizione (puntatore) del primo elemento pari
nella lista (restituisce NULL se la lista non contiene elementi pari).
ListaDiInteri FirstEven(ListaDiInteri lis) {
 while (lis != NULL) {
     if (lis->s % 2 == 0)
            return lis;
  /* il primo pari è in lis 
       else
        lis = lis ->
next;


     }


     return NULL;


 }
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct El 
{
    int s;
    struct El *next;
}
ElementoLista;

void stampaLista(ElementoLista* lista){
    ElementoLista* l = lista;
    printf("\nValori lista: ");
    while (l != NULL)
    {
        printf("%d ", l->s);
        l = l ->next;
    }
}
void firstEven(ElementoLista* lista){
    ElementoLista *l= lista;
    int pos=0;
    while(l != NULL){
        if(l->s % 2==0){
            return pos;
        }
        l = l->next;
        pos++;
        return NULL;
    }
}

int main(){
    int n, num, numP;
    int lung = 0;
    ElementoLista* lista = NULL;
    ElementoLista* l;
    do{
        printf("inserire un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (ElementoLista*) malloc(sizeof(ElementoLista));
                l = lista;
            } else {
                l->next = (ElementoLista*) malloc(sizeof(ElementoLista));
                l = l->next;
            }
            l->s = n;
            l->next = NULL;
        }
    } while (n >= 0);
    stampaLista(lista);
    firstEven(lista);

    return 0;
}