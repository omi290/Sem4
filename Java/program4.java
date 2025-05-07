import java.util.*;
public class program4 {
    public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int num;
            num = sc.nextInt();
            int ans = 0, mul = 1;  

        while (num != 0) {
            int rem = num % 10;
            if (rem == 0) {
                rem = 1;
            }
            ans = rem * mul + ans;  
            mul *= 10; 
            num /= 10;
        }
            System.out.println(+ans);
            sc.close();
    }
}
