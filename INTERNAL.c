#include <stdio.h>
#define MAX 100

int main()
{
    int queue[MAX],n,i;
    int front = 0;
    int rear = -1;
    int choice, value;
    char ch;

    printf("number of elements in queue:");
    scanf("%d", &n);

    if(n > MAX)
    {   printf("Queue full \n");
        return 0; }

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {   rear++;
        scanf("%d", &queue[rear]);
    }

    do
    {
        printf("1. Insert at rare side \n");
        printf("2. Delete at front side\n");
        printf("3.front of the queue\n");
        printf("4.isfull\n");
        printf("5.isEmpty\n");

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
                    printf("\nQueue elements: ");
                    for(i = front; i <= rear; i++)
                  {
                 printf("%d ", queue[i]);
                 }
                 
                 }
                break;

            case 2: 
                if(front > rear)
                {
                    printf("Queue is empty \n");
                }
                else
                {
                    printf("Deleted front element : %d", queue[front]);
                    front++;
                    printf("Queue elements: ");
                  for(i = front; i <= rear; i++)
                {
                printf("%d ", queue[i]);
                }
                }
                break;


            case 3:    
            printf("front of the queue is %d\n ",queue[front]);

            break;

            case 4:
            if(front > rear)
            {
            printf("Queue is empty\n");
          }
          else{
            printf("queue is not empty");
          }

          break;

          case 5:
          if(rear==MAX-1){
            printf(" queue is full");
          }
          else{
            printf("queue is not full");
          }

          break;

        }

       
        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &ch);

    } while(ch == 'y');
    
}