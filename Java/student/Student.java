package student;

public class Student {
    private String id;
    private String name;
    private int age;

    public Student(String id, String name, int age) {
        this.id = id;
        this.name = name;
        this.age = age;
    }

    public String getStudentInfo() {
        return "Student ID: " + id + ", Name: " + name + ", Age: " + age;
    }
}

