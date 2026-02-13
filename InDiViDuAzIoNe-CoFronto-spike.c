#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GENOME 30000
#define MAX_LINE   1024

#define MATCH 1
#define MISMATCH -1
#define GAP -2


int max(int z, int z1, int z3) {
    int m;
    m=z;
    if (z1 > m)
        m = z1;
    if (z3 > m)
        m = z3;

    if (m < 0) 
        return 0;
        

    else  
    return m;
    

}

void smithwatermanmatrix(char Genoma[], char Spike [],int colonne , int righe ) {
   int **matrice = malloc(righe * sizeof(int *));
if (matrice == NULL) {
    printf("Errore di allocazione matrice righe\n");
    exit(1);
}

// Alloca ogni riga
for (int i = 0; i < righe; i++) {
    matrice[i] = calloc(colonne, sizeof(int));  // inizializza a 0
    if (matrice[i] == NULL) {
        printf("Errore di allocazione matrice colonna\n");
        exit(1);
    }
}

       

for(int riga=1 ;riga<righe;riga=riga+1){ 

    for(int colonna=1 ;colonna<colonne;colonna=colonna+1){ 
    int z=0;
    int z1=0;
    int z2=0;
    int z3=0;
    //W=Gopen​+(n−1)⋅Gextension​
    z=matrice[riga][colonna-1]+GAP;
    z1=matrice[riga-1][colonna]+GAP;
 
        if(Genoma[colonna]==Spike[riga]) {
        z2=MATCH;
        }
        else {
        z2=MISMATCH;
        }
    z3=matrice[riga-1][colonna-1]+z2;
        if(z<0) {
        z=0;
        }
        if(z1<0) {
        z1=0;
        }
        if(z3<0) {
        z3=0;
        }
    matrice[riga][colonna]=max(z,z1,z3);
}

} 
int massimo =0;
int x=0;
int y=0;
        
for (int riga= 0; riga <righe; riga++) {
  
for (int colonna= 0; colonna <colonne; colonna++){
if (matrice[riga][colonna]>massimo) {
    massimo=matrice[riga][colonna];
    x=riga;
    y=colonna;
    }
  
}
 
}    

  printf ("il massimo è %d, è in posizione riga %d colonna %d \n",massimo,x, y);  
int Fine;
Fine=y;
int msm=0;
int gapsd=0;
int gapsi=0;
do {

int maxm=0;
int R=0;
int R1 =0;
int R3=0;
R=matrice[x-1][y-1];
R1=matrice[x-1][y];
R3=matrice[x][y-1];
maxm=max(R,R1,R3);
if(maxm==R) {
y=y-1;
x=x-1;
  if(Genoma[y]!=Spike[x]) 
     msm=msm+1;
    //printf("missmatch in posizione %d \n",y);
        
}
else if(maxm==R1) {
    gapsd=gapsd+1;
y=y;
x=x-1;   
//printf("delezione rispetto alla spike in posizione %d \n", y);
}
else if(maxm==R3) {
    gapsi=gapsi+1;
y=y-1;
x=x;   
//printf("inserzione rispetto alla spike in posizione %d \n", y);
}


} while(matrice[x][y]!=0);

printf( "la spike inzia in posizione %d , e finisce in posizone %d ci sono %d mismatch %d inserzioni e %d delezioni \n",y+1,Fine,msm, gapsi, gapsd );
printf("la spike è lunga %d basi",Fine-(y+1));
for (int i = 0; i < righe; i++) {
    free(matrice[i]);
}
free(matrice);



}    



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
printf("\nLunghezza della sequenza spike di WUHAN 1 è: %zu basi \n", strlen(rif_spike));


// Spike con 'Z' iniziale
char rif_spike_Z[3823];
rif_spike_Z[0] = 'Z';
for(int i = 0; i < 3822; i++) {
    rif_spike_Z[i+1] = rif_spike[i];
}
char FRIULI_Z[lenfriuli + 1];  // +1 per 'Z'

FRIULI_Z[0] = 'Z';  // primo elemento = Z

// Copia il resto del genoma
for (int i = 0; i < lenfriuli; i++) {
    FRIULI_Z[i + 1] = FRIULI[i];
}


       int righe=3823;
       int colonne=29751;
       smithwatermanmatrix(FRIULI_Z,rif_spike_Z,colonne, righe);



    return 0;

}