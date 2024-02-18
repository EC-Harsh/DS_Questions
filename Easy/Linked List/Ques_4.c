// Ques 4. Delete a node from single link list whose head pointer is not given .
// only the pointer is given which is pointing to a node which is to be deleted.
// there is no chance that this is the last node .

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

node * rptr(node * head){ // creating a fucntion that returns a pointer to a node /

// assuming that user  will give data as 1,2,3,4,5
// then it will return the pointer pointing to that node whose value is 3.

    node*ptr=head;
    while(ptr!=NULL){
        if(ptr->info==3){
            return ptr;
        }
        ptr=ptr->nl;
    }
}
void deln(node *ptr){

    // logic used:
    // we cant change previous node's nl link so we are 
    // right shifting values from that node whose pointer is given.
    // suppose the list is :
    
    // |1|200| -> |2|300| -> |3|400|(ptr) -> |4|500| -> |5|NULL|
    // ptr is the pointer pointing n to adress 300.

    // we are updating value as shown below
    //  |1|200| -> |2|300| -> |4|400| -> |5|NULL| 

    // see the difference in the node's nl values. 

    node*tptr=ptr->nl; // creating a pointer which will store next node information
    while(1){

        ptr->info=tptr->info; // updating data

        if(tptr->nl==NULL){ // for last node we are breaking loop.
            free(tptr);
            break;}

        ptr=ptr->nl;
        tptr=tptr->nl;
    }

    // As the data of last node's info is already copied to second last node 
    // we have to change second last node's nl value to NULL so that 
    // it becomes the last node .
    ptr->nl=NULL;
}

 int main()
 {
    int size ;
    printf("Enter list Length: ");
    scanf("%d",&size);
    node *l1=c_list(size);
    print(l1);
    

    printf("list After Deleting a node (assuming that node with info=3 have to be deleted): \n");
    deln(rptr(l1));
    print(l1);

    return 0;
 }
 