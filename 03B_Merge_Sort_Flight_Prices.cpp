/*
Problem Statement 3B:
Implement a Merge Sort or Insertion Sort algorithm to sort flight ticket prices in ascending order
so that customers can quickly find the lowest fares.
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
    cout << "Enter number of flight ticket prices: ";
    cin >> n;

    cout << "Enter " << n << " flight ticket prices:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Price " << i + 1 << ": ";
        cin >> prices[i];
    }

    mergeSort(prices, 0, n - 1);

    cout << "\nFlight ticket prices in ascending order:\n";
    for (int i = 0; i < n; i++)
        cout << prices[i] << " ";
    cout << "\nLowest flight fare: " << prices[0] << endl;

    return 0;
}
