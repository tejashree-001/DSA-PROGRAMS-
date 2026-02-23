#include <stdio.h>
#define MAX 100

int main()
{
    int queue[MAX];
    int front = 0;
    int rear = -1;
    int n, i;
    int choice, value;
    char ch;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n > MAX)
    {
        printf("Queue full \n");
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        rear++;
        scanf("%d", &queue[rear]);
    }

    do
    {
        printf("1. Insert at rare side \n");
        printf("2. Delete at front side\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
                if(rear == MAX - 1)
                {
                    printf("Queue is full \n");
                }
                else
                {
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    rear++;
                    queue[rear] = value;
                    printf("Inserted: %d\n", value);
                    printf("Queue elements: ");
                    for(i = front; i <= rear; i++)
                  {
                 printf("%d ", queue[i]);
                 }
                 printf("\nFront = %d, Rear = %d\n", queue[front], queue[rear]);
                 }
                break;

            case 2: 
                if(front > rear)
                {
                    printf("Queue is empty \n");
                }
                else
                {
                    printf("Deleted front element : %d\n", queue[front]);
                    front++;
                    printf("Queue elements: ");
                  for(i = front; i <= rear; i++)
                {
                printf("%d ", queue[i]);
                }
                printf("\nFront = %d, Rear = %d\n", queue[front], queue[rear]);
                }
                break;


            default:
                printf("Invalid choice\n");
        }

        if(front > rear)
        {
            printf("Queue is empty\n");
        }
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);

    } while(ch == 'y');

    printf("exit \n");

    
}