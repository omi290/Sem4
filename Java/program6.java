import java.util.*;
public class program6 {
    public static void main(String []args)
    {
       Scanner sc = new Scanner(System.in);
       int n;
       n=sc.nextInt();
       int a[]=new int[n];
        
        for(int i=0;i<n;i++)
        {
           a[i]=sc.nextInt();
        }
        for(int i=1;i<n;i++){
           for(int j=0;j<n-1;j++){
                if(a[j]>0&&a[i]<0){
                    int temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
           }
           
        }
        for(int i=0;i<n;i++){
            System.out.print(a[i]+" ");
        }
       sc.close();
    }
}
