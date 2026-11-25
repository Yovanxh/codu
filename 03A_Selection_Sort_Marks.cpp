/*
Problem Statement 3A:
Develop a program that takes student marks as input and sorts them in ascending order using Selection Sort.
*/

#include <iostream>
using namespace std;

int main()
{
    int n, i, j, minIndex, temp;
    cout << "Enter number of students: ";
    cin >> n;

    int marks[100];
    cout << "Enter marks of " << n << " students:\n";
    for (i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (marks[j] < marks[minIndex])
                minIndex = j;
        }
        temp = marks[i];
        marks[i] = marks[minIndex];
        marks[minIndex] = temp;
    }

    cout << "\nStudent marks in ascending order:\n";
    for (i = 0; i < n; i++)
        cout << marks[i] << " ";
    cout << endl;

    return 0;
}
