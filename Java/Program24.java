import javax.swing.*;
import java.awt.event.*;

public class Program24 extends JFrame implements ActionListener {
    JLabel label1, label2;
    JTextField text1, text2;
    JButton reset, exit, count_vowel;

    Program24() {
        setTitle("Vowels Counting");
        setSize(450, 350);
        setLayout(null);

        label1 = new JLabel("Enter String");
        label1.setBounds(30, 30, 150, 25);
        text1 = new JTextField();
        text1.setBounds(180, 30, 200, 25);
        label2 = new JLabel("Vowels count_vowels");
        label2.setBounds(30, 70, 150, 25);
        text2 = new JTextField();
        text2.setBounds(180, 70, 200, 25);
        count_vowel = new JButton("Count Vowels");
        count_vowel.setBounds(30, 110, 150, 30);
        count_vowel.addActionListener(this);
        reset = new JButton("Reset");
        reset.setBounds(190, 110, 90, 30);
        reset.addActionListener(this);
        exit = new JButton("Exit");
        exit.setBounds(290, 110, 90, 30);
        exit.addActionListener(this);
        add(label1);
        add(text1);
        add(label2);
        add(text2);
        add(count_vowel);
        add(reset);
        add(exit);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        String clickbtn = e.getActionCommand();
        String s = text1.getText().toLowerCase();
        if (clickbtn.equals("Count Vowels")) {
            
            int count_vowels = 0;
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    count_vowels++;
                }
            }
            text2.setText(String.valueOf(count_vowels));
        } 
        else if (clickbtn.equals("Reset")) {
            text1.setText("");
            text2.setText("");
        } 
        else if (clickbtn.equals("Exit")) {
            System.exit(0);
        }
    }

    public static void main(String[] args) {
        new Program24();
    }
}
