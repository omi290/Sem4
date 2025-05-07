package enrollment;

import student.Student;
import course.Course;

public class Enrollment {
    private Student student;
    private Course course;

    public Enrollment(Student student, Course course) {
        this.student = student;
        this.course = course;
    }

    public String getEnrollmentInfo() {
        return student.getStudentInfo() + " is enrolled in " + course.getCourseInfo();
    }
}
