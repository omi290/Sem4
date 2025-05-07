
#include<stdio.h>
void insertionSort(int arr[], int n, int *comparisons, int *shifts) {
    *comparisons = 0;
    *shifts = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            (*comparisons)++;
            arr[j + 1] = arr[j];  
            (*shifts)++;
            j--;
        }

        

        arr[j + 1] = key;
        (*shifts)++;  
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int comparisons = 0, shifts = 0;

    insertionSort(arr, n, &comparisons, &shifts);

    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nComparisons = %d\nShifts = %d\n", comparisons, shifts);
    return 0;
}