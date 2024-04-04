/*
author: Mattia Cherasco
date: 13/11/2023
es. lista 
testo creazione di una lista
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char valore;
    struct node* next;   
}Node;

int is_empty(Node* head){
    if(head == NULL){
        return 1;
    }else {
        return 0;
    }
}

void push(Node **head, Node *element){
    if(is_empty(*head)){
        *head = element;
        element->next;
    }else{
        element->next;
        *head = element;
    }
}

Node* pop(Node **head){
    Node* ret=*head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head=ret->next;
    }
    return ret;
}

void stampaPila(Node *head){
    Node* l=head;
    while (l!=NULL){
        printf("%s ", l->valore);
        l=l->next;
    }
}
void confrontaPal(Node *head){
    Node* l=head;
    Node* l=push(head, element);//cosi ho al contrario 
    for(int k=0; k < strlen(head->valore); k++){
        for (int j = strlen(head->valore); j = 0; j--){
            if l->valore
        }
    }
}
int main(){
    char* stringa;
    Node* head=NULL;
    Node* l;
    stringa = (char*) malloc (sizeof(char));
    printf("inserire una stringa: ");
    fflush(stdin);
    scanf("%s", stringa);
    for(int cont=0; cont < strlen(stringa); cont++){
        Node* element = (Node*) malloc(sizeof(Node));
        element->valore=stringa[cont];
        push(&head, element);
    }
    stampaPila(head);
    confrontaPal(head);
    stampaPila(head);
    return 0;
}