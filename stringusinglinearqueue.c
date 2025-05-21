#include <stdio.h>
#include <string.h>

#define MAX 5

char queue[MAX][100];  // Queue to store strings
int front = -1;
int rear = -1;

void enQueue(char element[]) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear += 1;
        strcpy(queue[rear], element);  // Copy the string into the queue
        printf("'%s' inserted\n", element);
    }
}

void deQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("'%s' is deleted\n", queue[front]);
    front += 1;
    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("'%s' ", queue[i]);
    }
    printf("\n");
}

int main() {
    int ch;
    char element[100];

    while (1) {
        printf("\nSelect Operation:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        getchar();  // To clear the newline character after scanf

        switch (ch) {
            case 1:
                printf("Enter string to enqueue: ");
                fgets(element, 100, stdin);
                element[strcspn(element, "\n")] = 0; // Remove newline character
                enQueue(element);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}