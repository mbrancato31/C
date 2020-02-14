
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FRUITS   7
#define BUY_AMOUNT   3

int threeSetCount;

// Prototype for our recursive combination finder; Note buy index and number of Fruit will count down.
void combinations(char ** fruits, int * current, int curFruit, int buyIndex);
int combinationCount (int options, int spots);
int factorial (int n);

int main(){
    char * fruitNames[NUM_FRUITS] = {"apples", "grapes", "oranges", "grapefruit", "kiwi", "tomatoes", "bananas"};
    int * lockedChoices = (int *) calloc(BUY_AMOUNT, sizeof(int)); // Which indices have been selected
    int       i;
    
    threeSetCount = 0;
    
    // Create memory and initialize memory ( Maybe do this with input files and loops in the lab)
    /*char **   frNames;  // The set of fruit names
    frNames = (char **) calloc(NUM_FRUITS, sizeof(char *));

    frNames[0] = (char *) calloc(strlen("apples"), sizeof(char));
    strcpy(frNames[0], "apples");
    frNames[1] = (char *) calloc(strlen("grapes"), sizeof(char));
    strcpy(frNames[1], "grapes");
    frNames[2] = (char *) calloc(strlen("oranges"), sizeof(char));
    strcpy(frNames[2], "oranges");
    frNames[3] = (char *) calloc(strlen("grapefruit"), sizeof(char));
    strcpy(frNames[3], "grapefruit");
    frNames[4] = (char *) calloc(strlen("kiwi"), sizeof(char));
    strcpy(frNames[4], "kiwi");
    frNames[5] = (char *) calloc(strlen("tomatoes"), sizeof(char));
    strcpy(frNames[5], "tomatoes");
    frNames[6] = (char *) calloc(strlen("bananas"), sizeof(char));
    strcpy(frNames[6], "bananas");*/

    printf("We have %d fruit options and need to choose %d to buy. Combinations: %d.\n", NUM_FRUITS, BUY_AMOUNT, combinationCount(NUM_FRUITS,BUY_AMOUNT));

    for (i = 0; i < BUY_AMOUNT; i++)
        lockedChoices[i] = -1;//nothing has been selected for purchase yet
    
    combinations(fruitNames, lockedChoices, 0, BUY_AMOUNT);// Run the recursive method
    
    free(lockedChoices);
    return EXIT_SUCCESS;
}

void combinations(char ** fruitNames, int * lockedChoices, int fruitIndex, int leftToBuy){
    int i;
    
    if (leftToBuy == 0) {// Check if we bought enough fruit
        
        printf("%d.", ++threeSetCount);// Print and update the lockedCount
        for (i = BUY_AMOUNT - 1; i >= 0; i--)// Print string in reverse order to get the correct order...
            printf(" %s", fruitNames[lockedChoices[i]]);
        printf("\n");
        
        return;//no recursion for base case
    }
    
    if (fruitIndex == NUM_FRUITS)// Check if there is no more fruit to choose from
        return; // if we got here, means we couldn't buy enough with the rejections we made along the way... 
    
    //--------- TO BUY OR NOT TO BUY... THAT IS THE QUESTION... ------------------
    //lock in this choice and buy it
    lockedChoices[leftToBuy-1] = fruitIndex;
    combinations(fruitNames, lockedChoices, fruitIndex+1, leftToBuy-1);// BUY IT (1 less to consider, 1 less to buy)
    //undo locking in this choice and don't buy it
    lockedChoices[leftToBuy-1] = -1;
    combinations(fruitNames, lockedChoices, fruitIndex+1, leftToBuy);// DON'T BUY IT (1 less to consider, same left to buy)

}

int combinationCount (int options, int spots){

    if (options == 0)
        if (spots == 0)
            return 1;//there's one way to choose none out of zero options
        else
            return 0;//there are no ways to choose more than none out of zero options

    int combinations = 1;
    for (int spot=0; spot<spots; spot++){
        combinations *= options;
        options--;
    }
    int orderings = factorial(spots);
    return combinations/orderings;//we are overcounting by order
}

int factorial (int n){
    if (n==0)
        return 1;
    if (n<3)//1!=1, 2!=2
        return n;

    return n*factorial(n-1);
}