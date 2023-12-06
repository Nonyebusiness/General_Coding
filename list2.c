#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    node *list = NULL; //list that points to nothing rn

    for (int i =1; i < argc; i++)
    {
         int number = atoi(argv[i]);

         node *n = malloc(sizeof(node));
         if (n == NULL)
         {
            return 1;
         }

          // Set the 'number' field of the new node 'n' to the value provided by the user
    n->number = number;

    // Set the 'next' pointer of the new node 'n' to NULL, indicating it is the last node in the list
    n->next = NULL;

    // Point the 'next' pointer of the new node 'n' to the current first node in the list
    n->next = list;

    // Update the 'list' pointer to point to the new node 'n', making 'n' the new first node of the list
    list = n;
    }
    node *ptr = list;

    while (ptr != NULL)
    {
        printf("%i\n", ptr->number); //prints what pointer is pointing at
        ptr = ptr->next;  //makes pointer point at what the number it was pointing at was pointing at, so if 3 was pointing at 2 and pounter was pointing at 3 then now it'll point to 2
    }

    ptr = list;
    while (ptr!=NULL)
    {
        node *next = ptr->next; //this line needs cause other you cant use ptr
        free(pt  r);
        ptr =ptr->next;
    }
}