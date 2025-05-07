import java.util.*;
public class program2 {
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        int choice;
        double p,a;
        float r;
        int n;
        System.out.println("1. Term Deposit \n 2. Recurring Deposite \n choice :");
        choice = sc.nextInt();
        switch(choice){
            case 1:
                System.out.println("Enter principal , rate of intrest , time (years)");
                p=sc.nextDouble();
                r=sc.nextFloat();
                n=sc.nextInt();
                a=p*(1 + r / 100)*n;
                System.out.println("Amount : "+a);
                break;
            case 2:
                System.out.println("Enter principal , rate of intrest , time (years)");
                p=sc.nextDouble();
                r=sc.nextFloat();
                n=sc.nextInt();
                a= p * n + p * n*((n + 1) / 2) * (r / 100) * (1 / 12);
                System.out.println("Amount : "+a);
                break;
            default:
                System.out.println("enter the valid choice");
        }
        sc.close();
    }
}
