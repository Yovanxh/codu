/*
Problem Statement 3D:
Develop a Merge Sort or Quick Sort based system to sort job applicants based on experience
in descending order so that the most experienced candidates appear first.
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
    cout << "Enter number of job applicants: ";
    cin >> n;

    cout << "Enter experience of each applicant (in years):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Applicant " << i + 1 << ": ";
        cin >> experience[i];
    }

    mergeSort(experience, 0, n - 1);

    cout << "\nJob applicants sorted by experience (descending order):\n";
    for (int i = 0; i < n; i++)
        cout << "Applicant " << i + 1 << " - " << experience[i] << " years\n";

    return 0;
}
