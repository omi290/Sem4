#include <stdio.h>
#include <string.h>

// Function to swap two strings
void swap(char *str1, char *str2) {
    char temp[30];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

// Partition function for QuickSort
int partition(char str[][30], int low, int high) {
    int pivot = low, i = low, j = high;
    while (i < j) {
        while (strcmp(str[i], str[pivot]) <= 0 && i < high) i++;
        while (strcmp(str[j], str[pivot]) > 0 && j > low) j--;
        if (i < j) swap(str[i], str[j]);
    }
    swap(str[low], str[j]);
    return j;
}

// QuickSort function
void quickSort(char str[][30], int low, int high) {
    if (low < high) {
        int loc = partition(str, low, high);
        quickSort(str, low, loc - 1);
        quickSort(str, loc + 1, high);
    }
}

// Display function
void display(char str[][30], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }
}

int main() {
    int n = 0, ch = 0;
    char str[100][30];

    printf("1. Insert names\n2. Sort\n3. Display\n4. Exit\n");
    do {
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter number of names: ");
                scanf("%d", &n);
                getchar(); // Clear buffer
                printf("Enter names:\n");
                for (int i = 0; i < n; i++) {
                    fgets(str[i], sizeof(str[i]), stdin);
                    str[i][strcspn(str[i], "\n")] = '\0'; // Remove newline
                }
                break;
            case 2:
                if (n > 0) quickSort(str, 0, n - 1);
                else printf("No names to sort!\n");
                break;
            case 3:
                if (n > 0) display(str, n);
                else printf("No names to display!\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Enter a valid choice!\n");
        }
    } while (ch != 4);

    return 0;
}
