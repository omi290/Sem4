import java.util.*;
class Program1
{
    public static void main(String[] args){
       
        Scanner sc = new Scanner(System.in);
        
        int roll , sem;
        String name,course;
        System.out.print("enter name :");
        name = sc.nextLine();
        System.out.print("enter roll no. :");
        roll=sc.nextInt();
        sc.nextLine();
        System.out.print("enter course :");
        course=sc.nextLine();
        System.out.print("enter semester :");
        sem=sc.nextInt();
        System.out.println("-------------X-------------");
        System.out.println("Name : "+name);
        System.out.println("Roll No.: "+roll);
        System.out.println("Semester : "+sem);
        System.out.println("Course : "+course);
        sc.close();
    }
}
