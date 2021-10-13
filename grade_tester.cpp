/*
    grade_tester.cpp : This file contains the 'main' function
    Daniel Tekle
    10/2/2020
    Program: Grade tester
             Takes the scores of the students from the keyboard as input.
             Then displays all grades and the highest score, lowest score, and the average score for the course.
             Handles any invalid input with a proper message
             Handels value outside grade range [0-100] with a proper error message.
    Compiled and executed Microsoft visual studio compiler
*/
#include <iostream>
#include <string>
#include <sstream>
#include <regex>
using namespace std;


int validate(string inputTemp) {
    regex integer_expr("^(?:[0-9]|[0-9][0-9]|100|1[0-1]|[0][0])$");
    int flag = 0;

    if (regex_match(inputTemp, integer_expr)) {
        flag = 1;
    }
    else {
        flag = -1;
    }

    return flag;
}

int studentCount() {
    string strStudentGrade;
    int intStudentGrade;

    cout << "Enter number of Students: ";
    cin >> strStudentGrade; // Reads a string
    cout << endl;

    while (validate(strStudentGrade) != 1) {
        cout << "Enter valid number of Students: ";
        cin >> strStudentGrade; // Reads a string
    }

    stringstream input(strStudentGrade);
    input >> intStudentGrade; //converts string to integer data type
    //cout << "Number of Students: " << intStudentGrade << "\n" << endl;
    return intStudentGrade;
}

int studentGrades(int numStudents) {
    int arrayStudents[100];
    string tempStr;

    int maxVal = 0;
    int minVal = 100;
    int avgVal = 0;

    int tempVal = 0;
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter Student " << i + 1 << " Grade: ";
        cin >> tempStr;
        while (validate(tempStr) != 1) {
            cout << "Enter A Valid Grade For Student " << i + 1 << ": ";
            cin >> tempStr;
        }
        stringstream input(tempStr);

        input >> arrayStudents[i]; //converts string to integer data type

        if (arrayStudents[i] > 0) {
            avgVal += arrayStudents[i];
        }
        if (arrayStudents[i] > maxVal) {
            maxVal = arrayStudents[i];
        }
        if (arrayStudents[i] < minVal) {
            minVal = arrayStudents[i];
        }
    }
    cout << endl;
    if (numStudents == 0 || avgVal == 0) {
        cerr << "\nNo students!!! \n\n";
        minVal = 0;
    }
    else {
        avgVal = avgVal / numStudents;
    }
    cout << "Students grades: [ ";
    for (int i = 0; i < numStudents; i++) {
        cout << arrayStudents[i] << " ";
    }
    cout << "]\n";

    cout << "The highest student grade: " << maxVal << "\n"
        << "The lowest student grade: " << minVal << "\n"
        << "The average student grade: " << avgVal << "\n"
        << endl;
    return 0;
}

int main() {
    int repeat = 0;
    int numStudents = studentCount();
    studentGrades(numStudents);

    return 0;

}
