#include<stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,found=0,c=0;
        scanf("%d",&n);
        int arr[n];
        for(int i =0;i<n;i++){
            scanf("%d",&arr[i]); // must be sorted.
        }
        int target,s,e,m;
        scanf("%d",&target); 
        s=0;
        e=n-1;
        while(s<=e){
            m=(s+e)/2;
            if(arr[m]==target){
                c++;
                printf("found and comparasions : %d\n",c);
                found =1;
                break;
            }
            else if(arr[m]<target){
                s=m+1;
                c++;
            }
            else {
                e=m-1;
                c++;
            }
        }
        if(!found)
                printf("not found and comparasions : %d\n",c);
    }
    return 0;
}