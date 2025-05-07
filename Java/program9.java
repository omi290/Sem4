import java.util.*;

class Bank {
    String name;
    String address;
    int account_no;
    public static int acc_count = 1000;
    double balance = 0.0;

    Bank(String name, String address, double balance) {
        this.name = name;
        this.account_no = ++acc_count;
        this.balance = balance;
        this.address = address;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposit successful! New balance: " + balance);
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawal successful! New balance: " + balance);
        } else {
            System.out.println("Invalid withdrawal amount or insufficient balance.");
        }
    }

    void change_address(String add) {
        this.address = add;
        System.out.println("Address updated successfully.");
    }

    void display() {
        System.out.println("\nAccount Details:");
        System.out.println("Name: " + name);
        System.out.println("Address: " + address);
        System.out.println("Account No.: " + account_no);
        System.out.println("Balance: " + balance);
    }
}

public class program9 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Bank[] accounts = new Bank[10]; 
        int count = 0; 

        while (true) {
            System.out.println("\nMain Menu:");
            System.out.println("1. Create New Account");
            System.out.println("2. Access Existing Account");
            System.out.println("3. Display All Accounts");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");

            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    if (count >= accounts.length) {
                        System.out.println("Account limit reached! Cannot create more accounts.");
                        break;
                    }
                    sc.nextLine(); // Consume newline
                    System.out.print("Enter your name: ");
                    String name = sc.nextLine();
                    System.out.print("Enter your address: ");
                    String address = sc.nextLine();
                    System.out.print("Enter initial deposit amount: ");
                    double balance = sc.nextDouble();
                    accounts[count] = new Bank(name, address, balance);
                    System.out.println("Account created successfully! Your account number is " + accounts[count].account_no);
                    count++;
                    break;

                case 2:
                    System.out.print("Enter account number: ");
                    int accNo = sc.nextInt();
                    Bank selectedAccount = null;

                    for (int i = 0; i < count; i++) {
                        if (accounts[i].account_no == accNo) {
                            selectedAccount = accounts[i];
                            break;
                        }
                    }

                    if (selectedAccount == null) {
                        System.out.println("Account not found.");
                        break;
                    }

                    while (true) {
                        System.out.println("\nAccount Menu for " + selectedAccount.name);
                        System.out.println("1. Deposit");
                        System.out.println("2. Withdraw");
                        System.out.println("3. Change Address");
                        System.out.println("4. Display Account Details");
                        System.out.println("5. Back to Main Menu");
                        System.out.print("Enter your choice: ");

                        int accChoice = sc.nextInt();
                        switch (accChoice) {
                            case 1:
                                System.out.print("Enter deposit amount: ");
                                double depositAmount = sc.nextDouble();
                                selectedAccount.deposit(depositAmount);
                                break;
                            case 2:
                                System.out.print("Enter withdrawal amount: ");
                                double withdrawAmount = sc.nextDouble();
                                selectedAccount.withdraw(withdrawAmount);
                                break;
                            case 3:
                                sc.nextLine(); // Consume newline
                                System.out.print("Enter new address: ");
                                String newAddress = sc.nextLine();
                                selectedAccount.change_address(newAddress);
                                break;
                            case 4:
                                selectedAccount.display();
                                break;
                            case 5:
                                System.out.println("Returning to Main Menu...");
                                break;
                            default:
                                System.out.println("Invalid choice, please try again.");
                        }
                        if (accChoice == 5) break;
                    }
                    break;

                case 3:
                    if (count == 0) {
                        System.out.println("No accounts found.");
                    } else {
                        System.out.println("\nList of Accounts:");
                        for (int i = 0; i < count; i++) {
                            System.out.println("Account No: " + accounts[i].account_no + " | Name: " + accounts[i].name + " | Balance: " + accounts[i].balance);
                        }
                    }
                    break;

                case 4:
                    System.out.println("Thank you for using our banking system.");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice, please try again.");
            }
        }
    }
}

