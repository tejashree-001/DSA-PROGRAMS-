#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* top = NULL;
    struct Node* newNode;
    struct Node* temp;

    int choice, value, n, i;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Create Linked List (Using Push)\n");
        printf("2. Pop (Delete All Elements)\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);

                printf("Enter %d values:\n", n);

                for (i = 0; i < n; i++) {
                    newNode = (struct Node*)malloc(sizeof(struct Node));

                    if (newNode == NULL) {
                        printf("Stack Overflow\n");
                        break;
                    }

                    printf("Value %d: ", i + 1);
                    scanf("%d", &value);

                    newNode->data = value;
                    newNode->next = top;
                    top = newNode;
                }

                printf("Linked List created successfully (Stack style)\n");
                break;

            case 2:
                if (top == NULL) {
                    printf("Stack Underflow (List already empty)\n");
                } else {
                    printf("Deleting elements:\n");

                    while (top != NULL) {
                        temp = top;
                        printf("%d deleted\n", top->data);
                        top = top->next;
                        free(temp);
                    }

                    printf("All elements deleted\n");
                }
                break;

            case 3:
                if (top == NULL) {
                    printf("List is empty\n");
                } else {
                    temp = top;
                    printf("Linked List elements:\n");

                    while (temp != NULL) {
                        printf("%d -> ", temp->data);
                        temp = temp->next;
                    }

                    printf("NULL\n");
                }
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}