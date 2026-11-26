/*
Problem Statement 3B:
Implement a Merge Sort or Insertion Sort algorithm to sort flight ticket prices in ascending order
so that customers can quickly find the lowest fares.
*/

#include <iostream>
using namespace std;

// ==========================================
// MERGE FUNCTION: Combines two sorted subarrays
// ==========================================
// First subarray:  prices[left .. mid]
// Second subarray: prices[mid+1 .. right]
void merge(int prices[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // Length of left temporary array
    int n2 = right - mid;     // Length of right temporary array

    int L[100], R[100];       // Temporary arrays to hold sub-problems

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = prices[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = prices[mid + 1 + j];

    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray in original array

    // Merge temporary arrays back into prices[left .. right] in ascending order
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            prices[k++] = L[i++];
        else
            prices[k++] = R[j++];
    }

    // Copy remaining elements of L[], if any
    while (i < n1)
        prices[k++] = L[i++];

    // Copy remaining elements of R[], if any
    while (j < n2)
        prices[k++] = R[j++];
}

// ==========================================
// RECURSIVE MERGE SORT FUNCTION
// ==========================================
void mergeSort(int prices[], int left, int right)
{
    // Base Condition: Single element or invalid bounds
    if (left < right)
    {
        // Calculate midpoint to prevent integer overflow
        int mid = left + (right - left) / 2;

        // Recursively sort the left half
        mergeSort(prices, left, mid);

        // Recursively sort the right half
        mergeSort(prices, mid + 1, right);

        // Merge the two sorted halves together
        merge(prices, left, mid, right);
    }
}

// ==========================================
// MAIN FUNCTION
// ==========================================
int main()
{
    int n;           // Total count of flight ticket prices
    int prices[100]; // Array of ticket prices

    // Input count with validation (1 to 100)
    do
    {
        cout << "Enter number of flight ticket prices (1 to 100): ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "Invalid count! Must be between 1 and 100.\n";
    } while (n < 1 || n > 100);

    // Input prices with positive-value validation
    cout << "Enter " << n << " flight ticket prices:\n";
    for (int i = 0; i < n; i++)
    {
        do
        {
            cout << "Price " << i + 1 << ": ";
            cin >> prices[i];
            if (prices[i] <= 0)
                cout << "Invalid price! Must be greater than 0.\n";
        } while (prices[i] <= 0);
    }

    // Execute Merge Sort from start index 0 to n-1
    mergeSort(prices, 0, n - 1);

    // Display sorted prices in ascending order
    cout << "\nFlight ticket prices in ascending order:\n";
    for (int i = 0; i < n; i++)
        cout << prices[i] << " ";

    // Lowest flight fare is now at index 0
    cout << "\nLowest flight fare: " << prices[0] << endl;

    return 0;
}
