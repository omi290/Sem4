import java.util.*;

interface Volume {
    void displayVolume();
}

class Cone implements Volume {
    double radius, height;

    Cone(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    @Override
    public void displayVolume() {
        double volume = (1.0 / 3) * Math.PI * radius * radius * height;
        System.out.println("Volume of Cone: " + volume);
    }
}

class Hemisphere implements Volume {
    double radius;

    Hemisphere(double radius) {
        this.radius = radius;
    }

    @Override
    public void displayVolume() {
        double volume = (2.0 / 3) * Math.PI * radius * radius * radius;
        System.out.println("Volume of Hemisphere: " + volume);
    }
}

class Cylinder implements Volume {
    double radius, height;

    Cylinder(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    @Override
    public void displayVolume() {
        double volume = Math.PI * radius * radius * height;
        System.out.println("Volume of Cylinder: " + volume);
    }
}

public class program14{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter radius and height of Cone: ");
        double coneRadius = sc.nextDouble();
        double coneHeight = sc.nextDouble();
        Cone cone = new Cone(coneRadius, coneHeight);
        
        System.out.print("Enter radius of Hemisphere: ");
        double hemiRadius = sc.nextDouble();
        Hemisphere hemisphere = new Hemisphere(hemiRadius);

        System.out.print("Enter radius and height of Cylinder: ");
        double cylRadius = sc.nextDouble();
        double cylHeight = sc.nextDouble();
        Cylinder cylinder = new Cylinder(cylRadius, cylHeight);

        System.out.println();
        cone.displayVolume();
        hemisphere.displayVolume();
        cylinder.displayVolume();

        sc.close();
    }
}
