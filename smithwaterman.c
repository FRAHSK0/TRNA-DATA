#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
   
    int matrice[22][193] = {0};   

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
    printf("missmatch in posizione %d \n",y);
        
}
else if(maxm==R1) {
y=y;
x=x-1;   
printf("delezione rispetto alla spike in posizione %d \n", y);
}
else if(maxm==R3) {
y=y-1;
x=x;   
printf("inserzione rispetto alla spike in posizione %d \n", y);
}


} while(matrice[x][y]!=0);

printf( "la spike inzia in posizione %d , e finisce in posizone %d\n",y+1, Fine );



}    




int main() {

   char Genoma[] ={'Z','A','T','G','C','G','T','A','C','G','T','T','A','G','C','T','A','G','C','T','G','A','T','C','G','A','T','C','G','A','T','G','C',
'T','A','G','C','T','A','G','G','C','T','A','A','C','G','T','T','A','G','C','T','A','G','C','T','G','A','C','T','G','A','T','C',
'G','T','T','G','A','C','C','A','T','G','G','C','C','A','T','T','G','T','A','A','T','G','G','G','C','C','G','C','T','G','A','A',
'A','G','G','G','T','G','C','C','C','G','A','T','A','G','C','T','A','G','C','T','A','G','C','T','G','A','T','C','G','A','T','C',
'G','A','T','G','G','C','T','G','C','T','G','C','T','G','A','A','C','T','G','A','C','C','G','T','G','A','A','T','T','C','G','C',
'T','A','G','C','T','A','G','C','T','A','G','C','T','A','A','C','T','G','A','T','C','G','T','A','C','G','A','T','C','G','T','A',
'A'
};
    char Spike[] = {'Z','A','T','G','G','C','T','A','T','T','G','T','T','A','T','G','G','G','T','C','G','T'};

    int righe =22;
    int colonne=193;
    smithwatermanmatrix(Genoma,Spike,colonne,righe);
    

    
    
return 0;

          
}
 
