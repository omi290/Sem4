import java.util.*;

public class program8 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s;
        int count = 0;
        s = sc.nextLine();
        
        for (int i = 0; i < s.length() - 2; i++) { 
            if (s.charAt(i) == '0') { 
                int j = i + 1;
                
                
                while (j < s.length() && s.charAt(j) == '1') {
                    j++;
                }

                
                if (j < s.length() && s.charAt(j) == '0' && j > i + 1) {
                    count++;
                    i = j - 1;
                }
            }
        }

        System.out.println("Count: " + count); 
        sc.close();
    } 
}
