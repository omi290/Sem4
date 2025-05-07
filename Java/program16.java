import java.util.Scanner;

class InvalidInputException extends Exception {
    public InvalidInputException(String message) {
        super(message);
    }
}

class Employee {
    private int empId;
    private String name;
    private int deptId;

    public Employee(int empId, String name, int deptId) throws InvalidInputException {
        if (empId < 2001 || empId > 5001) {
            throw new InvalidInputException("Employee Id must be between 2001 and 5001");
        }
        if (!Character.isUpperCase(name.charAt(0))) {
            throw new InvalidInputException("Employee name must start with a capital letter");
        }
        if (deptId < 1 || deptId > 5) {
            throw new InvalidInputException("Department Id must be between 1 and 5");
        }
        this.empId = empId;
        this.name = name;
        this.deptId = deptId;
    }

    public void display() {
        System.out.println("Employee details:");
        System.out.println("Id: " + empId);
        System.out.println("Name: " + name);
        System.out.println("Department Id: " + deptId);
    }
}

public class program16 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            System.out.println("Enter Employee ID:");
            int empId = Integer.parseInt(sc.nextLine());
            
            System.out.println("Enter Employee Name:");
            String name = sc.nextLine().trim();
            
            System.out.println("Enter Department ID:");
            int deptId = Integer.parseInt(sc.nextLine());
            
            Employee emp = new Employee(empId, name, deptId);
            emp.display();
        } catch (NumberFormatException e) {
            System.out.println("Invalid input! Please enter numeric values for Employee ID and Department ID.");
        } catch (InvalidInputException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            sc.close();
        }
    }
}
