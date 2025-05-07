#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b, int *s) {
    int temp = *a;
    *a = *b;
    *b = temp;
    (*s)++;
}

int partition(int a[], int l, int u, int *c, int *s) {
    int i = l - 1, pivot = a[u];
    for (int j = l; j < u; j++) {
        (*c)++;
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j], s);
        }
    }
    swap(&a[i + 1], &a[u], s);
    return i + 1;
}

void quicksort(int a[], int l, int u, int *c, int *s) {
    if (l < u) {
        int r = l + rand() % (u - l + 1);
        swap(&a[r], &a[u], s);
        int loc = partition(a, l, u, c, s);
        quicksort(a, l, loc - 1, c, s);
        quicksort(a, loc + 1, u, c, s);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], c = 0, s = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n - 1, &c, &s);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nComparisons: %d\nSwaps: %d\n", c, s);
    return 0;
}
