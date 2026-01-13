#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
    string department;

    void display() {
    	cout << "+-----------------------------------+\n";
        cout << "| NAME: " << name <<"               "<< endl;
        cout << "+-----------------------------------+\n";
        cout << "| Roll No: " << rollNo << "         "<<endl;
        cout << "+-----------------------------------+\n";
        cout << "| DEPARTMENT: " << department <<"   "<< endl;
        cout << "+-----------------------------------+\n";
    }
};

class StudentManagementSystem {
private:
    Student student[100]; // fixed size array
    int count = 0;        // number of students added

public:
    // Add student
    void AddStudent(string name, int rollNo, string department) {
        // check duplicate
        for (int i = 0; i < count; i++) {
            if (student[i].rollNo == rollNo) {
                cout << "STUDENT WITH ROLL NO " << rollNo << " ALREADY EXISTS.\n";
                return;
            }
        }
        student[count].name = name;
        student[count].rollNo = rollNo;
        student[count].department = department;
        count++;
        cout << "STUDENT ADDED SUCCESSFULLY.\n";
    }

    // Remove student
    void RemoveStudent(int rollNo) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (student[i].rollNo == rollNo) {
                // shift left
                for (int j = i; j < count - 1; j++) {
                    student[j] = student[j + 1];
                }
                count--;
                cout << "STUDENT DATA DELETED SUCCESSFULLY.\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "STUDENT WITH ROLL NO " << rollNo << " NOT FOUND.\n";
        }
    }

    // Search student
    void SearchStudent(int rollNo) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (student[i].rollNo == rollNo) {
                cout << "STUDENT FOUND:\n";
                student[i].display();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "STUDENT WITH ROLL NO " << rollNo << " NOT FOUND.\n";
        }
    }

    // Display all students
    void DisplayAll() {
        if (count == 0) {
            cout << "No students added yet.\n";
            return;
        }
        cout << "All Students:\n";
        for (int i = 0; i < count; i++) {
            student[i].display();
        }
    }
};

int main() {
    StudentManagementSystem s;
    string name, department;
    int rollNo, choice;

    do {
        cout << "\n<---STUDENT INFORMATION--->\n";
        cout << "1. ADD STUDENT\n";
        cout << "2. FIND STUDENT\n";
        cout << "3. DELETE STUDENT DATA\n";
        cout << "4. DISPLAY ALL STUDENTS\n";
        cout << "5. EXIT\n";
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cin.ignore(); // clear newline before getline
            cout << "Enter Name: ";
            getline(cin, name); // full name with spaces

            cout << "Enter Roll No: ";
            cin >> rollNo;
            cin.ignore(); // clear newline again

            cout << "Enter Department: ";
            getline(cin, department); // full department with spaces

            s.AddStudent(name, rollNo, department);
            break;

        case 2:
            cout << "Enter Roll No to search: ";
            cin >> rollNo;
            s.SearchStudent(rollNo);
            break;

        case 3:
            cout << "Enter Roll No to delete: ";
            cin >> rollNo;
            s.RemoveStudent(rollNo);
            break;

        case 4:
            s.DisplayAll();
            break;

        case 5:
            cout << "EXITING...\n";
            return 0;

        default:
            cout << "Invalid Choice! Try Again.\n";
            break;
        }
    } while (1);

    return 0;
}