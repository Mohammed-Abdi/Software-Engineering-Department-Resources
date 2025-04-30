#include<iostream>
using namespace std;

struct student {
    string fullName, department, id;
    int age;
    struct student *link;
};

struct student *start = NULL;

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

}

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

}

void displayStudentInfo(){
    if(start == NULL){
        cout << "There is no any student record!\n";
    } else {
        struct student *displayInfo;
        displayInfo = start;

        while(displayInfo != NULL){
            cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━\n";
            cout << "\nName: " << displayInfo -> fullName << "\nAge: " << displayInfo -> age << "\nID: " << displayInfo -> id << "\nDepartment: " << displayInfo -> department;
            cout << "\n\n━━━━━━━━━━━━━━━━━━━━━━━━\n";
            displayInfo = displayInfo -> link;
        }
    }
}

void deleteFirst(){
    if(start == NULL){
        cout << "Empty Linked List";
    } else {
        struct student *df;
        df = start;
        start = start -> link;
        delete df;
    }
}

void deleteLast(){
    if(start == NULL){
        cout << "Empty Linked List";
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
}

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
            }
            search = search -> link;
        }

        search = start;

        if(isFound == true){
            while(search != NULL){
                cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━\n";
                cout << "\nName: " << search -> fullName << "\nAge: " << search -> age << "\nID: " << search -> id << "\nDepartment: " << search -> department;
                cout << "\n\n━━━━━━━━━━━━━━━━━━━━━━━━\n";
                search = search -> link;
            }
            // cout << "\nStudent with id \"" << target << "\" is found\n";
        }
    }
}

int main(){
    int choice;
    cout << "Welcome To Student Registering System\n";
    do{
        cout << "\n1. Insert Student Info InFront\n2. Insert Student Info InBack \n3. Display Students Info\n4. Delete First Student Info\n5. Delete Last Student Info\n6. Search Student\n7. Exit\n[1 - 4]: ";
        cin >> choice;
        switch(choice){
            case 1: insertStudentInfoInFront();
            cout << "\nStudent Created Successfully\n";
            break;
            case 2: insertStudentInfoInBack(); 
            cout << "\nStudent Created Successfully\n";
            break;
            case 3: displayStudentInfo(); break;
            case 4: deleteFirst();
            cout << "\nFirst Student deleted Successfully\n";
            break;
            case 5: deleteLast(); 
            cout << "\nLast Student deleted Successfully\n";
            break;
            case 6: searchStudent(); 
            cout << "\nStudent Found Successfully\n";
            break;
            case 7: cout << "Program Ended, Thank You!\n"; 
            break;
            default: cout << "404\n";
        }
    }while(choice != 7);
    return 0;
}