
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *newNode(int value) {
    struct node *n = malloc(sizeof(struct node));

    if(n == NULL)
        exit(1);

    n->data = value;
    n->left = n->right = NULL;

    return n;
}

struct node *insert(struct node *root, int value) {
    if(root == NULL)
        return newNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    printf("BST inorder: ");
    inorder(root);

    printf("\n");

    return 0;
}
