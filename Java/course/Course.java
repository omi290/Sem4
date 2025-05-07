package course;

public class Course {
    private String courseId;
    private String courseName;
    private int credits;

    public Course(String courseId, String courseName, int credits) {
        this.courseId = courseId;
        this.courseName = courseName;
        this.credits = credits;
    }
    

    public String getCourseInfo() {
        return "Course ID: " + courseId + ", Name: " + courseName + ", Credits: " + credits;
    }
}

