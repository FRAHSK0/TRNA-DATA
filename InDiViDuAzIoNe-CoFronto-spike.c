#include <stdio.h>
#include <string.h>
#define MAX_GENOME 30000
#define MAX_LINE   1024
int main(void) {
    FILE *FILEWUHAN1 = fopen("WUHAN-1.fasta", "r");//APERTURA FILE COVID WUHAN
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
  FILE *FILEFRIULI= fopen("FRIULI.fasta", "r");//APERTURA FILE FRIULI
    if (FILEFRIULI == NULL) {
        perror("Errore apertura file");
        return 1;
    }
    char FRIULI[MAX_GENOME + 1];  // +1 per '\0'

    char lineFriuli[MAX_LINE];
        int lenfriuli = 0;

    while (fgets(lineFriuli, MAX_LINE, FILEFRIULI)) {   // MESSO IL FILE NELL'ARRAY

        // Salta intestazione
        if (lineFriuli[0] == '>') continue;

        // Rimuove newline
        lineFriuli[strcspn(lineFriuli, "\n")] = '\0';

        // Copia caratteri uno a uno
        for (int i = 0; lineFriuli[i] != '\0'; i++) {
            if (lenfriuli < MAX_GENOME) {
                FRIULI[lenfriuli] = lineFriuli[i];
                lenfriuli++;
            }
        }
    }

    FRIULI[lenfriuli] = '\0';
   fclose(FILEFRIULI); // CHIUSURA FILE 
   printf("Lunghezza del genoma WUHAN-1: %d basi\n", len);
   printf("Lunghezza del genoma FRIULI: %d basi\n", lenfriuli); 
   int spike_start = 21563; // in ref
   int spike_end   = 25384; // in ref


char rif_spike[3823];   // Array per la sequenza spike di wuhan 1
for(int i=spike_start; i<spike_end+1; i++) {
    rif_spike[i-spike_start] = WUHAN1[i];
}
rif_spike[3822] = '\0'; // Aggiungi terminatore di stringa

int best_score = -1;
int best_pos   = -1;
int score ;
for (int i = 0; i < lenfriuli-3822 ; i++) {

    score = 0;
    for (int j = 0; j < 3822; j++) {
        if (FRIULI[i+j] == rif_spike[j]) 
        score++;
    }
    if (score > best_score) {
        best_score = score;
        best_pos = i;
    }
}

int corrected_spike_start = best_pos;   
int corrected_spike_end   = best_pos + 3822 - 1;
printf("La sequenza spike in FRIULI inizia a: %d e termina a: %d\n", corrected_spike_start, corrected_spike_end);


printf("\nLunghezza della sequenza spike: %zu basi\n", strlen(rif_spike));
int differences = 0;
for (int i = 0; i < 3822; i++) {
    if (rif_spike[i] != FRIULI[corrected_spike_start + i]) {
        differences++;
    }
}

printf("Numero di differenze nella sequenza spikee: %d\n", differences);





    return 0;

}