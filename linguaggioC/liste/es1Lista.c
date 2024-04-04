/*
author: Marco Giorgis
date: 13/11/2023
es. lista 
testo creazione di una lista
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int valore;
    struct node* next;   
}Node;

int calcolaLunghezza(Node* lista){
    Node* l = lista;
    int lung = 0;
    while (l != NULL)
    {
        lung++;
        l = l ->next;
    }
    return lung; 
}

int ricorsivaLunghezza(Node* lista, int lung){
    Node* l = lista;
    if(l != NULL){
        lung++;
        lung = ricorsivaLunghezza(l->next, lung);
    }
    return lung;
}

int ricorsivaLunghezza1(Node* head){
    if(head->next != NULL){
        return 1 + ricorsivaLunghezza1(head->next);
    }
    return 1;
}

void stampaLista(Node* lista){
    Node* l = lista;
    printf("\nValori lista: ");
    while (l != NULL)
    {
        printf("%d ", l->valore);
        l = l ->next;
    }
}

void stampaListaRicorsiva(Node* lista){
    Node* l = lista;
    if(l != NULL){
        printf("%d ", l->valore);
        stampaListaRicorsiva(l->next);
    }
}

void aggiungiLista(Node** lista, int num){
    Node* l = *lista;
    while (l->next != NULL){
        l = l->next;
    }
    l->next = (Node*) malloc(sizeof(Node));
    l->valore = num;
    l->next = NULL;
}

void aggiungiPrimoElemento(Node** lista, int num){
    Node* nuovoNodo = (Node*) malloc(sizeof(Node));
    nuovoNodo->next = *lista;
    nuovoNodo->valore = num;
    *lista = nuovoNodo;
}

void rimuoviUltimoElemento(Node** lista){
    Node* l = *lista;
    while (l->next->next != NULL)
    {
        l = l->next;
    }
    free(l->next);
    l->next = NULL;
}

int main(){
    int n, num, numP;
    int lung = 0;
    Node* lista = NULL;
    Node* l;
    do{
        printf("inserire un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (Node*) malloc(sizeof(Node));
                l = lista;
            } else {
                l->next = (Node*) malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    } while (n >= 0);

    l = lista;
    printf("numeri inseriti: ");
    printf("\n");
    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next;
    }
    printf("\n");
    printf("Numero di elementi: %d", calcolaLunghezza(lista));
    printf("\nNumero di elementi con ricorsiva: %d", ricorsivaLunghezza(lista, lung));
    printf("\nInserire un valore da aggiungere: ");
    scanf("%d", &num);
    printf("\nInserire un numero da aggiungere in prima posizione: ");
    scanf("%d", &numP);
    aggiungiLista(&lista, num); //passata come puntatore per aggiungere o rimuvore elementi
    aggiungiPrimoElemento(&lista, numP);
    stampaLista(lista);
    printf("\nLista senza ultimo elemento: ");
    rimuoviUltimoElemento(&lista);
    stampaLista(lista);
    printf("\nValori lista ricorsiva: ");
    stampaListaRicorsiva(lista);
    return 0;
}