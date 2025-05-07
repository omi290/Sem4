#include<stdio.h>
#include<math.h>
int main (){
        int t;
        scanf("%d",&t);
        while(t--){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i = 0; i < n; i++){
            scanf("%d",&arr[i]); 
        }
        int a,c=0;
        scanf("%d",&a);
        for(int i = 0;i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(abs(arr[i] - arr[j]) == a){
                    c++;
                
                }
            }
        }
        printf("%d\n",c);
    }
    return 0;
}