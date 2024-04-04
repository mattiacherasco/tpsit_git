/*
Nei Pronto Soccorsi dell’ospedale i pazienti sono classificati con un colore: 
rosso (urgentissimo)
giallo (grave)
verde (moderato)
bianco (lieve). 
Funziona così: quando una persona arriva al pronto soccorso 
l’infermiere lo registra (nome e età) e decide anche il colore di priorità; 
appena un medico è libero deve gestire prima quelli con codice rosso, 
poi giallo, poi verde e poi bianco. 
Dichiara una struttura Paziente con i campi:
Nome,
Età,
Colore;
il programma deve gestire 4 code diverse e inserire il paziente nella lista 
corretta, quando un medico è libero entra il paziente successivo, 
(quindi sceglie il primo dei pazienti codice verde solo se non ci sono codici 
rosso e giallo).
Le informazioni vanno visualizzate a schermo.
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>

typedef struct paziente{
    char* nome;
    int eta;
    char* colore;
    struct paziente* next;   
}Paziente;

int chiediDim(int dim_max){
    int x;
    do{
        printf("inserire il numero massimo di pazienti in questo ospdeale [%d]: ", dim_max);
        scanf("%d", &x);
    } while (x > dim_max || x <= 0);
    return x;
}

bool is_empty(Paziente* head){
    return head == NULL;
}

void enqueue(Paziente** head, Paziente** tail, Paziente* elem){
    if(is_empty(*head)){
        *head = elem;
    }
    else{
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Paziente* dequeue(Paziente** head, Paziente** tail){
    Paziente* ret = *head;
    if(is_empty(*head)){
        printf("\nErrore coda vuota");
        return NULL;
    }
    else{
        *head = ret->next;
    }
    if(*head == NULL){
        *tail = NULL;
    }
    return ret;
}

void gestioneOsp(Paziente** headRosso, Paziente** tailRosso, Paziente** headGiallo, Paziente** tailGiallo, Paziente** headVerde, Paziente** tailVerde, Paziente** headBianco, Paziente** tailBianco){
    while(is_empty(*headRosso)!=true || is_empty(*headGiallo)!=true
     || is_empty(*headVerde)!=true || is_empty(*headBianco)!=true){
        if(is_empty(*headRosso) != true){
            dequeue(headRosso,tailRosso);
        }else if(is_empty(*headGiallo) != true){
            dequeue(headGiallo,tailGiallo);
        }else if(is_empty(*headVerde) != true){
            dequeue(headVerde,tailVerde);
        }else{
            dequeue(headBianco,tailBianco);
        }  
    }
}

void stampaCoda(Paziente* head){
    Paziente* l = head;
    while (l != NULL){
        printf("%s, %d, %s", l->nome, l->eta, l->colore);
        l = l->next;
    }
}


int main(){
    int eta;
    Paziente* headRosso=NULL;
    Paziente* headGiallo=NULL;
    Paziente* headVerde=NULL;
    Paziente* headBianco=NULL;
    Paziente* tailRosso=NULL;
    Paziente* tailGiallo=NULL;
    Paziente* tailVerde=NULL;
    Paziente* tailBianco=NULL;

    char* nome = (char*) malloc(sizeof(char));
    char* colore = (char*) malloc(sizeof(char));
    int scelta=0;

    while (scelta!=-1){
        printf("\nInserisci un numero (-1 per uscire, 1 per inserire un nuovo paziente, 2 per mandare un medico,3 per stampare): ");
        scanf("%d", &scelta);
        switch (scelta) {
        case -1:
            printf("Hai premuto -1. Uscita dal programma.\n");
            break;
        case 1:
            printf("inserire il nome del nuovo  paziente: ");
            fflush(stdin);
            scanf("%s", nome);
            printf("inserire l'eta del nuovo paziente");
            fflush(stdin);
            scanf("%d", &eta);
            printf("inserire colore del nuovo paziente: ");
            fflush(stdin);
            scanf("%s", colore);

            Paziente* element = (Paziente*) malloc(sizeof(Paziente));
            element->nome = nome;
            element->eta = eta;
            element->colore = colore;
            if(strcmp(colore,"rosso")==0){
                enqueue(&headRosso, &tailRosso, element);
            }else if(strcmp(colore,"giallo")==0){
                enqueue(&headGiallo, &tailGiallo, element);
            }else if(strcmp(colore,"verde")==0){
                enqueue(&headVerde, &tailVerde, element);
            }else if(strcmp(colore,"bianco")==0){
                enqueue(&headBianco, &tailBianco, element);
            }
            element=element->next;
            break;
        case 2:
            gestioneOsp(&headRosso, &tailRosso, &headGiallo, &tailGiallo, &headVerde, &tailVerde, &headBianco, &tailBianco);
        case 3:
            printf("inserire il colore che si vuole stampare: ");
            fflush(stdin);
            scanf("%s", colore);
            if(strcmp(colore,"rosso")==0){
                stampaCoda(headRosso);
            }else if(strcmp(colore,"giallo")==0){
                stampaCoda(headGiallo);
            }else if(strcmp(colore,"verde")==0){
                stampaCoda(headVerde);
            }else if(strcmp(colore,"bianco")==0){
                stampaCoda(headBianco);
            }
            break;
        default:
            printf("Scelta non valida.\n");
            break;
        }
    }
     
    return 0;
}
