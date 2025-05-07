import java.util.*;
abstract class Shape {
    abstract int rectangleArea(int length, int breadth);
    abstract int squareArea(int side);
    abstract double circleArea(double radius);
}

class Area extends Shape {
    @Override
    int rectangleArea(int length, int breadth) {
        return length * breadth;
    }

    @Override
    int squareArea(int side) {
        return side * side;
    }

    @Override
    double circleArea(double radius) {
        return Math.PI * radius * radius;
    }
}

public class program12 {
    public static void main(String[] args) {
        Area area = new Area();
        Scanner sc = new Scanner(System.in);
        int l,b,a;
        float r;
        System.out.println("enter l and b ");
        l=sc.nextInt();
        b=sc.nextInt();
        System.out.println("enter side of square ");
        a=sc.nextInt();
        System.out.println("enter redius of circle ");
        r=sc.nextFloat();
        int rectArea = area.rectangleArea(l, b);
        int squareArea = area.squareArea(a);
        double circleArea = area.circleArea(r);
        
        System.out.println("Area of Rectangle: " + rectArea);
        System.out.println("Area of Square: " + squareArea);
        System.out.println("Area of Circle: " + circleArea);
        sc.close();
    }
}

