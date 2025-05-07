#include <stdio.h>

void findCommonElements(int arr1[], int m, int arr2[], int n) {
    int i = 0, j = 0, found = 0;

    while (i < m && j < n) {
        if (arr1[i] == arr2[j]) {
            printf("%d ", arr1[i]);
            i++;
            j++;
            found = 1;
        } 
        else if (arr1[i] < arr2[j]) {
            i++;
        } 
        else {
            j++;
        }
    }

    if (!found) {
        printf("No Common Elements");
    }
    printf("\n");
}

int main() {
    int m, n;
    
    scanf("%d", &m);
    int arr1[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &n);
    int arr2[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    findCommonElements(arr1, m, arr2, n);

    return 0;
}
