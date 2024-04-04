#include <stdio.h>
#include <stdlib.h>

// Struttura per il nodo di una lista
typedef struct Nodo {
    int dato;
    struct Nodo* prossimo;
} Nodo;

// Struttura per la coda
typedef struct Coda {
    Nodo* inizio;
    Nodo* fine;
} Coda;

// Struttura per la pila
typedef struct Pila {
    Nodo* cima;
} Pila;

// Funzione di inizializzazione per la coda
void inizializzaCoda(Coda* coda) {
    coda->inizio = coda->fine = NULL;
}

// Funzione di inizializzazione per la pila
void inizializzaPila(Pila* pila) {
    pila->cima = NULL;
}

// Funzione per l'inserimento nella coda
void inserisciCoda(Coda* coda, int dato) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuovoNodo->dato = dato;
    nuovoNodo->prossimo = NULL;

    if (coda->fine == NULL) {
        // La coda è vuota
        coda->inizio = coda->fine = nuovoNodo;
    } else {
        // Aggiungi il nuovo nodo alla fine della coda
        coda->fine->prossimo = nuovoNodo;
        coda->fine = nuovoNodo;
    }
}

// Funzione per l'estrazione dalla coda
int estraiCoda(Coda* coda) {
    if (coda->inizio == NULL) {
        // La coda è vuota
        printf("Errore: la coda è vuota\n");
        return -1; // Valore sentinella per indicare errore
    }

    Nodo* nodoEstratto = coda->inizio;
    int datoEstratto = nodoEstratto->dato;

    coda->inizio = nodoEstratto->prossimo;

    // Verifica se la coda è diventata vuota
    if (coda->inizio == NULL) {
        coda->fine = NULL;
    }

    free(nodoEstratto);
    return datoEstratto;
}

// Funzione per l'inserimento nella pila
void inserisciPila(Pila* pila, int dato) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuovoNodo->dato = dato;
    nuovoNodo->prossimo = pila->cima;

    pila->cima = nuovoNodo;
}

// Funzione per l'estrazione dalla pila
int estraiPila(Pila* pila) {
    if (pila->cima == NULL) {
        // La pila è vuota
        printf("Errore: la pila è vuota\n");
        return -1; // Valore sentinella per indicare errore
    }

    Nodo* nodoEstratto = pila->cima;
    int datoEstratto = nodoEstratto->dato;

    pila->cima = nodoEstratto->prossimo;

    free(nodoEstratto);
    return datoEstratto;
}

// Funzione per confrontare due code e determinare se sono uguali
int equalsCoda(Coda* coda1, Coda* coda2) {
    Nodo* nodo1 = coda1->inizio;
    Nodo* nodo2 = coda2->inizio;

    while (nodo1 != NULL && nodo2 != NULL) {
        if (nodo1->dato != nodo2->dato) {
            return 0; // Le code sono diverse
        }
        nodo1 = nodo1->prossimo;
        nodo2 = nodo2->prossimo;
    }

    // Verifica se entrambe le code sono state completamente attraversate
    return (nodo1 == NULL && nodo2 == NULL);
}

int main() {
    Coda coda1, coda2;
    Pila pila1, pila2;
    
    inizializzaCoda(&coda1);
    inizializzaCoda(&coda2);
    
    inizializzaPila(&pila1);
    inizializzaPila(&pila2);

    // Esempio di inserimento nella coda
    inserisciCoda(&coda1, 1);
    inserisciCoda(&coda1, 2);
    inserisciCoda(&coda1, 3);

    // Esempio di inserimento nella pila
    inserisciPila(&pila1, 1);
    inserisciPila(&pila1, 2);
    inserisciPila(&pila1, 3);

    // Esempio di estrazione dalla coda
    printf("Elemento estratto dalla coda: %d\n", estraiCoda(&coda1));

    // Esempio di estrazione dalla pila
    printf("Elemento estratto dalla pila: %d\n", estraiPila(&pila1));

    // Esempio di confronto tra due code
    if (equalsCoda(&coda1, &coda2)) {
        printf("Le code sono uguali.\n");
    } else {
        printf("Le code sono diverse.\n");
    }

    return 0;
}
