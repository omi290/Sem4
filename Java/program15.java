import student.Student;
import course.Course;
//import enrollment.Enrollment;

public class program15 {
    public static void main(String[] args) {
        Student student = new Student("S101", "Om prakash", 20);
        Course course = new Course("PCS408", "Java Programing", 4);
      //  Enrollment enrollment = new Enrollment(student, course);

        System.out.println(student.getStudentInfo());
        System.out.println(course.getCourseInfo());
       
  }
}
