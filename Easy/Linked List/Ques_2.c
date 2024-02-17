// Ques 2 Reverse a given link list.

# include <stdio.h>
# include <stdlib.h>

typedef struct node{ // creating a node data type which stores data and link to another value which is dynamically allocated.
    int info; // data/val
    struct node *nl; // pointer that stores next value address
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

node * rev(node *ptr){
    node *head,*curr,*n,*prev; 
    //creating four pointers first is head which is stores head node , 
    // 2nd is current which stores  current node value.
    // 3rd and 4th are n and prev which stores next and previous node respectively.


    // The logic used in this question :
    // first the  head and curr and prev node will be same .
    // second the n is pointing to second .
    // traversing the list till last value i.e NULL
    // first change curr value next node(n) and and make n=n->nl
    // which will make n to point every next node untill end .
    // for reversing the list we have to make nl of a node to its previous node's addres
    // that's why curr->nl=prev.
    // now change the prev to curr.
    // repeat the above steps till last node by using while loop. 


    head=curr=prev=ptr;
    n=ptr->nl;
    

    while(n!=NULL){ // traversing till last 

        curr=n; // first change curr value next node(n)

        n=n->nl; //make n to point every next node untill end 

        curr->nl=prev;// for reversing the list we have to make nl 
        // of a node to its previous node's addres that's why curr->nl=prev.
        
        prev=curr; //change the prev to curr.
    } 
    head->nl=NULL; // making head node's nl to NULL so that it will become last node
//  after reversing

    head=curr; // changing the head value curr which will be last node after traversing .
    return head;
}
int main() {
     node *l1; // creating list's head pointer.
    l1=c_list(5);
    print(l1); // printing the whole list. 

    l1=rev(l1) ;// reversing the list .
    print(l1); // printing the reversed list.
    return 0 ;
}