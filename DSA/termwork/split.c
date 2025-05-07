#include <stdio.h> 
#include <stdlib.h> 
typedef struct Node { 
    int data;         
    struct Node* next;   
} Node; 
Node* createNode(int value) { 
        Node* node = (Node*)malloc(sizeof(Node)); 
        if (!node) { 
        printf("Memory allocation failed!\n"); 
        exit(1); 
    } 
    node->data = value; 
    node->next = NULL; 
    return node; 
} 
void insert(Node** head, int value) { 
    Node* node = createNode(value); 
    if (*head == NULL) { 
    *head = node; 
    return; 
    } 
    Node* temp = *head; 
    while (temp->next != NULL) { 
    temp = temp->next; 
    } 
    temp->next = node; 
} 
// Function to split list P into lists Q (odd positions) and R (even positions) 
void split(Node* P, Node** Q, Node** R) { 
        int pos = 1;  // Position counter 
        Node *temp = P, *lastQ = NULL, *lastR = NULL; 
        while (temp != NULL) { 
            if (pos % 2 == 1) { // Odd position 
                if (*Q == NULL) { 
                *Q = temp;  // Set the head of Q 
                lastQ = temp; 
                } 
                else { 
                lastQ->next = temp; 
                lastQ = temp; 
                } 
            } 
            else { // Even position 
                if (*R == NULL) { 
                *R = temp;  // Set the head of R 
                lastR = temp; 
              } 
               else { 
                lastR->next = temp; 
                lastR = temp; 
            } 
            } 
            temp = temp->next; 
            pos++; 
    } 
    // Ensure the last nodes of Q and R terminate the lists properly 
    if (lastQ != NULL) lastQ->next = NULL; 
    if (lastR != NULL) lastR->next = NULL; 
} 
// Function to display the elements of a linked list 
void display(Node* head) { 
    if (head == NULL) { 
    printf("List is empty!\n"); 
    return; 
    } 
    Node* temp = head; 
    while (temp != NULL) { 
    printf("%d -> ", temp->data); 
    temp = temp->next; 
    } 
    printf("NULL\n"); 
} 
// Main function 
int main() { 
Node* P = NULL;  // Main list 
Node* Q = NULL;  // List containing odd positions of P 
Node* R = NULL;  // List containing even positions of P 
int choice, value; 
// Menu-driven program to create list P and split it into Q and R 
do { 
        printf("\nMenu:\n"); 
        printf("1. Insert into List P\n"); 
        printf("2. Display List P\n"); 
        printf("3. Split List P into Q and R\n"); 
        printf("4. Display List Q\n"); 
        printf("5. Display List R\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
    switch (choice) { 
    case 1: 
    printf("Enter value to insert into List P: "); 
    scanf("%d", &value); 
                    insert(&P, value); 
                    break; 
    
                case 2: 
                    printf("List P: "); 
                    display(P); 
                    break; 
    
                case 3: 
                    split(P, &Q, &R); 
                    printf("List P has been split into Q and R.\n"); 
                    break; 
    
                case 4: 
                    printf("List Q (Odd positions): "); 
                    display(Q); 
                    break; 
    
                case 5: 
                    printf("List R (Even positions): "); 
                    display(R); 
                    break; 
    
                case 6: 
                    printf("Exiting...\n"); 
                    break; 
    
                default: 
                    printf("Invalid choice! Please try again.\n"); 
            } 
        } while (choice != 6); 
    
    // Free memory for lists P, Q, and R 
    Node* temp; 
        while (P != NULL) { 
            temp = P; 
            P = P->next; 
            free(temp); 
        } 
        while (Q != NULL) { 
            temp = Q; 
            Q = Q->next; 
            free(temp); 
        } 
        while (R != NULL) { 
            temp = R; 
            R = R->next; 
            free(temp); 
        } 
    return 0;
}