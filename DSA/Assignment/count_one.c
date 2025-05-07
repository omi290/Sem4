#include<stdio.h>

int main (){
   
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i = 0; i < n; i++){
            scanf("%d",&arr[i]); // must be sorted.
        }
        int  s, e, m;
         
        s = 0;
        e = n - 1;
        int last_occurrence = -1, first_occurrence = -1;

        
        while(s <= e){
            m = (s + e) / 2;
            if(arr[m] == 1){
                first_occurrence = m;
                e = m - 1;
            }
            else if(arr[m] < 1){
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }

    
        s = 0;
        e = n - 1;

    
        while(s <= e){
            m = (s + e) / 2;
            if(arr[m] == 1){
                last_occurrence = m;
                s = m + 1;
            }
            else if(arr[m] < 1){
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }

        if(last_occurrence == -1 && first_occurrence == -1)
            printf("Not present\n");
        else
            printf("Occurrences: %d\n", last_occurrence - first_occurrence + 1);
    
    
    return 0;
}
