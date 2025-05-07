import java.util.Scanner;

public class program7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m, i, j, k, minRow, colIndex, f;
        
        System.out.print("Enter number of rows: ");
        n = sc.nextInt();
        System.out.print("Enter number of columns: ");
        m = sc.nextInt();
        
        int a[][] = new int[n][m];

        System.out.println("Enter matrix elements:");
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        boolean found = false;

        for (i = 0; i < n; i++) {
            minRow = a[i][0];
            colIndex = 0;

           
            for (j = 1; j < m; j++) {
                if (a[i][j] < minRow) {
                    minRow = a[i][j];
                    colIndex = j;
                }
            }

            
            f = 1;
            for (k = 0; k < n; k++) {
                if (a[k][colIndex] > minRow) {
                    f = 0;
                    break;
                }
            }

            if (f == 1) {
                System.out.println("Saddle point  :  " + minRow);
                found = true;
            }
        }

        if (!found) {
            System.out.println("No saddle point found");
        }

        sc.close();
    }
}
