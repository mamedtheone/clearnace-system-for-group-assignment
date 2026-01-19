
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Student information
    string name = "";
    string studentID = "";
    string studentDept = "";
    int year = 0;

    // Subjects
    string subjects[10];
    int subjectCount = 0;

    // Departments
    string departments[5] = {
        "Engineering Library",
        "Digital Library",
        "Finance",
        "Department",
        "Dorm"
    };

    // Stats and reason
    string status[5] = {"Pending", "Pending", "Pending", "Pending", "Pending"};
    string reason[5] = {"", "", "", "", ""};

    int choice = 0;

    while (true) {
        cout << "\n==============================\n";
        cout << "   STUDENT CLEARANCE SYSTEM   \n";
        cout << "==============================\n";
        cout << "1. Enter Student Information\n";
        cout << "2. Enter Subjects Taken\n";
        cout << "3. Fill Clearance Form\n";
        cout << "4. View Clearance Status\n";
        cout << "5. Check Final Clearance\n";
        cout << "6. Exit\n";
        cout << "==============================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear input buffer

        switch(choice) {
            case 1: {
                cout << "\nEnter Full Name: ";
                getline(cin, name);

                cout << "Enter Student ID: ";
                getline(cin, studentID);

                cout << "Enter Department: ";
                getline(cin, studentDept);

                cout << "Enter Year of Study: ";
                cin >> year;
                cin.ignore();

                cout << "Student information saved.\n";
                break;
            }

            case 2: {
                cout << "\nHow many subjects were you given this year? ";
                cin >> subjectCount;
                cin.ignore();
                if (subjectCount > 10) subjectCount = 10;

                for (int i = 0; i < subjectCount; i++) {
                    cout << "Enter subject " << (i+1) << ": ";
                    getline(cin, subjects[i]);
                }

                cout << "Subjects saved.\n";
                break;
            }

            case 3: {
                if (name == "" || subjectCount == 0) {
                    cout << "Please enter student info and subjects first.\n";
                } else {
                    string answer;
                    for (int i = 0; i < 5; i++) {
                        cout << "\n" << departments[i] << ": Do you have any issues? (yes/no): ";
                        getline(cin, answer);
                        if (answer == "no") {
                            status[i] = "Cleared";
                            reason[i] = "";
                        } else {
                            status[i] = "Pending";
                            cout << "Please explain the reason: ";
                            getline(cin, reason[i]);
                        }
                    }
                    cout << "Department clearance form completed.\n";
                }
                break;
            }

            case 4: {
                cout << "\n--- CLEARANCE STATUS ---\n";
                for (int i = 0; i < 5; i++) {
                    cout << departments[i] << " : " << status[i];
                    if (status[i] == "Pending") {
                        cout << " (" << reason[i] << ")";
                    }
                    cout << endl;
                }
                break;
            }

            case 5: {
                bool cleared = true;
                for (int i = 0; i < 5; i++) {
                    if (status[i] != "Cleared") cleared = false;
                }
                cout << "\n--- FINAL CLEARANCE RESULT ---\n";
                if (cleared) cout << "STUDENT IS FULLY CLEARED ✅\n";
                else cout << "STUDENT IS NOT FULLY CLEARED ❌\n";
                break;
            }

case 6:
                cout << "Exiting program...\n";
                return 0;

default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;

}
