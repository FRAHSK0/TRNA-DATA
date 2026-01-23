#include <stdio.h>
#include <string.h>

#define MAX_GENOME 30000
#define MAX_LINE   1024
int base_to_int(char b) {
    switch (b) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;   
        default:  return -1;  
    }
}

int main(void) {
     int freq[64] = {0};// dichiaraziuone di un array di frequenze per contare le triplette 
     int max = 0;
    int max_idx = 0;

 char bases[] = {'A','C','G','T'};

    FILE *WUHAN = fopen("WUHAN-1.fasta", "r");
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

     for (int i = 0; i <len - 2; i=i+3) {  
        int a = base_to_int(PRIMOCOVID[i]);
        int b = base_to_int(PRIMOCOVID[i+1]);
        int c = base_to_int(PRIMOCOVID[i+2]);

        int idx = a * 16 + b * 4 + c;
        int count = ++freq[idx];

        if (count > max) {
            max = count;
            max_idx = idx;
        }

    }


   

    printf("Genoma letto è composto da %d basi)\n", len);
    printf ("A: %d (%.2f%%)\n", A, (A / (float)len) * 100.0f);
    printf ("C: %d (%.2f%%)\n", C, (C / (float)len) * 100.0f);
    printf ("G: %d (%.2f%%)\n", G, (G / (float)len) * 100.0f);
    printf ("T: %d (%.2f%%)\n", T, (T/ (float)len) * 100.0f);  

   

    printf("Tripletta più frequente: %c%c%c (%d volte)\n",
           bases[max_idx / 16],
           bases[(max_idx / 4) % 4],
           bases[max_idx % 4],
           max);
 
   for(int j=0;j<4;j++){
    for(int k=0;k<4;k++){
        for(int l=0;l<4;l++){
            int index = j*16 + k*4 + l;
            printf("%c%c%c: ", bases[j], bases[k], bases[l]);
            for(int m=0; m < freq[index]/10; m++)  // scala
                printf("|");
            printf(" (%d)\n", freq[index]);
        }
    }
}






    return 0;
}