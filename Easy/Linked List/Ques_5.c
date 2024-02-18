// Ques 5. Nth node from end in single link list
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{                    // creating a node data type which stores data and link to another value which is dynamically allocated.
    int info;        // data/value
    struct node *nl; // pointer that stores next value address
} node;

node *c_list(int n)
{
    node *head = (node *)malloc(sizeof(node)); // creating a head node

    node *ptr = head; // creating a pointer that points to new node after every iteration.

    int i = 1;
    while (n != 0)
    { // for n times because we have to create n nodes.
        if (i == 1)
        {
            head->nl = NULL; // for head node
        }
        else
        {
            ptr->nl = (node *)malloc(sizeof(node)); // creating a new node
            ptr = ptr->nl;                          // chainging ptr value to new node.
        }
        n--;
        i++;
        printf("Enter Data: ");
        scanf("%d", &ptr->info); // entering data to new node.
        ptr->nl = NULL;          // last node value will be NULL because it is not connected to any other node.
    }
    return head; // return head so that list can be acessed to head.
}

void print(node *ptr)
{
    if (ptr->nl == NULL)
    {                                    // base condition for recurrsion
        printf("%d->NULL\n", ptr->info); // prints data for last node .
        return;
    }
    printf("%d-> ", ptr->info); // printing data for each node .
    print(ptr->nl);
}

void nfromend(node *ptr, int n)
{
    static int x = 0; // creating a static variable so that is not changes every time function calls .

    if (ptr == NULL)
    { // base condition i.e last node.
        return;
    }

    nfromend(ptr->nl, n);
    x++; // increasing x by 1 every time function returns from last

    if (x == n)
    { // check for nth node
        printf("The %dth from end is : %d\n", n, ptr->info);
    }
}
int main()
{
    node *l1 = c_list(5);

    nfromend(l1, 4);

    return 0;
}