#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <time.h>

typedef struct coda{
    int numArrivo;
    int valore;
    struct coda* next;   
}Coda;

int chiediNum(int dim_max){
    int x;
    do{
        printf("inserire il numero d'arrivo: ");
        scanf("%d", &x);
    } while (x > dim_max || x <= 0);
    return x;
}

int generaCasuale(int limMin, int limMax){
    return limMin+rand()%limMax+1-limMin;
}

bool is_emptyCoda(Coda* head){
    return head == NULL;
}

void enqueue(Coda** head, Coda** tail, Coda* elem){
    if(is_emptyCoda(*head)){
        *head = elem;
    }
    else{
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Coda* dequeue(Coda** head, Coda** tail){
    Coda* ret = *head;
    if(is_emptyCoda(*head)){
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

void stampaCoda(Coda* head){
    Coda* l = head;
    while (l != NULL){
        printf("Coda: numero arrivo %d  valore %d\n", l->numArrivo, l->valore);
        l = l->next;
    }
}



typedef struct pila{
    int numArrivo;
    int valore;
    struct pila* next;
}Pila;

bool is_emptyPila(Pila* head){
    return head == NULL;
}

void push(Pila **head, Pila *element){
    if(is_emptyPila(*head)){
        *head = element;
        element->next = NULL;
    }
    else{
        element->next = *head;
        *head = element;
    }
}


Pila* pop(Pila **head){
    Pila* stack;
    if(is_emptyPila(*head)){
        return NULL;
    }
    else{
        stack = *head;
        *head = stack->next;
    }
    return stack;
}

void stampaPila(Pila* head){
    Pila* l = head;
    while(l != NULL){
        printf("Pila: numero arrivo %d  valore %d\n", l->numArrivo, l->valore);
        l = l->next;
    }
}



void scontro(Pila* head, Coda* headCoda, Coda* tailCoda){
    stampaCoda(headCoda);
    stampaPila(head);
    if(head->valore > headCoda->valore){
        head->valore-=headCoda->valore;
        dequeue(&headCoda, &tailCoda);
        printf("vincitore %d", head->valore);
        free(headCoda);
    }else if(head->valore < headCoda->valore){
        headCoda->valore-=head->valore;
        pop(&head);
        printf("vincitore %d", headCoda->valore);
        free(head);
    }else{
        pop(&head);
        dequeue(&headCoda, &tailCoda);
    }
    if(head->next==NULL){
        printf("vincitore è la coda");
        stampaCoda(headCoda);
    }else if(headCoda->next==NULL){
        printf("vincitore è la pila");
        stampaPila(head);
    }else{
        scontro(head->next, headCoda->next, tailCoda);
    }
}


int main(){
    srand(time(NULL));
    int eta;
    Coda* headCoda1=NULL;
    Coda* tailCoda1=NULL;

    Coda* headCoda2=NULL;
    Coda* tailCoda2=NULL;

    Coda* headCoda3=NULL;
    Coda* tailCoda3=NULL;

    Coda* headCoda4=NULL;
    Coda* tailCoda4=NULL;

    Coda* headCoda5=NULL;
    Coda* tailCoda5=NULL;
    
    Pila* el;
    Pila* head1;
    Pila* head2;
    Pila* head3;
    Pila* head4;
    Pila* head5;



    int numArrivo=0;
    int valore=0;
    int scelta=0;

    while (scelta!=-1){
        printf("\nInserisci un numero (-1 per uscire, 1 per inserire nuovo, 3 per stampare): ");
        scanf("%d", &scelta);
        switch (scelta) {
        case -1:
            printf("Hai premuto -1. Uscita dal programma.\n");
            break;
        case 1:
            Coda* element = (Coda*) malloc(sizeof(Coda));
            element->numArrivo = chiediNum(5);
            element->valore=generaCasuale(1, 10);
            enqueue(&headCoda1, &tailCoda1, element);
            enqueue(&headCoda2, &tailCoda2, element);
            enqueue(&headCoda3, &tailCoda3, element);
            enqueue(&headCoda4, &tailCoda4, element);
            enqueue(&headCoda5, &tailCoda5, element);


            head1 = (Pila*)malloc(sizeof(Pila));
            el = (Pila*)malloc(sizeof(Pila));
        
            el->numArrivo = chiediNum(5);
            el->valore=generaCasuale(1, 10);

            push(&head1, el);
            push(&head2, el);
            push(&head3, el);
            push(&head4, el);
            push(&head5, el);
            head1 = head1->next;
            head2 = head2->next;
            head3 = head3->next;
            head4 = head4->next;
            head5 = head5->next;





            element=element->next;
            break;
        case 2:
            scontro(head1, headCoda1, tailCoda1);
        case 3:
            stampaCoda(headCoda1);
            printf("\n");
            stampaCoda(headCoda2);
            printf("\n");
            stampaCoda(headCoda3);
            printf("\n");
            stampaCoda(headCoda4);
            printf("\n");
            stampaCoda(headCoda5);
            printf("\n");
            stampaPila(head1);
            printf("\n");
            stampaPila(head2);
            printf("\n");
            stampaPila(head3);
            printf("\n");
            stampaPila(head4);
            printf("\n");
            stampaPila(head5);

            break;
        }
    }
     
    return 0;
}

