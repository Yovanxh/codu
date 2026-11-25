/*
Problem Statement 3A:
Develop a program that takes student marks as input and sorts them in ascending order using Selection Sort.
Fixes: Validates 1 <= n <= 100 and ensures each mark is within 0 to 100.
*/

#include <iostream>
using namespace std;

int main()
{
    int n, i, j, minIndex, temp;
    int marks[100];

    do
    {
        cout << "Enter number of students (1 to 100): ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "Invalid count! Must be between 1 and 100.\n";
    } while (n < 1 || n > 100);

    cout << "Enter marks of " << n << " students (0 to 100):\n";
    for (i = 0; i < n; i++)
    {
        do
        {
            cout << "Student " << i + 1 << ": ";
            cin >> marks[i];
            if (marks[i] < 0 || marks[i] > 100)
                cout << "Invalid marks! Enter a value between 0 and 100.\n";
        } while (marks[i] < 0 || marks[i] > 100);
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
