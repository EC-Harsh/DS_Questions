// Ques.1 Print the middle of a given linked list .
 # include <stdio.h>
 # include <stdlib.h>

typedef struct node{ // creating a node data type which stores data and link to another value which is dynamically allocated.
    int info ; // data/value
    struct node * nl; // pointer that stores next value address
 } node ;

node * c_list(int n){
    node *head= (node *)malloc(sizeof(node)); //creating a head node
    node *ptr=head; //creating a pointer that points to new node after every iteration.
    int i=1;
    while(n!=0){ // for n times because we have to create n nodes.
        if(i==1){
            head->nl=NULL; // for head node
        }
        else{
            ptr->nl= (node *)malloc(sizeof(node)); // creating a new node
            ptr=ptr->nl; //chainging ptr value to new node.
        }
        n--; i++;
        printf("Enter Data: ");
        scanf("%d",&ptr->info); // entering data to new node.
        ptr->nl=NULL; // last node value will be NULL because it is not connected to any other node.
    }
    return head; // return head so that list can be acessed to head.
}

void print(node * ptr){
    if(ptr->nl==NULL){ // base condition for recurrsion
        printf("%d->NULL\n",ptr->info); // prints data for last node .
        return ;
    }
    printf("%d-> ",ptr->info); // printing data for each node .
    print(ptr->nl);
}
void mid(node *ptr){ // function that prints middle node
    // the logic used is:
    // creating two pointers ptr and t_ptr and one counter variable c that counts node's position 
    // and changing t_ptr value to its next link value when counter varaible is odd.
    // this will take t_ptr to the middle when ptr is at last.
    int c=0;
    node *t_ptr=ptr;
    while(ptr->nl!=NULL){ // using while loop for traversing till last 
        if(c%2!=0){ // condition when t_ptr has to change.
            t_ptr=t_ptr->nl;
        }
        
        ptr=ptr->nl;
        c++;
    }
    printf("\nThe Middle Value of The list is: %d\n",t_ptr->info); 
    // printing the middle value .
}

 int main() {
    
    node *l1; // creating list's head pointer.
    l1=c_list(5);
    print(l1); // printing the whole list.
    mid(l1); // printing the middle value .
    return 0 ;
 }