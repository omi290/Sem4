import java.util.*;

class ArrayDemo
{   int n;
    ArrayDemo(int n){
        this.n=n;
    }
    void ArrFun(int arr[],int a){
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]+arr[j]==a){
                    System.out.println("pairs : "+ arr[i] + " and "+arr[j]);
                }
            }
        }
    }
    
    void ArrFun(int a[], int b[], int p, int q) {
        int i = 0, j = 0;
        while (i < p && j < q) {  
            if (a[i] > b[j]) {
                
                int temp = a[i];
                a[i] = b[j];
                b[j] = temp;
    
                Arrays.sort(b);
            }
            i++;  
        }
    }
    
}
public class program11 {
    public static void main(String args[])
    {   
        Scanner sc = new Scanner(System.in);
        int n,k;
        n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println("Enter the target");
        k=sc.nextInt();
        ArrayDemo array = new ArrayDemo(n);
        array.ArrFun(arr, k);
        int p,q;
        System.out.println("Enter p and q ");
        p=sc.nextInt();
        q=sc.nextInt();
        int a[]=new int[p];
        int b[]=new int[q];
        for(int i=0;i<p;i++){
            a[i]=sc.nextInt();
        }
        for(int i=0;i<q;i++){
            b[i]=sc.nextInt();
        }
        array.ArrFun(a,b,p,q);
        for(int i=0;i<p;i++){
            System.out.print(a[i] + " ");
        }
        System.out.println();
        for(int i=0;i<q;i++){
            System.out.print(b[i] + " ");
        }
        sc.close();
    }
}
