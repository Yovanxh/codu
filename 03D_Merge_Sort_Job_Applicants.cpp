/*
Problem Statement 3D:
Develop a Merge Sort or Quick Sort based system to sort job applicants based on experience
in descending order so that the most experienced candidates appear first.
*/

#include <iostream>
using namespace std;

// ==========================================
// MERGE FUNCTION: Merge in Descending Order
// ==========================================
void merge(int experience[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;     // Size of right subarray
    int L[100], R[100];       // Temporary buffers

    // Populate temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = experience[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = experience[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge in DESCENDING order: greater elements placed first
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
            experience[k++] = L[i++];
        else
            experience[k++] = R[j++];
    }

    // Append remaining elements from L[]
    while (i < n1)
        experience[k++] = L[i++];

    // Append remaining elements from R[]
    while (j < n2)
        experience[k++] = R[j++];
}

// ==========================================
// RECURSIVE MERGE SORT (Divide and Conquer)
// ==========================================
void mergeSort(int experience[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(experience, left, mid);        // Sort left partition
        mergeSort(experience, mid + 1, right);    // Sort right partition
        merge(experience, left, mid, right);     // Combine partitions
    }
}

// ==========================================
// MAIN FUNCTION
// ==========================================
int main()
{
    int n;                // Total number of applicants
    int experience[100];  // Applicant experience in years

    // Input total applicant count with validation
    do
    {
        cout << "Enter number of job applicants (1 to 100): ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "Invalid count! Must be between 1 and 100.\n";
    } while (n < 1 || n > 100);

    // Input each applicant's experience (reject negative years)
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

    // Execute Merge Sort
    mergeSort(experience, 0, n - 1);

    // Output ranked applicants
    cout << "\nJob applicants sorted by experience (descending order):\n";
    for (int i = 0; i < n; i++)
        cout << "Applicant " << i + 1 << " - " << experience[i] << " years\n";

    return 0;
}
