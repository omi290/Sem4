import java.util.*;

abstract class Temperature {
    double temp;
    
    void setTempData(double temp) {
        this.temp = temp;
    }
    
    abstract void changeTemp();
}

class Fahrenheit extends Temperature {
    double ctemp;

    @Override
    void changeTemp() {
        ctemp = (5.0 / 9) * (temp - 32);
        System.out.println(temp + "F in Celsius is: " + ctemp + "C");
    }
}

class Celsius extends Temperature {
    double ftemp;

    @Override
    void changeTemp() {
        ftemp = (9.0 / 5) * temp + 32;
        System.out.println(temp + "C in Fahrenheit is: " + ftemp + "F");
    }
}

public class program13{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter temperature in Fahrenheit: ");
        double fTemp = sc.nextDouble();
        Fahrenheit f = new Fahrenheit();
        f.setTempData(fTemp);
        f.changeTemp();
        
        System.out.print("Enter temperature in Celsius: ");
        double cTemp = sc.nextDouble();
        Celsius c = new Celsius();
        c.setTempData(cTemp);
        c.changeTemp();

        sc.close();
    }
}
