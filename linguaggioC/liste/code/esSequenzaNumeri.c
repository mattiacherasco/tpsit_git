#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct sequenza{
    int valore;
    struct sequenza* next;   
}Sequenza;

int chiediDim(int dim_max){
    int x;
    do{
        printf("inserire il numero massimo di elementi in sequenza [%d]: ", dim_max);
        scanf("%d", &x);
    } while (x > dim_max || x <= 0);
    return x;
}

bool is_empty(Sequenza* head){
    return head == NULL;
}

void enqueue(Sequenza** head, Sequenza** tail, Sequenza* elem){
    if(is_empty(*head)){
        *head = elem;
    }
    else{
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Sequenza* dequeue(Sequenza** head, Sequenza** tail){
    Sequenza* ret = *head;
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

void stampaCoda(Sequenza* head){
    Sequenza* l = head;
    while (l != NULL){
        printf("%d, ", l->valore);
        l = l->next;
    }
}


int main(){
    int DIM = 100;
    int numeri[DIM];
    int dim = chiediDim(DIM);

    Sequenza* headPari = NULL;
    Sequenza* headDispari = NULL;

    Sequenza* tailPari = NULL;
    Sequenza* tailDispari = NULL;

    for(int k = 0; k < dim; k++){
        printf("inserire il valore in posizione [%d]: ", k);
        scanf("%d", &numeri[k]);

        if(numeri[k] % 2 == 0){
            Sequenza* element = (Sequenza*) malloc(sizeof(Sequenza));
            element->valore = numeri[k];
            enqueue(&headPari, &tailPari, element);
        } else {
            Sequenza* element = (Sequenza*) malloc(sizeof(Sequenza));
            element->valore = numeri[k];
            enqueue(&headDispari, &tailDispari, element);
        }
    }
    stampaCoda(headPari);
    stampaCoda(headDispari);
    return 0;
}
