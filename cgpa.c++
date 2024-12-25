#include <iostream>
#include <vector>

using namespace std;

struct Course {
    double gradePoints;
    int creditHours;
};

double calculateGPA(const vector<Course>& courses) {
    double totalGradePoints = 0;
    int totalCreditHours = 0;

    for (const auto& course : courses) {
        totalGradePoints += course.gradePoints * course.creditHours;
        totalCreditHours += course.creditHours;
    }

    return (totalCreditHours > 0) ? (totalGradePoints / totalCreditHours) : 0;
}

int main() {
    int numSemesters;
    cout<<endl;
    cout << "Enter the number of semesters: ";
    cin >> numSemesters;
    cout<<endl;

    vector<double> semesterGPAs;
    int totalCreditsAllSemesters = 0;
    double totalGradePointsAllSemesters = 0;

    for (int i = 0; i < numSemesters; ++i) {
        int numCourses;
        cout << "\nEnter the number of courses for semester " << (i + 1) << ": ";
        cin >> numCourses;

        vector<Course> courses(numCourses);
        for (int j = 0; j < numCourses; ++j) {
            char grade;
            int creditHours;

            cout << "Enter grade (A, B, C, D, F) for course " << (j + 1) << ": ";
            cin >> grade;
            cout << "Enter credit hours for course " << (j + 1) << ": ";
            cin >> creditHours;
            cout<<endl;

            double gradePoints = 0;
            switch (grade) {
            
                case 'A':
                 gradePoints = 4.0;
                  break;

                case 'B':
                 gradePoints = 3.0;
                  break;

                case 'C':
                 gradePoints = 2.0;
                  break;

                case 'D':
                 gradePoints = 1.0;
                  break;

                case 'F':
                 gradePoints = 0.0;
                  break;

                default:
                 cout << "Invalid grade entered. Please use A, B, C, D, or F.\n"; --j;
                  continue;
            }

            courses[j] = { gradePoints, creditHours };
        }

        double semesterGPA = calculateGPA(courses);
        semesterGPAs.push_back(semesterGPA);

        int totalCreditsThisSemester = 0;
        double totalGradePointsThisSemester = 0;
        for (const auto& course : courses) {
            totalCreditsThisSemester += course.creditHours;
            totalGradePointsThisSemester += course.gradePoints * course.creditHours;
        }

        totalCreditsAllSemesters += totalCreditsThisSemester;
        totalGradePointsAllSemesters += totalGradePointsThisSemester;

        cout << "\nGPA for semester " << (i + 1) << ": " << semesterGPA << "\n";
    }

    double CGPA = (totalCreditsAllSemesters > 0) ? (totalGradePointsAllSemesters / totalCreditsAllSemesters) : 0;

    cout<<endl;
    cout << "\nOverall CGPA: " << CGPA << "\n";

    return 0;
}