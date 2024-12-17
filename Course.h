#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <iostream>

class Course {
public:
    std::string courseNumber;               // Course number (e.g., "CS101")
    std::string courseTitle;                // Title of the course (e.g., "Introduction to Programming")
    std::vector<std::string> prerequisites; // List of prerequisite course numbers

    // Constructor
    Course();  // Default constructor
    Course(const std::string& number, const std::string& title, const std::vector<std::string>& prereqs);

    // Print course details
    void PrintCourseInfo() const;

    // Static method to print prerequisites as a comma-separated string
    static std::string FormatPrerequisites(const std::vector<std::string>& prereqs);
};

#endif // COURSE_H
