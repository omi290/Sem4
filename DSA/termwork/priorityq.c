#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
typedef struct Node {
    int value;
    int id;
    struct Node *next, *prev;
} Node;

// Function to create a new node
Node *create(int value, int id) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->id = id;
    node->next = node->prev = NULL;
    return node;
}

// Function to insert a node in the queue based on ID order
void enqueue(Node **head, int value, int id) {
    Node *node = create(value, id);
    if (*head == NULL) {
        *head = node;
        return;
    }
    Node *temp = *head;

    while (temp && temp->id <= id) {
        temp = temp->next;
    }

    if (!temp) { // Insert at the end
        Node *last = *head;
        while (last->next) {
            last = last->next;
        }
        last->next = node;
        node->prev = last;
    } else if (temp == *head) { // Insert at the front
        node->next = *head;
        (*head)->prev = node;
        *head = node;
    } else { // Insert in the middle
        node->next = temp;
        node->prev = temp->prev;
        temp->prev->next = node;
        temp->prev = node;
    }
}

// Function to remove a node from the front of the queue
int dequeue(Node **head) {
    if (*head == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    Node *temp = *head;
    int id = temp->id;
    *head = (*head)->next;
    if (*head) {
        (*head)->prev = NULL;
    }
    free(temp);
    return id;
}

// Function to display the queue
void printQueue(Node *head) {
    if (!head) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue (ID -> Value):\n");
    while (head) {
        printf("%d -> %d\n", head->id, head->value);
        head = head->next;
    }
}

int main() {
    int choice;
    Node *queue = NULL;

    printf("Queue Operations:\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int value, id;
                printf("Enter value and ID: ");
                scanf("%d %d", &value, &id);
                enqueue(&queue, value, id);
                break;
            }
            case 2: {
                int removedId = dequeue(&queue);
                if (removedId != -1) {
                    printf("Dequeued ID: %d\n", removedId);
                }
                break;
            }
            case 3: {
                printQueue(queue);
                break;
            }
            case 4: {
                printf("Exiting program.\n");
                break;
            }
            default: {
                printf("Invalid choice. Try again.\n");
            }
        }
    } while (choice != 4);

    return 0;
}
