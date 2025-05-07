#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int id;
    char name[20];
    struct node *next;
} list;

list *create(int id, char *name) {
    list *temp = (list *)malloc(sizeof(list));
    temp->id = id;
    strcpy(temp->name, name);
    temp->next = NULL; // Initialize next to NULL
    return temp;
}

void insert(list **h, int id, char *name) {
    list *temp = create(id, name);
    if (*h == NULL) {
        *h = temp;
        return;
    }
    list *p = *h;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = temp;
}

void display(list *h) {
    list *p = h;
    while (p != NULL) {
        printf("%d %s\n", p->id, p->name);
        p = p->next;
    }
}

list *unionlist(list *h1, list *h2) {
    list *temp = NULL; // Initialize union list
    list *p = h1, *q = h2;

    // Copy all elements from h1
    while (p != NULL) {
        insert(&temp, p->id, p->name);
        p = p->next;
    }

    // Copy unique elements from h2
    while (q != NULL) {
        int found = 0;
        p = h1;  // Reset p to start of h1
        while (p != NULL) {
            if (p->id == q->id) {
                found = 1;
                break;
            }
            p = p->next;
        }
        if (!found) {
            insert(&temp, q->id, q->name);
        }
        q = q->next;
    }

    return temp;
}

int main() {
    list *h1 = NULL, *h2 = NULL, *union_list = NULL;
    int choice, emp_id;
    char name[20];

    do {
        printf("\nMenu:\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Find Union\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Emp_Id and Name to insert into List 1: ");
            scanf("%d", &emp_id);
            getchar();
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            insert(&h1, emp_id, name);
            break;
        case 2:
            printf("Enter Emp_Id and Name to insert into List 2: ");
            scanf("%d", &emp_id);
            getchar();
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            insert(&h2, emp_id, name);
            break;
        case 3:
            printf("List 1:\n");
            display(h1);
            break;
        case 4:
            printf("List 2:\n");
            display(h2);
            break;
        case 5:
            union_list = unionlist(h1, h2);
            printf("Union of List 1 and List 2:\n");
            display(union_list);

            // Free union list
            list *temp;
            while (union_list != NULL) {
                temp = union_list;
                union_list = union_list->next;
                free(temp);
            }
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    // Free memory for h1 and h2
    list *temp;
    while (h1 != NULL) {
        temp = h1;
        h1 = h1->next;
        free(temp);
    }
    while (h2 != NULL) {
        temp = h2;
        h2 = h2->next;
        free(temp);
    }

    return 0;
}
