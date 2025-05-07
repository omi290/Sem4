/*import javax.swing.*;
import java.awt.event.*;
public class HelloWorldSwing extends JFrame implements ActionListener{
    JTextField txt1;
    HelloWorldSwing(){
        setTitle("Hello world swing");
        setLayout(null);
        setSize(500,300);
        JLabel label = new JLabel("Hello , swing GUI!",JLabel.CENTER);
        add(label);
        JButton btn = new JButton("DEMO");
        btn.setBounds(100,100,120,40);
        add(btn);
        btn.addActionListener(this);
        txt1 = new JTextField();
        txt1.setBounds(250,100,180,20);
        add(txt1);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
       setVisible(true);
    }
    public void actionPerformed(ActionEvent e){
        txt1.setText("I clicked on DEMO");
    }
    public static void main(String[] args){
       HelloWorldSwing h = new HelloWorldSwing();
       
    }
}
*/
/*import javax.swing.*;
import java.awt.event.*;
public class AddTwoNumbers extends JFrame implements ActionListener{
    JLabel label1,label2,resultLabel;
    JTextField text1,text2;
    JButton addButton,mulButton;
    AddTwoNumbers(){
        setTitle("Add Two Numbers");
        setSize(400,250);
        label1 = new JLabel("Enter first no");
        label1.setBounds(30,30,150,25);
        text1 = new JTextField();
        text1.setBounds(180,30,150,25);
        label2 = new JLabel("Enter second no");
        label2.setBounds(30,70,150,25);
        text2= new JTextField();
        text2.setBounds(180,70,150,25);
        addButton = new JButton("ADD");
        addButton.setBounds(130,110,100,30);
        addButton.addActionListener(this);
        mulButton = new JButton("MULTIPLY");
        mulButton.setBounds(260,110,100,30);
        resultLabel = new JLabel("Result : ");
        resultLabel.setBounds(30,160,300,25);
        add(label1);
        add(text1);
        add(label2);
        add(text2);
        add(addButton);
        add(mulButton);
        add(resultLabel);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
    public void actionPerformed(ActionEvent e){
        try{
            int num1 = Integer.parseInt(text1.getText());
            int num2 = Integer.parseInt(text2.getText());
            int sum = num1+num2;
            resultLabel.setText("Result : "+sum);

        }
        catch(NumberFormatException ex){
            resultLabel.setText("Please enter vaild integer");
        }

    }
    public static void main(String [] args){
        new AddTwoNumbers();
    }
}*/
import javax.swing.*;
import java.awt.event.*;
/*public class LoginForm extends JFrame implements ActionListener {
    JTextField userTxt ;
    JPasswordField passField;
    void createGui(){
        JFrame frame = new JFrame("Login Form");
        JLabel userlabel = new JLabel("Username :");
        JLabel passlabel = new JLabel("Password :");
        userTxt = new JTextField();
        passField = new JPasswordField();
        JButton  login = new JButton("Login");
        JButton reset=new JButton("Reset");
        login.addActionListener(this);
        userlabel.setBounds(30, 30, 80, 30);
        userTxt.setBounds(120,30,180,30);
        passlabel.setBounds(30,70,80,30);
        passField.setBounds(120,70,150,30);
        login.setBounds(120,120,80,30);
        frame.add(userlabel );
        frame.add(userTxt );
        frame.add(passlabel );
        frame.add(passField );
        frame.add(login );
        frame.setSize(350,220);
        frame.setLayout(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
    public void actionPerformed(ActionEvent e){
       String user = userTxt.getText();
       String pass = new String(passField.getPassword());
       if(user.equals("admin")&&pass.equals("1234")){
        JOptionPane.showMessageDialog(this,"Login Successful");
       }
       else{
        JOptionPane.showMessageDialog(this,"Invalid Credentials");
       }


    }
    public static void main(String []args){
        LoginForm ob = new LoginForm();
        ob.createGui();
    }
   
}*/
/*public class CheckBox{
    public static void main(String args[])
    {
        JFrame frame = new JFrame("check box example");
        frame.setSize(400,400);
        JCheckBox c1 = new JCheckBox("Java");
        JCheckBox c2 = new JCheckBox("Python");
        c1.setBounds(50, 50 , 100 ,30);
        c2.setBounds(50,80,100,30);
        JButton btn = new JButton("Submit");
        btn.setBounds(50,100,100,30);

        btn.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                String msg= "selected :";
                if(c1.isSelected()) msg += "Java";
                if(c2.isSelected()) msg += "Python";
                JOptionPane.showMessageDialog(frame,msg);

            }
        });
        frame.add(c1);
        frame.add(c2);
        frame.add(btn);
        frame.setLayout(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
    
}*/

