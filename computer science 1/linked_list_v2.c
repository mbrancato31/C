
#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 10

#define DEBUG

// The node structure for our linked list
typedef struct Node Node;
struct Node {
    int value;
    Node * nextPtr;
};


// Our prototypes
Node * add2end(Node * front, Node * end, int value);
Node * add2front(Node * front, int value);
void printList(Node * someNode);
void printRevList(Node * someNode);

// The main method
int main()
{
    int i;
    
    // Make the original list empty
    Node * front = NULL;
    Node * end = NULL;
    
    // Add values
    for (i = 0; i < MAX_COUNT; i++)
    {
        if (rand() % 2 == 1) 
        {
            // Capture the element in case we want to debug
            int element  = rand();
            
            // Set the front to the new head (important if the list was empty)
            front = add2end(front, end, element);
            
            // Set the end to front if the list was originally empty
            if (end == NULL)
            {
                end = front;
            }
// DEBUG
#ifdef DEBUG
            printf("Adding to end %d\n", element);
#endif
        }
        else
        {
            // Capture the element in case we want to debug
            int element = rand();
            
            // Since we are updating the front, we should store that new value
            front = add2front(front, element);
            
            // Update the end if the list was originally null
            if (end == NULL)
            {
                end = front;
            }
            
// DEBUG
#ifdef DEBUG
            printf("Adding to front %d\n", element);
#endif
        }
        
        //(list not empty) AND (end is not actually end)
        while (end != NULL && end->nextPtr != NULL)
        {
            // Walk the end pointer to the actual end
            end = end->nextPtr;
        }
    }
    
// DEBUG
#ifdef DEBUG
    // Print the list
    printList(front);
    printRevList(front);
#endif

    // Store the number of nodes free'd
    int freeCount = 0;
    
    // Delete the memory
    while (front != NULL)
    {
        // Capture the address of the second node in the list
        Node * nextFront = front->nextPtr;
        
        // Free the front since we have the next pointer captured
        free(front);
        freeCount++;
        
        // (old code) Use after free
        // front = front->nextPtr;  
        // Does not cause a use after free
        front = nextFront;
    }
    
    // Print the number of nodes that were freed
    printf("The number of free's was %d\n", freeCount);
    
    return 0;
}

// Fixed method to add to the end
// Returns the pointer to the front after insertion 
// (in the case of an empty list)
Node * add2end(Node * front, Node * end, int value)
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
    lastNode->value = value;
    
    // Return the expected front node
    return frontReturn;
}

// Fixed function to add to the front
// Returns the front of the list after insertion
Node * add2front(Node * front, int value)
{
    // Make the new front node
    Node * newFront = (Node *) calloc(1, sizeof(Node));
    newFront->nextPtr = front;
    newFront->value = value;
    
    // Return the new front
    return newFront;
}

// Function to print the values in a linked list
void printList(Node * someNode)
{
    // Base case
    if (someNode == NULL)
    {
        printf("NULL\n");
        return;
    }
    
    // Recursive statement
    printf("%d -> ", someNode->value);
    printList(someNode->nextPtr);
}

// Function to print the values in a linked list IN REVERSED ORDER
void printRevList(Node * someNode)
{
    // Base case
    if (someNode == NULL)
    {
        printf("NULL ");
        return;
    }
    
    // Recursive statement
    // Remember to call the correct function...
    printRevList(someNode->nextPtr);
    
    // Print after recursion to reverse the list
    printf("%d -> ", someNode->value);
}
