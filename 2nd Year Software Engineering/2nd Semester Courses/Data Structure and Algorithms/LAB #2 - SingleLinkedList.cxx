#include<iostream>
using namespace std;

struct student {
    string fullName, department, id;
    int age;
    struct student *link;
};

struct student *start = NULL;
//Add student info at the start of the linked list
void insertStudentInfoInFront(){
    string fName, mName, lName, departmentValue, idValue;
    int ageValue;

    cout << "Enter First Name: ";
    cin >> fName;
    cout << "Enter Middle Name: ";
    cin >> mName;
    cout << "Enter Last Name: ";
    cin >> lName;
    cout << "Enter Age: ";
    cin >> ageValue;
    cout << "Enter Student ID: ";
    cin >> idValue;
    cout << "Enter Department: ";
    cin >> departmentValue;

    struct student *temp;
    temp = new student;
    temp -> fullName = fName + " " + mName + " " + lName;
    temp -> id = idValue;
    temp -> age = ageValue;
    temp -> department = departmentValue;

    if(start == NULL){
        start = temp;
        start -> link = NULL;
    } else {
        temp -> link = start;
        start = temp;
    }
    cout << "\nStudent Created Successfully\n";
}
//Adds more student info
void addMoreInFront(){
    char response;
    do{
    cout << "Do you want to insert more? [y/n]: ";
    cin >> response;
    switch (response)
    {
    case 'y':
    case 'Y': insertStudentInfoInFront();
              break;
    case 'n':
    case 'N': cout << "Redirecting to homepage...\n";
              break;
    default: cout << "404: Wrong Input!\n";
    }
    } while(response != 'n' && response != 'N');
}
//Add student info at the end of the linked list
void insertStudentInfoInBack(){
    string fName, mName, lName, departmentValue, idValue;
    int ageValue;

    cout << "Enter First Name: ";
    cin >> fName;
    cout << "Enter Middle Name: ";
    cin >> mName;
    cout << "Enter Last Name: ";
    cin >> lName;
    cout << "Enter Age: ";
    cin >> ageValue;
    cout << "Enter Student ID: ";
    cin >> idValue;
    cout << "Enter Department: ";
    cin >> departmentValue;

    struct student *temp;
    temp = new student;
    temp -> fullName = fName + " " + mName + " " + lName;
    temp -> id = idValue;
    temp -> age = ageValue;
    temp -> department = departmentValue;

    if(start == NULL){
        start = temp;
        start -> link = NULL;
    } else {
        struct student *newPointer;
        newPointer = start;

        while(newPointer -> link != NULL){
            newPointer = newPointer -> link;
        }

        newPointer -> link = temp;
        temp -> link = NULL;
    }

    cout << "\nStudent Created Successfully\n";

}
//Adds more student info
void addMoreInBack(){
    char response;
    do{
    cout << "Do you want to insert more? [y/n]: ";
    cin >> response;
    switch (response)
    {
    case 'y':
    case 'Y': insertStudentInfoInBack();
              break;
    case 'n':
    case 'N': cout << "Redirecting to homepage...\n";
              break;
    default: cout << "404: Wrong Input!\n";
    }
    } while(response != 'n' && response != 'N');
}
//Display all student records
void displayStudentInfo(){
    if(start == NULL){
        cout << "There is no any student record!\n";
    } else {
        struct student *displayInfo;
        displayInfo = start;

        while(displayInfo != NULL){
            cout << "\n════════════════════\n";
            cout << "Name: " << displayInfo -> fullName 
                 << "\nAge: " << displayInfo -> age 
                 << "\nID: " << displayInfo -> id 
                 << "\nDepartment: " << displayInfo -> department;
            cout << "\n════════════════════\n";
            displayInfo = displayInfo -> link;
        }
    }
}
//Delete the student found at the start of the linked list
void deleteFirst(){
    if(start == NULL){
        cout << "Empty Linked List";
    } else {
        struct student *df;
        df = start;
        start = start -> link;
        delete df;
        cout << "\nFirst Student deleted Successfully\n";
    }
}
//Delete the student found at the end of the linked list
void deleteLast(){
    if(start == NULL){
        cout << "Empty Linked List";
    } else {
        if(start -> link == NULL){
            delete start;
            start = NULL;
        } else {
            struct student *newPointer, *newPointer1;
        newPointer = start;

        while(newPointer -> link != NULL){
            newPointer1 = newPointer;
            newPointer = newPointer -> link;
        }

        newPointer1 -> link = NULL;
        delete newPointer;
    }
    cout << "\nLast Student deleted Successfully\n";
    }
}
//Searchs a student record by ID and displays it
void searchStudent(){
    if(start == NULL){
        cout << "\nThere is no any Student record!";
    } else {
        struct student *search;
        search = start;

        bool isFound = false;
        string target;
        cout << "Enter the ID: ";
        cin >> target;

        while(search != NULL){
            if(search -> id == target){
                isFound = true;
                //Student Record
                cout << "\n════════════════════\n";
                cout << "Name: " << search -> fullName 
                << "\nAge: " << search -> age 
                << "\nID: " << search -> id 
                << "\nDepartment: " << search -> department;
                cout << "\n════════════════════\n"
                     << "\nStudent is Found Successfully\n";
        }
        search = search -> link;
        }

        if(isFound == false){
            cout << "Student with ID \"" << target << "\" is not found!\n";
        }
    }
}

int main(){
    int choice;
    cout << "Welcome To Student Registering System\n";
    do{
        cout << "\n1. Insert Student Info InFront\n2. Insert Student Info InBack \n3. Display Students Info\n4. Delete First Student Info\n5. Delete Last Student Info\n6. Search Student\n7. Exit\n\nChoose[1 - 4]: ";
        cin >> choice;
        switch(choice){
            case 1: insertStudentInfoInFront();
                    addMoreInFront();
                    break;
            case 2: insertStudentInfoInBack();
                    addMoreInBack();
                    break;
            case 3: displayStudentInfo(); 
                    break;
            case 4: deleteFirst();
                    break;
            case 5: deleteLast(); 
                    break;
            case 6: searchStudent(); 
                    break;
            case 7: cout << "Program Ended, Thank You!\n©2025 | Mohammed Abdi"; 
                    break;
            default: cout << "404: request was not found\n";
        }
    }while(choice != 7);
    return 0;
}