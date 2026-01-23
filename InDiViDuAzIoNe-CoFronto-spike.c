#include <stdio.h>
#include <string.h>
#define MAX_GENOME 30000
#define MAX_LINE   1024
int main(void) {
     FILE *FILEWUHAN1 = fopen("WUHAN-1.fasta", "r");//APERTURA FILE
    if (FILEWUHAN1 == NULL) {
        perror("Errore apertura file");
        return 1;
    }
    char WUHAN1[MAX_GENOME + 1];  // +1 per '\0'

    char line[MAX_LINE];
        int len = 0;

    while (fgets(line, MAX_LINE, FILEWUHAN1)) {   // MESSO IL FILE NELL'ARRAY

        // Salta intestazione
        if (line[0] == '>') continue;

        // Rimuove newline
        line[strcspn(line, "\n")] = '\0';

        // Copia caratteri uno a uno
        for (int i = 0; line[i] != '\0'; i++) {
            if (len < MAX_GENOME) {
                WUHAN1[len] = line[i];
                len++;
            }
        }
    }

    WUHAN1[len] = '\0';
    fclose(FILEWUHAN1); // CHIUSURA FILE

char rif_spike[3823];   // Array per la sequenza spike
for(int i=21563, j=0; i<25385 && j<3822; i++, j++) {
    rif_spike[j] = WUHAN1[i];
}
rif_spike[3822] = '\0'; // Aggiungi terminatore di stringa

printf("\nLunghezza della sequenza spike: %d basi\n", strlen(rif_spike));   















    return 0;

}