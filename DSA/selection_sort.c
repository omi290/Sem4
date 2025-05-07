#include<stdio.h>
void select(int *a,int n){
    int s=0,c=0;
    for(int i=0;i<n-1;i++){
        int min =i;
        for(int j=i+1;j<n;j++){
            c++;
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp=a[i];
            a[i]=a[min];
            a[min]=temp;
            s++;
        }
    }
    printf("swaps : %d\ncomparasions : %d \n",s,c);
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    select(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}