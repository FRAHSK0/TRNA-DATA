#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MATCH 1
#define MISMATCH -1
#define GAP -2
int max(int z, int z1, int z3) {
    int m = z;

    if (z1 > m)
        m = z1;
    if (z3 > m)
        m = z3;

    if (m < 0)
        return 0;
    else 
    return m;
}



int main() {

    int  matrice[5][6]= {0}; 
    char Genoma[6]={ 'Z','A','T','G','C','T'};
    char Spike[5]={'z','A','G','C','T'};
    
for(int riga=1 ;riga<5;riga=riga+1){ 

    for(int colonna=1 ;colonna<6;colonna=colonna+1){ 
    int z=0;
    int z1=0;
    int z2=0;
    int z3=0;
    z=matrice[riga][colonna-1]+GAP*riga;
    z1=matrice[riga-1][colonna]+GAP*colonna;
 
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
    matrice[riga][colonna]=max(z1,z,z3);
        


    }

}
 for (int riga= 0; riga <5; riga++) {
  printf("\n");
for (int colonna= 0; colonna <6; colonna++) {
  printf ("%d",matrice[riga][colonna]);
}

}    

}