
#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if(rear == SIZE - 1)
        printf("Queue Overflow\n");
    else {
        if(front == -1)
            front = 0;

        queue[++rear] = value;
    }
}

void dequeue() {
    if(front == -1)
        printf("Queue Underflow\n");
    else {
        printf("Deleted: %d\n", queue[front++]);

        if(front > rear)
            front = rear = -1;
    }
}

void display() {
    int i;

    if(front == -1) {
        printf("Queue is empty\n");
        return;
    }

    for(i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Queue: ");
    display();

    dequeue();

    printf("After deletion: ");
    display();

    return 0;
}

