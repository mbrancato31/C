#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FLUSH myFlush() // clears the keyboard buffer

typedef struct Strudents_t{
    char name[100+1];
    char sym[100+1];
    
}Strudents_t;

void myFlush();
void update(Strudents_t *student, int i);
void query(Strudents_t *student, int size);

int main(){

    int n, size = 0;
    char decision;
    scanf("%d", &n);
    Strudents_t student[1000+1];
    
    
    for(int i = 0; i < n; i++){
        FLUSH;
        scanf("%c", &decision);

        if(decision =='u'){
            update(student, i);
            size++;
        }else if(decision == 'q'){
            query(student, size);
        }


    }





    return 0;
}

 void update(Strudents_t *student, int i){
     
     scanf("%s", student[i].name);
     scanf("%s", student[i].sym);
     
 }
 void query(Strudents_t *student, int size){
    char choice[100+1];
    char word[100+1];
    

    scanf("%s", choice);
    scanf("%s", word);

    if(strcmp(choice, "student")==0){
        int times = 0;

        for(int j = 0; j < size; j++){
            if(strcmp(word, student[j].name) == 0){
                times++;
            }
        }
        printf("%d\n", times);
        for(int j = 0; j < size; j++){
            if(strcmp(word, student[j].name) == 0){
                printf("%s\n", student[j].sym);
            }
        }

    }else if(strcmp(choice, "symptom")==0){
         int times = 0;

        for(int j = 0; j < size; j++){
            if(strcmp(word, student[j].sym) == 0){
                times++;
            }
        }
        printf("%d\n", times);
        for(int j = 0; j < size; j++){
            if(strcmp(word, student[j].sym) == 0){
                printf("%s\n", student[j].name);
            }
        }


        

    }

     
 }

 
void myFlush() {
	while (getchar() != '\n');
} // end myFlush