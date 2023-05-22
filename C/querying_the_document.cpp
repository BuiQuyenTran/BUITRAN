#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
    
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}
// char** split_string (char *text, char delim){
//     char** result= (char**) malloc (sizeof (char*));
//     int size=1;
//     char *temp = strtok (text, &delim);
//     *result=temp;
//     while (temp !=NULL){
//         size++;
//         result= (char**) realloc (result, size* sizeof (char*));
//         temp= strtok (NULL, &delim);
//         result[size-1]=temp;
        
//     }
//     return result;
// }


// char**** get_document(char* text) {
//     char **paragraphs= split_string(text, '\n');
//     int npar=0;
//     while (paragraphs[npar]!=NULL){
//         npar++;
//     }
//     char**** doc = (char****) malloc ((npar+1) *sizeof (char***));

//     doc[npar]=NULL;
//     int i=0;
//     while (paragraphs[i]!=NULL){
//         char **sentences = split_string(text, '.');
//         int nsen=0;
//         while (sentences[nsen]!=NULL){
//             nsen++;
//         }
        
//         doc [i]= (char***) malloc ((nsen +1)* sizeof (char**));
//         doc[i][nsen]=NULL;
//         int j=0;
//         while (sentences[j]!=NULL){
//             doc[i][j]= split_string(sentences[j], ' ');
//             j++;
            
//         }
//         i++;
        
//     }
//     return doc;
    

// }
char **** get_document (char * text){
    char ****doc= (char****) malloc (MAX_PARAGRAPHS *sizeof (char ***));
    for (int i=0;i<MAX_PARAGRAPHS;i++){
        doc[i]= (char***)malloc (sizeof (char**));
    }
    for (int i=0;i<MAX_PARAGRAPHS;i++){
        //for (int j=0;j<1;j++){
            doc[i][0]=(char**) malloc (sizeof (char*));
        //}
    }
    for (int i=0;i<MAX_PARAGRAPHS;i++){
        for (int j=0;j<1;j++){
            for (int k=0;k<1;k++){
                doc[i][j][k]= (char*)malloc (sizeof (char));
            }
        }
    }
    for (int n=0, i=0, j=0, k=0, l=0; n<strlen (text);n++){
        if (text[n]!=' ' && text[n]!='\n' && text[n] !='.'){
            doc[i][j][k][l]=text[n];
            l++;
            doc[i][j][k]= (char*)realloc (doc[i][j][k], (l+1) * sizeof (char));
        }
        else if (text[n]==' '){
            doc[i][j][k][l]='\0';
            l=0;
            k++;
            doc[i][j]= (char**)realloc (doc[i][j], (k+1)* sizeof (char*));
            doc[i][j][k]= (char*)malloc (sizeof (char));
            continue;
        }
        else if (text[n]=='.'){
            doc[i][j][k][l]='\0';
            k=l=0;
            j++;
            doc[i]= (char***)realloc (doc[i], (j+1)* sizeof (char**));
            doc[i][j]= (char**)malloc (sizeof (char*));
            doc[i][j][k]= (char*)malloc (sizeof (char));
            continue;

        }
        else if (text[n]=='\n'){
            j=k=l=0;
            i++;
            continue;
        }
    }
    return doc;
}



char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);
    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    freopen ("querying_the_document.txt", "r", stdin);
    char* text = get_input_text();
    char**** document = get_document(text);
   //  char*** paragraph= (char***) malloc ( sizeof (char**));
   //  paragraph=kth_paragraph (document, 1);
   // /print_paragraph (paragraph);
    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);
        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}