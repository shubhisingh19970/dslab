
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int value) {
    struct node *newnode, *temp;

    newnode = malloc(sizeof(struct node));

    if (newnode == NULL)
        return;

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    }
    else {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }
}

void display() {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    printf("Linked List: ");
    display();

    return 0;
}
