#include "Course.h"

// Constructor implementation
Course::Course(const std::string& number, const std::string& title, const std::vector<std::string>& prereqs)
    : courseNumber(number), courseTitle(title), prerequisites(prereqs) {}

// Method to print course details
void Course::PrintCourseInfo() const {
    std::cout << "Course Number: " << courseNumber << "\n";
    std::cout << "Title: " << courseTitle << "\n";

    if (!prerequisites.empty()) {
        std::cout << "Prerequisites: " << FormatPrerequisites(prerequisites) << "\n";
    } else {
        std::cout << "Prerequisites: None\n";
    }
}

// Static method to format prerequisites as a comma-separated string
std::string Course::FormatPrerequisites(const std::vector<std::string>& prereqs) {
    std::string formatted;
    for (size_t i = 0; i < prereqs.size(); ++i) {
        formatted += prereqs[i];
        if (i < prereqs.size() - 1) {
            formatted += ", ";
        }
    }
    return formatted;
}
