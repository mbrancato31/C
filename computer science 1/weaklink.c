#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Link Link;
struct Link {
    int h;
    int v;
    int l;
    Link * nextLink;
    Link * backLink;
};

Link * add2end(Link * end, int value);
Link * breakPoint(Link * head, Link * tail, int count[],int limit);

int main(){

    int value;
    Link * head = NULL;
    Link * tail = NULL;
    int  count[2]; // count[1] is for broken links and count[2] are for whole links
    count[2] = 0;
    count[1] = 0;
    int whole = 0;

    
    do{

        scanf("%d", &value);

        if(value != -1){
            tail = add2end(tail, value);
            //printf("   %d  %d  %d\n", tail->h, tail->v, tail->l);
            // Check if the head is still NULL
            if (head == NULL)
                head = tail;
            
            if(tail->l == -1){
                
                Link * tmpHead = head;
                tail = breakPoint(tmpHead, tail, count, tail->h - 2);
                //printf("   a%d  %d  %d\n", tail->h, tail->v, tail->l);
            }
            whole++;
        }   
            
        
    }while( value  != -1);

    if(tail == NULL){
        printf("Ending chain height is %d.\n", 0);
        printf("There are %d broken links and %d whole links on the floor.\n", count[1], whole - count[1]);
    }else{
        printf("Ending chain height is %d.\n", tail->h);
        printf("There are %d broken links and %d whole links on the floor.\n", count[1], whole - tail->h - count[1]);
    }
    
    


    while( head != NULL){
        Link * next = head->nextLink;
        free(head);
        head = next;
    }

}

Link * add2end(Link * end, int value){
    // Create the node
   Link * newBack = calloc(1, sizeof(Link));
   newBack->v = value;
   
   // Set the new back's previous pointer to the previous back node
   newBack->backLink = end;
   
   // Check if the old back has a pointer that should be updated
   if (end != NULL)
      end->nextLink = newBack;
   
   // Set the next to NULL to signify the end of the list
   newBack->nextLink = NULL;

   // define height
   if(end == NULL){
       newBack->h = 1;
   }else{
       newBack->h = end->h + 1;
   }

   // define limit
   if(end == NULL){
       newBack->l = newBack->v;
   }else{
       int tempL = end->l - 1;
       if(tempL <= newBack->v){
           newBack->l = tempL;
       }else{
           newBack->l = newBack->v;
       }
   }
   
   // Return the newly created node
   return newBack;
}

Link * breakPoint(Link * head, Link * tail, int count[],int limit){
   
    if(head != NULL){
        
        if(head->v != limit){ 
            tail = breakPoint(head->nextLink, tail, count, limit-1 ); 
        }else if (head->v == limit){
            if(head->backLink == NULL){
                printf("Chain broken at link %d. New height is %d.\n", tail->h, 0);
                tail = NULL;
            }else{
                printf("Chain broken at link %d. New height is %d.\n", tail->h, head->backLink->h);
                tail = head->backLink;
                tail->nextLink = NULL;
            }            
            count[1]++;               

            

            while( head != NULL){
                Link * next = head->nextLink;
                free(head);
                head = next;
            }

            

        }
    }
    
    return tail;
}
