/*verifica*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30
#define LUNG_MAX 200

typedef struct
{
    char *data;
    char *cognome;
    int versati;
} Struttura;

typedef struct{
    char *cognome;
    int quota;
}Totale;


int contaRighe(char riga[], Struttura tabella[], int cont)
{
    int n = 0;
    FILE *fp2 = fopen("4AROB_GITA.csv", "r");
    while (fgets(riga, LUNG_MAX, fp2))
    {
        n++;
    }
    fclose(fp2);
    return n;
}

void caricaTabella(char file[LUNG_MAX], Struttura tabella[], int n)
{
    
    char *campo;
    Struttura *cont = tabella;
    char riga[LUNG_MAX];
    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf("impossibile aprire file!");
        exit(1);
    }
    while (fgets(riga, LUNG_MAX, fp))
    {
        campo = strtok(riga, ";");
        cont->data = strdup(campo);
        campo = strtok(NULL, ";");
        cont->cognome = strdup(campo);
        campo = strtok(NULL, ";");
        cont->versati = atoi(campo); // atof float
        cont++;
    }
    fclose(fp);
}

void stampaTabella(Struttura tabella[], int n)
{
    for (Struttura *k = tabella; k < tabella + n; k++)
    {
        printf("%s ha versato %d euro\n", k->cognome, k->versati);
    }
}

void controlloPagamenti(Struttura tabella[], int n){
    int pagatoTot=2200;
    for (Struttura *k = tabella; k < tabella + n; k++)
    {
        pagatoTot=pagatoTot-k->versati;
    }
    if(pagatoTot==2200){
        printf("versamenti completati");
    }else{
        if(pagatoTot<2200)
            printf("mancano %d euro di versamenti",pagatoTot);
        else
            printf("errore nei pagamenti(troppi soldi)");
    }
}

void totaleSingolo(Struttura tabella[], Totale totalepers[], int n){
    int pagatoTot=0;
    Totale *j;
    for (Struttura *k = tabella; k < tabella + n; k++)
    {
        j->cognome=k->cognome;
        j->quota=k->versati;
    }
    for (Totale *k = totalepers; k < totalepers + n; k++)
    {
        if( k->quota==100){
            printf("%s ha pagato tutto", k->cognome);
        }else{
            if(k->quota<100){
                printf("%s deve ancora pagare %d euro", k->cognome, 100-k->quota);
            }else{
                printf("a %s dovranno essere restituiti %d euro", k->cognome, k->quota-100);
            }
        }
       
    
    if(pagatoTot==2200){
        printf("versamenti completati");
    }else{
        if(pagatoTot<2200)
            printf("mancano %d euro di versamenti", 2200-pagatoTot);
        else
            printf("errore nei pagamenti(troppi soldi)");
    }
    }
}

int main()
{
    Struttura *tabella;
    Totale *totalepers;
    char riga[LUNG_MAX];
    char file[LUNG_MAX] = "4AROB_GITA.csv";
    int n_righe = contaRighe(riga, tabella, DIM);
   
    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf("Impossibile aprire file");
        return -1;
    }
    fclose(fp);
    int scelta;
    tabella = (Struttura *)malloc(n_righe * sizeof(Struttura));
    totalepers = (Totale *)malloc(n_righe * sizeof(Totale));
    caricaTabella(file, tabella, n_righe);
    do
    {
        printf("scelta1: valore totale\n");
        printf("scelta2: verifica pagamenti\n");
        printf("scelta3: quadro generale\n");
        printf("Cosa vuoi fare: \n");
        scanf("%d", &scelta);
        switch (scelta)
        {
            case 0:
                break;
            case 1:
                controlloPagamenti(tabella, n_righe);
                break;
            case 2:
                totaleSingolo(tabella, totalepers, n_righe);
                break;
            case 3:
                stampaTabella(tabella, n_righe);
                break;
        }
    } while (scelta != 0);
    free(tabella);
    return 0;
}