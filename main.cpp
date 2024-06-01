#include <iostream>
#include <conio.h>
#include <limits> // Include <limits> for input validation
using namespace std;
//functions
void main_menu();
void add_new_marks(int n);
void print_marks_sheet();
void print_grade_sheet();
void print_data_summary();
//global array
int marks[10];
//create a menu
int main()
{
    int n;
    do
    {
        //call main_menu function
        main_menu();
        while (!(cin >> n) || cin.peek() != '\n') { // Input validation
            cout << "\n\tInvalid Input! Please choose a number from the menu (1-5)" << endl;
            main_menu();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
        //what will happen after choose a number from a displayed menu
        switch(n)
        {
        case 1 :
            cout << "\n[1] Add new Student Marks" << endl;
            add_new_marks(n);
            break;
        case 2 :
            cout << "\n[2] Print Marks Sheet" << endl;
            print_marks_sheet();
            break;
        case 3 :
            cout << "\n[3] Print Grade Sheet" << endl;
            print_grade_sheet();
            break;
        case 4 :
            cout << "\n[4] Print Summary Sheet" << endl;
            print_data_summary();
            break;
        case 5 :
            cout << "\n[5] Exit" << endl;
            cout << "\n\tEnd of the Operation! See you Later!" << endl;
            break;
        default :
            cout << "\n\tInvalid Input! Please choose a number from the menu (1-5)" << endl;
            break;
        }
    }
    while(n!=5);
}
void main_menu()
{
    //display menu
    int n;
    cout << "\n" << endl;
    cout << "--------------------------" << endl;
    cout << "  Result Sheet Generator " << endl;
    cout << "--------------------------" << endl;
    cout << "[1] Add new Student Marks" << endl;
    cout << "[2] Print Mark Sheet" << endl;
    cout << "[3] Print Grade Sheet" << endl;
    cout << "[4] Print Summary Sheet" << endl;
    cout << "[5] Exit" << endl;
    cout << "--------------------------" << endl;
    cout << "\n\nChoose a number from the Menu : ";
}
void add_new_marks(int n)
{
    //validate entered marks
    cout << "\nEnter Marks (0-100) of the 10 Students" << endl;
    for (int i=0 ; i<10 ; i++)
        {
            cout << "Enter the mark of Student " << i+1 << ": ";
            while (!(cin >> marks[i]) || cin.peek() != '\n' || marks[i] < 0 || marks[i] > 100 || marks[i] != static_cast<int>(marks[i])) {
                cout << "Invalid input! Mark must be an integer between 0 and 100. Please enter again! ";
                cout << "\nEnter the mark of Student " << i+1 << ": ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
}
}
void print_marks_sheet()
{
    //display marks sheet
    cout << "\n" << endl;
    cout << "-------------" << endl;
    cout << " Marks Sheet " << endl;
    cout << "-------------" << endl;
    cout << "\nID" << "\t" << "SUB1\n" << endl;
    for (int i=0 ; i<10 ; i++)
        cout << i+1 << "\t " << marks[i] << endl;
    cout << "-------------" << endl;
}
void print_grade_sheet()
{
    //earned grade
    string grade;
    cout << "\n" << endl;
    cout << "-------------" << endl;
    cout << " Grade Sheet " << endl;
    cout << "-------------" << endl;
    cout << "\nID" << "\t" << "SUB1\n" << endl;
    for (int i=0 ; i<10 ; i++)
    {
        //grade calculation formulas
        if (marks[i] >= 90 && marks[i] <=100)
             grade="A+";
        if (marks[i] >= 80 && marks[i] <=89)
             grade="A";
        if (marks[i] >= 70 && marks[i] <=79)
             grade="B+";
        if (marks[i] >= 60 && marks[i] <=69)
             grade="B";
        if (marks[i] >= 50 && marks[i] <=59)
             grade="C+";
        if (marks[i] >= 40 && marks[i] <=49)
             grade="C";
        if (marks[i] >= 30 && marks[i] <=39)
             grade="D+";
        if (marks[i] >= 20 && marks[i] <=29)
             grade="D";
        if (marks[i] < 20)
             grade="E";
        cout << i+1 << "\t " << grade << endl;
    }
    cout << "-------------" << endl;
}
void print_data_summary()
{
    //display class summary with Average,min and max
    float sum=0;
    int i;
    cout << "\n" << endl;
    cout << "----------------------" << endl;
    cout << "    Class Summary     " << endl;
    cout << "----------------------" << endl;
    cout << "\t\tSUB1" << endl;
    //calculate Average
    for (int i=0 ; i<10 ; i++)
            sum += marks[i];
    cout << "Average" << "\t\t" << sum/10 << endl;
    //find min and max
    int max=marks[0],min=marks[0];
    for (i=0 ; i<10 ; i++)
    {
        if (marks[i]>max)
            max=marks[i];
        else if (marks[i]<min)
            min=marks[i];
    }
    cout << "\nMin" << "\t\t" << min << endl;
    cout << "Max" << "\t\t" << max << endl;
    cout << "----------------------" << endl;
}
