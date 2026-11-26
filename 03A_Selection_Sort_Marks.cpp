/*
Problem Statement 3A:
Develop a program that takes student marks as input and sorts them in ascending order using Selection Sort.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;          // Number of students
    int i, j;       // Loop index variables
    int minIndex;   // Tracks the index of the minimum element found in the unsorted subarray
    int temp;       // Temporary variable used for swapping elements
    int marks[100]; // Array to hold marks of up to 100 students

    // ==========================================
    // INPUT: NUMBER OF STUDENTS (With Validation)
    // ==========================================
    do
    {
        cout << "Enter number of students (1 to 100): ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "Invalid count! Must be between 1 and 100.\n";
    } while (n < 1 || n > 100);

    // ==========================================
    // INPUT: STUDENT MARKS (0 to 100 validation)
    // ==========================================
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

    // ==========================================
    // ALGORITHM: SELECTION SORT (Ascending Order)
    // ==========================================
    // Repeatedly finds the minimum element from the unsorted portion and puts it at the beginning
    for (i = 0; i < n - 1; i++)
    {
        // Assume the first element of the unsorted segment is the smallest
        minIndex = i;

        // Iterate through the unsorted portion to find the true minimum
        for (j = i + 1; j < n; j++)
        {
            if (marks[j] < marks[minIndex])
                minIndex = j; // Update index of current smallest value
        }

        // Swap the found minimum element with the first element of unsorted portion
        temp = marks[i];
        marks[i] = marks[minIndex];
        marks[minIndex] = temp;
    }

    // ==========================================
    // OUTPUT: DISPLAY SORTED MARKS
    // ==========================================
    cout << "\nStudent marks in ascending order:\n";
    for (i = 0; i < n; i++)
        cout << marks[i] << " ";
    cout << endl;

    return 0;
}
