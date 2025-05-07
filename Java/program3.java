import java.util.*;
public class program3 {
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        int num1,num2,sum1=0,sum2=0;
        System.out.print("enter 2 numbers");
        num1=sc.nextInt();
        num2=sc.nextInt();
        for(int i =1;i<=num1/2;i++){
            if(num1%i==0)
            {
                sum1+=i;
            }
        }
        for(int i =1;i<=num2/2;i++){
            if(num2%i==0)
            {
                sum2+=i;
            }
        }
        if((sum1==num1) &&(sum2==num2))
        {
            System.out.println("Frindly pair");
        }
        else 
        {
            System.out.println("Not friendly pair");
        }
        sc.close();
    }
}
