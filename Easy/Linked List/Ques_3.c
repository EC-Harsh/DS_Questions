//Ques 3. Reverse a doubly linklist 
# include <stdio.h>
# include<stdlib.h>

typedef struct node{ // data type which stores: 
    int info; //DATA/Value
    struct node *nl,*pl;// next node's address and previous node's addres;
} node;

node * c_list(int n){
    node *head,*ptr,*prev; // *head for head pointer 
    // *ptr for traversing 
    // *prev for storing previous node's address so that 
    //it not lost after changing to next node 


    head=(node *)malloc(sizeof(node)); // head pointer .
    ptr=head;
    int i=1;
    while(n!=0){ // for n nodes
        if(i==1){ 
            // for head node firstly the nl and pl both are NULL;
            head->pl=NULL;
            head->nl=NULL;
        }
        else{
            ptr->nl=(node *)malloc(sizeof(node)); // creating next node 

            prev=ptr; // storing previous node 

            ptr=ptr->nl;

            ptr->pl=prev; // updating pointers
        }
        n--;
        
        printf("Enter Data for node %d: ",i);
        scanf("%d",&ptr->info); // asking data to put in present node .
        i++;}

        ptr->nl=NULL; // for last node nl will be NULL
        return head;
}

void print(node *ptr){
    if(ptr->nl==NULL){ // base condition for print func
        printf("%d->NULL\n",ptr->info);
        return ;
    }
    printf("%d<->",ptr->info);
    print(ptr->nl);
} 

// Logic used :

// After Observing it is found that swapping the nl and pls values and
// changing head pointer to last node will make the list reversed.

// so we store nl and pl in Y and X and  swap them .

// we have to take care that we dont loose next because if we next node the list will be destroyed.
// the t_ptr here takes care that . 

node *rev(node *head){
    node *ptr=head,*t_ptr; // t_ptr is travesing pointer which traverse till last.
    node *X,*Y; // X AND Y are two pointers that stores nodes pl and nl respectively

    while(t_ptr!=NULL){
        X=ptr->pl;
        Y=ptr->nl;
        // storing X and Y values .

        ptr->nl=X;
        ptr->pl=Y;
        // swapping nl and pl values .

        t_ptr=Y; // take t_ptr to next node 

        ptr=Y; // update ptr to next node so that it can change in next iteration
    }

    head=X->pl; // updating head to last node
    return head;
    
    
    
}
int main() {
    int size ;
    printf("Enter List Length: "); // Asking for length of the list
    scanf("%d",&size);

    node *head=c_list(size); // creating list
    print(head); 

    printf("Reversed LIST: \n");
    head=rev(head);
    print(head);
    return 0 ;
}