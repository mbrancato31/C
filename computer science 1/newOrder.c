#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
struct Node {
    char value[100 + 1];
    Node * nextPtr;
};

Node * add2end(Node * front, Node * end, char value[100 + 1]);
Node * add2front(Node * front, char value[100 + 1]);
Node * newOrderlist(char order[26 + 1], Node * front, Node * end, int n, int letterPos);
void realOrder(char similarNames[10000][100], int count, char order[26 + 1], int count3, int similarNamesIndex);
void printList(Node * someNode);

int main(){
    int i, n;
    char order[26+1], trash;

    //gets the order of the alphabet
    for(i = 0; i < 26; i++){
        scanf("%c", &order[i]);
        scanf("%c", &trash);// for space
    }

    //gets number of cases
    scanf("%d", &n);

    // Make the original list empty
    Node * front = NULL;
    Node * end = NULL;
    
    // Add values
    for (i = 0; i < n; i++)
    {

        char value[100 + 1];
        scanf("%s", value);
       
        // Set the front to the new head (important if the list was empty)
        front = add2end(front, end, value);
            
        // Set the end to front if the list was originally empty
        if (end == NULL)
        {
            end = front;
        }
        
        //(list not empty) AND (end is not actually end)
        while (end != NULL && end->nextPtr != NULL)
        {
            // Walk the end pointer to the actual end
            end = end->nextPtr;
        }
    }

    front = newOrderlist(order, front, end, n, 0);
    
    // Print the list
    //printList(front);

   
    

// Delete the memory
    while (front != NULL)
    {
        // Capture the address of the second node in the list
        Node * nextFront = front->nextPtr;
        
        // Free the front since we have the next pointer captured
        free(front);
        
        front = nextFront;
    }

}// end main

///////////////// new order list /////////////////////////////////////////////////////

Node * newOrderlist(char order[26 + 1], Node * front, Node * end, int n, int letterPos){
    
    // run the order
    for(int i = 0; i < 26; i++){

        int count = 0;
        Node * tempFront = front;
        //store names with similar letters
        char similarNames[10000][100];
        //char temp[10000][100];
        for(int j = 0; j < n; j++){

            if(order[i] == tempFront->value[0]){

                strcpy(similarNames[count], tempFront->value);
                count++;

            }
                
            tempFront = tempFront->nextPtr;

            
        }

        // order the ones that have same letters
        if(count > 1){
            
            realOrder(similarNames, count, order, 0, 0);
            
        }else if (count == 1){
            printf("%s\n", similarNames[0]);
            
        }

        
    }


    return front;
}

///////////////// add end ////////////////////////////////////////////////////////////

Node * add2end(Node * front, Node * end, char value[100 + 1])
{
    // Create front
    Node * frontReturn = front;
    
    // Find the last node in our list
    Node * lastNode = end;
    while (lastNode != NULL && lastNode->nextPtr != NULL)
    {
        lastNode = lastNode->nextPtr;
    }
    
    // Check if the list was empty
    if (front == NULL)
    {
        // The list is empty 
        // make the new node the last node
        lastNode = (Node *) calloc(1, sizeof(Node));
        frontReturn = lastNode;
    }
    else
    {
        // Make this new node the node after the last one
        lastNode->nextPtr = (Node *) calloc(1, sizeof(Node));
        
        // Update the last pointer
        lastNode = lastNode->nextPtr;
    }
    
    // Update the values for this new last node
    lastNode->nextPtr = NULL;
    strcpy(lastNode->value, value);
    
    
    // Return the expected front node
    return frontReturn;
}

////////////////// add front ///////////////////////////////////////////////

Node * add2front(Node * front, char value[100 + 1])
{
    // Make the new front node
    Node * newFront = (Node *) calloc(1, sizeof(Node));
    newFront->nextPtr = front;
    strcpy(newFront->value, value);
   
    
    // Return the new front
    return newFront;
}

////////////////// print list /////////////////////////////////////////////////

void printList(Node * someNode)
{
    // Base case
    if (someNode == NULL)
    {
        //printf("NULL\n");
        return;
    }
    
    // Recursive statement
    printf("%s \n", someNode->value);
    printList(someNode->nextPtr);
}

//////////////// real order /////////////////////////////////////////////////////

void realOrder(char similarNames[10000][100], int count, char order[26 + 1], int count3, int similarNamesIndex){

    similarNamesIndex++;
    for(int i = 0; i < 26; i++){
        
        count3 = 0;
        

        for(int j = 0; j < count; j++){


            if(order[i] == similarNames[j][similarNamesIndex]){
//printf("1.  i:%d, o:%c, sm[j]:%s, sm[c3]:%s, c:%d, c3:%d \n", similarNamesIndex, order[i], similarNames[j],similarNames[count3], count, count3);

                if(strcmp(similarNames[count3], similarNames[j]) == 0){
                    strcpy(similarNames[count3],similarNames[j]);
                }else if(strcmp(similarNames[count3], similarNames[j]) != 0){
                    char tmpName[100];
                    strcpy(tmpName, similarNames[count3]);
                    strcpy(similarNames[count3],similarNames[j]);
                    strcpy(similarNames[j],tmpName);
                    

                }

//printf("2.  i:%d, o:%c, sm[j]:%s, sm[c3]:%s, c:%d, c3:%d \n", similarNamesIndex, order[i], similarNames[j],similarNames[count3], count, count3);                
                count3++;

            }

        }    

        if(count3 > 1){
//printf("%d\n", count3);            
            realOrder(similarNames, count3, order, 0, similarNamesIndex);
            
        }else if(count3 == 1){
            printf("%s\n", similarNames[0]);
        }      
            
        
        

              
    }    

    return;
}
