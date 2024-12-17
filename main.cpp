#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include "Course.h"

using namespace std;

// Global hash table to store courses
unordered_map<string, Course> courseTable;

// Function declarations
void LoadCoursesFromFile(const string& fileName);
void PrintAllCourses();
void PrintCourseInformation(const string& courseNumber);
void DisplayMenu();


/**********************************************************
*   LoadCoursesFromFile()                                 *
*                                                         *
*   Load a list of courses from a file from               *
*   the user with error handling                          *
***********************************************************/
void LoadCoursesFromFile(const string& fileName) {
    ifstream inFile(fileName);
    if (!inFile) {
        cout << "Error: Unable to open file.\n";
        return;
    }

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string courseNumber, courseTitle, prereq;
        vector<string> prerequisites;

        getline(ss, courseNumber, ',');
        getline(ss, courseTitle, ',');

        while (getline(ss, prereq, ',')) {
            prerequisites.push_back(prereq);
        }

        if (courseTable.find(courseNumber) != courseTable.end()) {
            cout << "Error: Duplicate course number found: " << courseNumber << endl;
            inFile.close();
            return;
        }

        // Create a Course object and insert it into the hash table
        courseTable[courseNumber] = Course(courseNumber, courseTitle, prerequisites);
    }

    inFile.close();
    cout << "Courses successfully loaded.\n";
}

/**********************************************************
*   PrintAllCourses()                                     *
*                                                         *
*   Print each course from hash table in a                *
*   formatted order                                       *
***********************************************************/
void PrintAllCourses() {
    if (courseTable.empty()) {
        cout << "No courses loaded. Please load a file first.\n";
        return;
    }

    vector<string> courseKeys;
    for (const auto& pair : courseTable) {
        courseKeys.push_back(pair.first);
    }

    sort(courseKeys.begin(), courseKeys.end());

    for (const string& key : courseKeys) {
        const Course& course = courseTable[key];
        cout << course.courseNumber << ": " << course.courseTitle << endl;
    }
}

/**********************************************************
 *  PrintCourseInformation()                             *
 *                                                       * 
 * Prints information about a specific course            *
 * *******************************************************/
void PrintCourseInformation(const string& courseNumber) {
    auto it = courseTable.find(courseNumber);
    if (it == courseTable.end()) {
        cout << "Error: Course not found.\n";
        return;
    }

    const Course& course = it->second;
    course.PrintCourseInfo(); // Use the class method to print course details
}

/*********************************************************
 *  DisplayMenu()                                        *
 *                                                       * 
 *  Displays the menu options for the user               *
 * ******************************************************/
void DisplayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Load File Data\n";
    cout << "2. Print Course List\n";
    cout << "3. Print Course Information\n";
    cout << "9. Exit\n";
    cout << "What would you like to do? ";
}

int main() {
    int choice = 0;
    while (choice != 9) {
        DisplayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                string fileName;
                cout << "Enter the file name: ";
                cin >> fileName;
                LoadCoursesFromFile(fileName);
                break;
            }
            case 2:
                PrintAllCourses();
                break;
            case 3: {
                string courseNumber;
                cout << "Enter course number: ";
                cin >> courseNumber;
                PrintCourseInformation(courseNumber);
                break;
            }
            case 9:
                cout << "Thanks for using the Course Selector!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
