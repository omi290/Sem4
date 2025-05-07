#include<stdio.h>

int main (){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i = 0; i < n; i++){
            scanf("%d",&arr[i]); // must be sorted.
        }
        
        for(int k = 2; k < n; k++){
            int i= 0,j=k-1;
        while(i<j){
                    if(arr[i] + arr[j] == arr[k]){
                        printf("%d %d %d\n",i+1,j+1,k+1);
                        return 0;
                    }
                    else if(arr[j] + arr[i] <arr[k]){
                        j--;
                    }
                    else i++;
            }
        }
        
        printf("Not present\n");
    }
    return 0;
}