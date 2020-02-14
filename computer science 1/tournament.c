#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("hhhh");

    int n;
    int preOrder[10];
    int postOrder[10];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &postOrder[i]);
        char temp;
        scanf("%c", &temp);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &preOrder[i]);
        char temp;
        scanf("%c", &temp);
    }

    for(int i = 0; i < n; i++){
        printf("%d", preOrder[i]);
    }

}