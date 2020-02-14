#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
struct Node {
    int v;
    Node * nextNode;
    Node * backNode;
};

typedef struct Tree Tree;
struct Tree {
    int v;
    Tree * parent;
    Tree * right;
    Tree * left;
};

Node * add2end(Node * end, int value);
Node * createTree(Node * pre, Node * post, Tree * root, int count);
void printTree(Tree * root, int count);
void cleanTree(Tree * cur);

int main(){

    int n;
    Tree * root;
    Node * headPreOrder = NULL;
    Node * tailPreOrder = NULL;
    Node * headPostOrder = NULL;
    Node * tailPostOrder = NULL;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int tmpValue;
        scanf("%d", &tmpValue);
        tailPostOrder = add2end(tailPostOrder, tmpValue);
        if (headPostOrder == NULL)
                headPostOrder = tailPostOrder;
        char temp;
        scanf("%c", &temp);
    }
    for(int i = 0; i < n; i++){
        int tmpValue2;
        scanf("%d", &tmpValue2);
        tailPreOrder = add2end(tailPreOrder, tmpValue2);
        if (headPreOrder == NULL)
                headPreOrder = tailPreOrder;
        char temp;
        scanf("%c", &temp);
    }

    /*Node * t = headPostOrder;
    for(int i = 0; i<n; i++){
        printf("%d", t->v);
        t = t->nextNode;
    }*/

    root = calloc(1, sizeof(Tree));
    Node * trash = createTree(headPreOrder, headPostOrder, root, 1);
    free(trash);
    //printf("a%d\n", root->right->right->right->v);
    printTree(root, 1);

    while( headPostOrder != NULL){
        Node * next = headPostOrder->nextNode;
        free(headPostOrder);
        headPostOrder = next;
    }

    while( headPreOrder != NULL){
        Node * next = headPreOrder->nextNode;
        free(headPreOrder);
        headPreOrder = next;
    }

    cleanTree(root);

return 0;
}//end main

///////////////////////////////////////////////////////////////////////////////////////

Node * add2end(Node * end, int value){
    // Create the node
   Node * newBack = calloc(1, sizeof(Node));
   newBack->v = value;
   
   // Set the new back's previous pointer to the previous back node
   newBack->backNode = end;
   
   // Check if the old back has a pointer that should be updated
   if (end != NULL)
      end->nextNode = newBack;
   
   // Set the next to NULL to signify the end of the list
   newBack->nextNode = NULL;

   // Return the newly created node
   return newBack;
}

Node * createTree(Node * pre, Node * post, Tree * root, int count){
    
    if(pre == NULL){
        return post;
    }
    
    root->v = pre->v;
//printf("a  count:%d value:%d pre:%d post:%d\n",count, root->v, pre->v, post->v);

    if(pre->v != post->v){
        //printf("b  count:%d value:%d pre:%d post:%d\n",count, root->v, pre->v, post->v);
        root->left = calloc(1, sizeof(Tree));
        post = createTree(pre->nextNode, post, root->left, count + 1);
        //printf("c  count:%d value:%d pre:%d post:%d\n",count, root->v, pre->v, post->v);
        
    }
    
    if(root->v == post->v){
        //printf("d  count:%d value:%d pre:%d post:%d\n",count, root->v, pre->v, post->v);
        
        Node * tmp = pre;
        if(pre->nextNode == NULL){
            pre = NULL;
        }else{
            if(pre->backNode == NULL){
                pre = pre->nextNode;
            }else{
                pre = pre->backNode;
                pre->nextNode = tmp->nextNode;
            }  
        }      
        free(tmp);
        return post->nextNode;        
    }
    
//printf("e  count:%d value:%d pre:%d post:%d\n",count, root->v, pre->v, post->v);
    root->right = calloc(1, sizeof(Tree));
    post = createTree(pre->nextNode, post, root->right, count + 1);
    //printf("f  count:%d value:%d pre:%d post:%d\n",count, root->v, pre->v, post->v);

    return post->nextNode;
}

void printTree(Tree * root, int count){
    //printf("a  c:%d v:%d\n", count, root->v);
    if(root == NULL){
        return;
    }
    if(root != NULL && root->left != NULL){
        //printf("b  c:%d v:%d\n", count, root->v);
        printTree(root->left, count + 1);
    }
    
    printf("%d ", root->v);

    if(root->right != NULL){
        //printf("d  c:%d v:%d\n", count, root->v);
        printTree(root->right, count + 1);
    }
    //printf("e  c:%d v:%d\n", count, root->v);
    return;
    
}

// Function to free an entire tree
void cleanTree(Tree * cur){
        if (cur == NULL)
            return;
        cleanTree(cur->left);
        cleanTree(cur->right);
        free(cur);
}