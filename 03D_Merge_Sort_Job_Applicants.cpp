/*
Problem Statement 3D:
Develop a Merge Sort or Quick Sort based system to sort job applicants based on experience
in descending order so that the most experienced candidates appear first.
Fixes: Validates 1 <= n <= 100 and rejects negative years of experience.
*/

#include <iostream>
using namespace std;

void merge(int experience[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = experience[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = experience[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
            experience[k++] = L[i++];
        else
            experience[k++] = R[j++];
    }

    while (i < n1)
        experience[k++] = L[i++];
    while (j < n2)
        experience[k++] = R[j++];
}

void mergeSort(int experience[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(experience, left, mid);
        mergeSort(experience, mid + 1, right);
        merge(experience, left, mid, right);
    }
}

int main()
{
    int n, experience[100];

    do
    {
        cout << "Enter number of job applicants (1 to 100): ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "Invalid count! Must be between 1 and 100.\n";
    } while (n < 1 || n > 100);

    cout << "Enter experience of each applicant (in years >= 0):\n";
    for (int i = 0; i < n; i++)
    {
        do
        {
            cout << "Applicant " << i + 1 << ": ";
            cin >> experience[i];
            if (experience[i] < 0)
                cout << "Invalid experience! Cannot be negative.\n";
        } while (experience[i] < 0);
    }

    mergeSort(experience, 0, n - 1);

    cout << "\nJob applicants sorted by experience (descending order):\n";
    for (int i = 0; i < n; i++)
        cout << "Applicant " << i + 1 << " - " << experience[i] << " years\n";

    return 0;
}
