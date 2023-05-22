#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char *s; 
    s= (char*)malloc (100*sizeof (char));\
    freopen ("digits_frequency.txt", "r", stdin);
    scanf ("%s", s);
    int A[10]; 
    for (int i=0;i<10;i++){
        A[i]=0;
    }
    for (int i=0;i<strlen (s);i++){
        for (int j=0;j<10;j++){
            if (j== (int) s[i]-48)
                A[j]++;
        }
        
    }
    for (int i=0;i<10;i++){
        printf ("%d ", A[i]);
    }
    
    return 0;
}
