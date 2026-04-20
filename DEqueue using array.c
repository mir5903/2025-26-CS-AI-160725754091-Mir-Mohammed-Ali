#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

// Check if full
int isFull() {
    return (front == 0 && rear == MAX - 1);
}

// Check if empty
int isEmpty() {
    return (front == -1);
}

// Insert at front
void insertFront(int value) {
    if (isFull()) {
        printf("Deque is Full\n");
        return;
    }

    if (front == -1) { // first element
        front = rear = 0;
    }
    else if (front == 0) {
        printf("Cannot insert at front (no space)\n");
    }
    else {
        front--;
    }

    deque[front] = value;
}

// Insert at rear
void insertRear(int value) {
    if (isFull()) {
        printf("Deque is Full\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        printf("Cannot insert at rear (no space)\n");
    }
    else {
        rear++;
    }

    deque[rear] = value;
}

// Delete from front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
}

// Delete from rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    }
    else {
        rear--;
    }
}

// Display
void display() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

// Main
int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertRear(30);

    display();

    deleteFront();
    deleteRear();

    display();

    return 0;
}
