#include <stdio.h>

void merge(int a[], int l, int mid, int u) {
    int i = l, j = mid + 1, k = 0;
    int b[u - l + 1]; 

    while (i <= mid && j <= u) {
       
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
           
        }
    }

    while (i <= mid) {
        b[k++] = a[i++];
    }

    while (j <= u) {
        b[k++] = a[j++];
    }

    
    for (i = l, k = 0; i <= u; i++, k++) {
        a[i] = b[k];
    }
}

void mergesort(int a[], int l, int u) {
    if (l < u) {
        int mid = (l + u) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, u);
        merge(a, l, mid, u);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergesort(arr, 0, n - 1);

    
    for (int i = 0; i < n; i++) {
        if(arr[i]==arr[i+1]){
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    
    return 0;
}
