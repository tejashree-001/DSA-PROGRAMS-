#include <stdio.h>

int main() {
    int stack[100];
    int top = -1;
    int size, n;
    int choice, x, i;

    printf("Enter stack size: ");
    scanf("%d", &size);

    printf("Enter number of elements in stack:\n  ");
    scanf("%d", &n);

    if (n > size) {
        printf("number of elements cannot be more than stack size.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        top++;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &stack[top]);
    }

    
    printf("\nstack is:\n");
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }

    
    do {
        
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Is Empty\n");
        printf("5. Is Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:   
                if (top == size - 1) {
                    printf("stack is full. cannot push\n");
                } else {
                    printf("Enter element to push: ");
                    scanf("%d", &x);
                    top++;
                    stack[top] = x;
                    printf("Element %d pushed successfully.\n", x);
                }
                printf("Stack after push an element:\n"); 
                for (i = top; i >= 0; i--) {
                    printf("%d\n", stack[i]);
                }
                break;

            case 2:   
                if (top == -1) {
                    printf("Stack is empty . can not push\n");
                } else {
                    printf("Popped element: %d\n", stack[top]);
                    top--;
                }

                printf("Stack after pop an element:\n"); 
                for (i = top; i >= 0; i--) {
                    printf("%d\n", stack[i]);
                }
                break;

            case 3:  
                if (top == -1) {
                    printf("Stack is empty. No top element.\n");
                } else {
                    printf("Top element is: %d\n", stack[top]);
                }
                break;

            case 4:   
                if (top == -1)
                    printf("Stack is EMPTY.\n");
                else
                    printf("Stack is NOT empty.\n");
                break;

            case 5:   
                if (top == size - 1)
                    printf("Stack is FULL.\n");
                else
                    printf("Stack is NOT full.\n");
                break;

            case 6:
                printf("exit \n");
                break;

            default:
                printf("Invalid choice\n");
        }


    } while (choice != 6);

    return 0;
}
