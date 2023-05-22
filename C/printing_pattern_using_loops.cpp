#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n=7;
    int A[n*2-1][n*2-1];
    for (int i=0;i<=n*2-2;i++){
        for (int j=0;j<=n*2-2;j++){
            A[i][j]=0;
        }
    }
    int temp=n;
    int x=n*2-2;
  	while (1){

        for (int k=n-temp;k<=x;k++){

            for (int i=k;i<=x;i++){
                    A[k][i]=temp;
                    A[i][k]=temp;
                    A[k][x]=temp;
                    A[x][k]=temp;

            }
        }
        x--;
        temp--;
        if (temp <1) break;
     }
          
    for (int i=0;i<=n*2-2;i++){
        for (int j=0;j<=n*2-2;j++){
            printf ("%d ", A[i][j]);
        }
        printf ("\n");
    }
      
      
    return 0;
}
