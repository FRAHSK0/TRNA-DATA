#include <stdio.h>
#include <string.h>

#define MAX_GENOME 30000
#define MAX_LINE   1024

int main(void) {
    FILE *WUHAN = fopen("PRIMO SEQUENZIAMENTO.fasta", "r");
    if (WUHAN == NULL) {
        perror("Errore apertura file");
        return 1;
    }

    char PRIMOCOVID[MAX_GENOME + 1];  // +1 per '\0'
    char line[MAX_LINE];
    int A=0;
    int C=0;
    int G=0;
    int T=0;
    
    int len = 0;

    while (fgets(line, MAX_LINE, WUHAN)) {

        // Salta intestazione
        if (line[0] == '>') continue;

        // Rimuove newline
        line[strcspn(line, "\n")] = '\0';

        // Copia caratteri uno a uno
        for (int i = 0; line[i] != '\0'; i++) {
            if (len < MAX_GENOME) {
                PRIMOCOVID[len] = line[i];
                len++;
            }
        }
    }

    PRIMOCOVID[len] = '\0';
    fclose(WUHAN);
    for (int i = 0; i < len; i++) {
       if (PRIMOCOVID[i]=='A') {
           A++;
        }
         else if (PRIMOCOVID[i]=='C') {
              C++;
         }
         else if (PRIMOCOVID[i]=='G') {
              G++;
            }
         else if (PRIMOCOVID[i]=='T') {
              T++;
         }
    }

    printf("Genoma letto è composto da %d basi)\n", len);
    printf ("A: %d (%.2f%%)\n", A, (A / (float)len) * 100.0f);
    printf ("C: %d (%.2f%%)\n", C, (C / (float)len) * 100.0f);
    printf ("G: %d (%.2f%%)\n", G, (G / (float)len) * 100.0f);
    printf ("T: %d (%.2f%%)\n", T, (T/ (float)len) * 100.0f);  

    

    return 0;
}