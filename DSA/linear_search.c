#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,found=0;
        scanf("%d",&n);
        int arr[n];
        for(int i =0;i<n;i++){
            scanf("%d",&arr[i]); 
        }
        int target;
        scanf("%d",&target); 
        for(int i=0;i<n;i++){
            if(arr[i]==target){
                printf("found %d\n",i+1);
                found=1;
                break;
            }
        }
        if(!found){
            printf("not found");
        }
    }
    return 0;
}