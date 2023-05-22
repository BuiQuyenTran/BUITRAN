#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
    int i=n-1;
    //Kiem tra xem co thang nao nho hon ma dung truoc khong, cac ptu se sx dan theo tt tu lon den be
    while (i>0 && strcmp (s[i-1], s[i])>=0){
        i--;
    }
    
    if (i<=0) return 0;//khong con truong hop nao
    
    int j=n-1;
    // ptu i-1 be hon ptu j thi doi 
    while (strcmp (s[i-1], s[j])>=0){
        j--;
    }
    //tim phan tu goc moi (i-1)
    char *tmp =s[i-1];
    s[i-1]=s[j];
    s[j]=tmp;
    j=n-1;
    // sap xep lai chuoi tu ptu i->cuoi la giam dan
    while (i<j){
        tmp =s[i];
        s[i]=s[j];
        s[j]=tmp;
        i++;
        j--;
    }
    
    
	return 1;
}

int main()
{
	char **s;
	int n;
	freopen ("permutations_of_string.txt", "r", stdin);
	scanf("%d", &n);
	s = (char**) calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = (char*) calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}