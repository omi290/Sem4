#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void findPairWithSum(int arr[], int n, int key) {
    mergeSort(arr, 0, n - 1);

    int left = 0, right = n - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == key) {
            printf("%d %d\n", arr[left], arr[right]);
            return;
        } else if (sum < key) {
            left++;
        } else {
            right--;
        }
    }

    printf("No Such Elements Exist\n");
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, key;
        scanf("%d", &n);
        int arr[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        scanf("%d", &key);
        findPairWithSum(arr, n, key);
    }

    return 0;
}
