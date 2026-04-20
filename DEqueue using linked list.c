#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Insert at front
void insertFront(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;

    if (front == NULL) {
        front = rear = temp;
    } else {
        temp->next = front;
        front->prev = temp;
        front = temp;
    }
    printf("Inserted at front\n");
}

// Insert at rear
void insertRear(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        temp->prev = rear;
        rear = temp;
    }
    printf("Inserted at rear\n");
}

// Delete from front
void deleteFront() {
    if (front == NULL) {
        printf("Deque is Empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Deleted: %d\n", temp->data);

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }
    free(temp);
}

// Delete from rear
void deleteRear() {
    if (rear == NULL) {
        printf("Deque is Empty\n");
        return;
    }

    struct Node* temp = rear;
    printf("Deleted: %d\n", temp->data);

    if (front == rear) {
        front = rear = NULL;
    } else {
        rear = rear->prev;
        rear->next = NULL;
    }
    free(temp);
}

// Display
void display() {
    if (front == NULL) {
        printf("Deque is Empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
