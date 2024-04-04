/*
Scrivi un programma in linguaggio C che
gestisca un archivio di libri. Il programma deve utilizzare una struttura Libro per rappresentare ciascun libro, con le seguenti
informazioni:
-Titolo (massimo 100 caratteri)
-Autore (massimo 100 caratteri)
-Anno di pubblicazione
Il programma deve consentire all'utente
di eseguire le seguenti operazioni:
-Stampare l'archivio dei libri:
-Stampa tutte le informazioni sui libri presenti nell'archivio.
-Stampa l’archivio dei libri pubblicati in un certo anno.
-Stampa tutti i libri pubblicati in ordine di anno.
Assicurati che il programma gestisca
correttamente la memoria dinamica e che non ci siano perdite di memoria.
Inoltre, gestisci eventuali errori nell'apertura del file CSV.
Ricorda di fornire un'interfaccia utente
chiara e intuitiva per consentire all'utente di eseguire queste operazioni.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30
#define LUNG_MAX 200

typedef struct
{
    char *titolo;
    char *autore;
    int anno_uscita;
} Libreria;

int contaRighe(char riga[], Libreria libro[], int cont)
{
    int n = 0;
    FILE *fp2 = fopen("listalibri.csv", "r");
    while (fgets(riga, LUNG_MAX, fp2))
    {
        n++;
    }
    fclose(fp2);
    return n;
}

void caricaLibri(char file[LUNG_MAX], Libreria libro[], int n)
{
    
    char *campo;
    Libreria *cont = libro;
    char riga[LUNG_MAX];
    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf("impossibile aprire file!");
        exit(1);
    }
    while (fgets(riga, LUNG_MAX, fp))
    {
        campo = strtok(riga, ",");
        cont->titolo = strdup(campo);
        campo = strtok(NULL, ",");
        cont->autore = strdup(campo);
        campo = strtok(NULL, ",");
        cont->anno_uscita = atoi(campo); // atof float
        cont++;
    }
    fclose(fp);
}

void stampaLibri(Libreria libri[], int n)
{
    for (Libreria *k = libri; k < libri + n; k++)
    {
        printf("Titolo: %s Autore: %s Anno uscita: %d\n", k->titolo, k->autore, k->anno_uscita);
    }
}

void cercaAnno(Libreria libro[], int n, int anno_scelta)
{
    printf("Libri dell'anno %d \n", anno_scelta);
    for (Libreria *k = libro; k < libro + n; k++)
    {
        if (k->anno_uscita == anno_scelta)
        {
            printf("Titolo: %s Autore: %s \n", k->titolo, k->autore);
        }
    }
}

void scambio(Libreria *a, Libreria *b)
{
    Libreria c;
    c = *a;
    *a = *b;
    *b = c;
}

void ordinaLibri(Libreria libro[], int cont)
{
    Libreria *k;
    int sup, sca;
    sup = cont - 1;
    int j;
    while (sup > 0)
    {
        j = 0;
        sca = 0;
        for (k = libro; k < libro + sup; k++)
        {
            if (k->anno_uscita < (k + 1)->anno_uscita)
            {
                scambio(k, (k + 1));
                sca = j;
            }
            j++;
        }
        sup = sca;
    }
    
}

int main()
{
    Libreria *libro;
    char riga[LUNG_MAX];
    int anno_scelta;
    char file[LUNG_MAX] = "listalibri.csv";
    int n_righe = contaRighe(riga, libro, DIM);
    printf("Numero righe: %d \n", n_righe);

    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf("Impossibile aprire file");
        return -1;
    }
    fclose(fp);
    int scelta;
    libro = (Libreria *)malloc(n_righe * sizeof(Libreria));
    caricaLibri(file, libro, n_righe);
    do
    {
        printf("Cosa vuoi fare: \n");
        scanf("%d", &scelta);
        switch (scelta)
        {
            case 0:
                break;
            case 1:
                stampaLibri(libro, n_righe);
                break;
            case 2:
                printf("Inserire l'anno da cercare: \n");
                scanf("%d", &anno_scelta);
                cercaAnno(libro, n_righe, anno_scelta);
                break;
            case 3:
                ordinaLibri(libro, n_righe);
                stampaLibri(libro, n_righe);
                break;
        }
    } while (scelta != 0);
    free(libro);
    return 0;
}