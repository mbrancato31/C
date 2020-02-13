#include <stdio.h>
#include <stdlib.h>

#define TRUE (1==1)
#define FALSE (1==0)

#define SIZE 16
#define SUB_SIZE 3
#define EMPTY 0


typedef struct HAT HAT;
struct HAT {
    int v;
    int choices[3];
};

HAT hats[SIZE][SIZE];

void readBoard(int n);
void printBoard(int n);
int isValid(int);
int backTrack(int, int, int);

int main(){

    int n;
    scanf("%d", &n);
    

    readBoard(n);
    
    if (backTrack(0, 0, n))
    {
        printBoard(n);
    }
    else
    {
        printf("No Solution found.\n");
    }
    
    return 0;
}


int isValid(int n){
    int row, col, g, subRow, subCol, value;
    
    // Check each row
    for (row = 0; row < n; row++)
    {
        // Set that no value exists
        int contains[n];
        for (value = 0; value < n; value++)
        {
            contains[value] = FALSE;
        }
        
        // Loop through the row
        for (col = 0; col < n; col++)
        {
           
            // Check if a value is present
            if (hats[row][col].v != EMPTY){
                // Check if the value is already in the row
                if (contains[hats[row][col].v - 1]){
                    return FALSE;
                }
                    
                // Set the value is in the row
                contains[hats[row][col].v - 1] = TRUE;
            }
            
        }
    }
    
    // Check each column
    for (col = 0; col < n; col++)
    {
        // Set that no value exists
        int contains[n];
        for (value = 0; value < n; value++)
        {
            contains[value] = FALSE;
        }
        
        // Loop through the column
        for (row = 0; row < n; row++)
        {
           
            // Check if a value is present
            if (hats[row][col].v != EMPTY){
                // Check if the value is already in the row
                if (contains[hats[row][col].v - 1]){
                    return FALSE;
                }
                    
                // Set the value is in the row
                contains[hats[row][col].v - 1] = TRUE;
            }
            
        }
    }

    
    
    
    // No invalid row, column
    return TRUE;
}


int backTrack(int r, int c, int n)
{
    // THIS IS BACKTRACKING : Check validity
    if (!isValid(n))
    {
        return FALSE;
    }
    
    // Check if col index (c) is off the board
    if (c == n)
    {
        return backTrack(r + 1, 0, n);
    }
    
    // Check if row index (r) is off the board
    if (r == n)
    {
        return TRUE;
    }
    
    // Check if forced
    if (hats[r][c].v != 0)
    {
        return backTrack(r, c + 1,n);
    }
    
    // Try all possible decisions
    int attempt;
    for (attempt = 0; attempt < 3; attempt++)
    {
        hats[r][c].v = hats[r][c].choices[attempt];
        if (backTrack(r, c + 1,n))
            return TRUE;
        
        // Undo the choice
        hats[r][c].v = EMPTY;
    }
    
    // No solution found
    return FALSE;
}



void printBoard(int n)
{
    int i, j, g;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            printf("%d ", hats[i][j].v);
        printf("\n");
    }
}

void readBoard(int n){
    int i, j, g;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for(g = 0; g < 3; g++){
                scanf("%d", &hats[i][j].choices[g]);
                char trash;
                scanf("%c", &trash);
            }
                
}


