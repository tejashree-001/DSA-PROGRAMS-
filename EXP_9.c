#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void display()
{
    struct Node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List: ");
    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void create()
{
    int n, i, value;
    struct Node *temp, *newnode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i=1;i<=n;i++)
    {
        newnode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d",&value);

        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
}

void insert_begin()
{
    struct Node *newnode;
    int value;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d",&value);

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;

    if(head != NULL)
    {
        head->prev = newnode;
    }

    head = newnode;
}

void insert_end()
{
    struct Node *temp, *newnode;
    int value;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d",&value);

    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }
}

void insert_middle()
{
    int pos, i, value;
    struct Node *temp, *newnode;

    printf("Enter position: ");
    scanf("%d",&pos);

    newnode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d",&value);

    newnode->data = value;

    temp = head;

    for(i=1;i<pos-1;i++)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL)
    {
        temp->next->prev = newnode;
    }

    temp->next = newnode;
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n---- MENU ----\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Middle\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                create();
                display();
                break;

            case 2:
                insert_begin();
                display();
                break;

            case 3:
                insert_end();
                display();
                break;

            case 4:
                insert_middle();
                display();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}