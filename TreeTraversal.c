#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *left, *right;
};


struct node* createNode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}


struct node* buildTree() {
    int value, choice;

    printf("Enter node value: ");
    scanf("%d", &value);

    struct node* root = createNode(value);

    // Left child
    printf("Does %d have left child? (1-Yes / 0-No): ", value);
    scanf("%d", &choice);
    if (choice == 1) {
        root->left = buildTree();
    }

    // Right child
    printf("Does %d have right child? (1-Yes / 0-No): ", value);
    scanf("%d", &choice);
    if (choice == 1) {
        root->right = buildTree();
    }

    return root;
}

// Traversals
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int choice;

    printf("Enter ROOT node\n");
    struct node* root = buildTree();

    while (1) {
        printf("\n--- Traversal Menu ---\n");
        printf("1. Inorder\n");
        printf("2. Preorder\n");
        printf("3. Postorder\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 2:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}