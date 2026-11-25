/*
Problem Statement 3B:
Implement a Merge Sort or Insertion Sort algorithm to sort flight ticket prices in ascending order
so that customers can quickly find the lowest fares.
Fixes: Validates 1 <= n <= 100 (preventing empty prices[0] access) and rejects negative ticket fares.
*/

#include <iostream>
using namespace std;

void merge(int prices[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = prices[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = prices[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            prices[k++] = L[i++];
        else
            prices[k++] = R[j++];
    }

    while (i < n1)
        prices[k++] = L[i++];
    while (j < n2)
        prices[k++] = R[j++];
}

void mergeSort(int prices[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(prices, left, mid);
        mergeSort(prices, mid + 1, right);
        merge(prices, left, mid, right);
    }
}

int main()
{
    int n, prices[100];

    do
    {
        cout << "Enter number of flight ticket prices (1 to 100): ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "Invalid count! Must be between 1 and 100.\n";
    } while (n < 1 || n > 100);

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

    mergeSort(prices, 0, n - 1);

    cout << "\nFlight ticket prices in ascending order:\n";
    for (int i = 0; i < n; i++)
        cout << prices[i] << " ";
    cout << "\nLowest flight fare: " << prices[0] << endl;

    return 0;
}
