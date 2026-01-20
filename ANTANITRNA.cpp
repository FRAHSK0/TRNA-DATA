#include <cstdio>
#include <string.h>
float percentuale(float valore, float totale) {
    if (totale == 0.0f) {
        printf("Errore: divisione per zero!\n");
        return 0.0f;  // puoi anche gestire diversamente l'errore
    }
    return (valore / totale) * 100.0f;
}

int main() {
    const char *TTRNA[4];
    float  ATrna [64];
    float GTrna [64];
    float CTrna [64];
    float  TTrna [64];
    float TOTTRNA[64];
      
    //	Saccharomyces cerevisiae 
    TTRNA[0]="AGCGCCGTGGCGCAGTGGAAGCGCGCAGGGCTCATAACCCTGATGTCCTCGGATCGAAACCGAGCGGCGCTA";

    // pinus
    TTRNA[1]="TGCGGAGTAGAGTAGTCTGGTAGCTCGCAAGGCTCATAACCTTGAGGTCACGGGTTCAAATCCTGTCTCCGCCA";

     //	Escherichia coli 
    TTRNA[2]="CGCGGGGTGGAGCAGCCTGGTAGCTCGTCGGGCTCATAACCCGAAGGTCGTCGGTTCAAATCCGGCCCCCGCAACCA";

    //homo sapiens
     TTRNA[3]="AGTAAGGTCAGCTAAATAAGCTATCGGGCCCATACCCCGAAAATGTTGGTTATACCCTTCCCGTACTA";



  	
    // Output
    for (int j= 0; j < 4; ++j) {
         float  A=0;
         float T=0;
         float C=0;
         float G=0;
         for (int i = 0; i < strlen(TTRNA[j]); ++i) {
            char ch = TTRNA[j][i];
            if (ch == 'a' || ch == 'A') A++;
            else if (ch == 'c' || ch == 'C') C++;
            else if (ch == 'g' || ch == 'G') G++;
            else if (ch == 't' || ch == 'T') T++;
        ATrna [j]=A;
             GTrna [j]=G;
                  CTrna [j]=C;
                       TTrna [j]=T;
                  TOTTRNA [j]=ATrna[j]+CTrna[j]+TTrna[j]+GTrna[j];          

    }

    }
      //printf("MET TRNA Saccharomyces cerevisiae lunghezza:%f percentuale di A:%f percentuale di C:%f percentuale di T:%f percentuale di G:%f \n",TOTTRNA[0],percentuale(ATrna[0],TOTTRNA[0]),percentuale(CTrna[0],TOTTRNA[0]),percentuale(TTrna[0],TOTTRNA[0]),percentuale(GTrna[0],TOTTRNA[0]));
      //printf("MET TRNA pinus lunghezza:%fpercentuale di A:%f percentuale di C:%f percentuale di T:%f percentuale di G:%f \n",TOTTRNA[1], percentuale(ATrna[1], TOTTRNA[1]), percentuale(CTrna[1], TOTTRNA[1]), percentuale(TTrna[1], TOTTRNA[1]), percentuale(GTrna[1], TOTTRNA[1]));
      //printf("MET TRNA Escherichia coli lunghezza:%f percentuale di A:%f percentuale di C:%f percentuale di T:%f percentuale di G:%f\n",TOTTRNA[2], percentuale(ATrna[2], TOTTRNA[2]), percentuale(CTrna[2], TOTTRNA[2]), percentuale(TTrna[2], TOTTRNA[2]), percentuale(GTrna[2], TOTTRNA[2]));
      //printf("MET TRNA Homo sapiens lunghezza:%f percentuale di A:%f percentuale di C:%f percentuale di T:%f percentuale di G:%f\n",TOTTRNA[3], percentuale(ATrna[3], TOTTRNA[3]), percentuale(CTrna[3], TOTTRNA[3]), percentuale(TTrna[3], TOTTRNA[3]), percentuale(GTrna[3], TOTTRNA[3]));
      
const char* specie[] = {
    "Saccharomyces cerevisiae",
    "Pinus",
    "Escherichia coli",
    "Homo sapiens"
};

for (int i = 0; i < 4; i++) {
    printf(
        "MET TRNA %s lunghezza: %.0f\n"
        "percentuale di A: %.1f%%\n"
        "percentuale di C: %.1f%%\n"
        "percentuale di T: %.1f%%\n"
        "percentuale di G: %.1f%%\n\n",
        specie[i],
        TOTTRNA[i],
        percentuale(ATrna[i], TOTTRNA[i]),
        percentuale(CTrna[i], TOTTRNA[i]),
        percentuale(TTrna[i], TOTTRNA[i]),
        percentuale(GTrna[i], TOTTRNA[i])
    );
}

    


    return 0;
}
