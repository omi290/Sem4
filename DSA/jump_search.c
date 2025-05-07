#include <stdio.h>  
int main() 
{    
    int T; 
    scanf("%d", &T); 
    while(T--) { 
        int n;  
        scanf("%d", &n); 
        int arr[n]; 
        for(int i = 0; i < n; i++) { 
            scanf("%d", &arr[i]); 
        } 
        int steps = 1, comp = 0, prev = 0, key;  
        scanf("%d", &key); 
 
        while(steps < n && arr[steps] <= key) { 
            comp++; 
            prev = steps; 
            steps *= 2; 
        } 
        int c = 1; 
        for(int j = prev; j <= steps && j < n; j++) { 
            comp++; 
            if(arr[j] == key) { 
                printf("Present %d.\n", comp); 
                c = 0; 
                break; 
            } 
        } 
        if(c == 1) 
            printf("Not Present %d.\n", comp); 
    } 
 
    return 0;  
} 