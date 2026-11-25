/*
Problem Statement 3C:
Develop a sorting system using Quick Sort to sort product ratings in descending order
so that highly rated products appear first.
Fixes: Validates 1 <= n <= 100 and ensures ratings stay strictly within 0.0 to 5.0.
*/

#include <iostream>
using namespace std;

int partition(float ratings[], int low, int high)
{
    float pivot = ratings[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (ratings[j] >= pivot)
        {
            i++;
            float temp = ratings[i];
            ratings[i] = ratings[j];
            ratings[j] = temp;
        }
    }
    float temp = ratings[i + 1];
    ratings[i + 1] = ratings[high];
    ratings[high] = temp;
    return i + 1;
}

void quickSort(float ratings[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(ratings, low, high);
        quickSort(ratings, low, pi - 1);
        quickSort(ratings, pi + 1, high);
    }
}

int main()
{
    int n;
    float ratings[100];

    do
    {
        cout << "Enter number of products (1 to 100): ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "Invalid count! Must be between 1 and 100.\n";
    } while (n < 1 || n > 100);

    cout << "Enter product ratings (0 to 5):\n";
    for (int i = 0; i < n; i++)
    {
        do
        {
            cout << "Rating of Product " << i + 1 << ": ";
            cin >> ratings[i];
            if (ratings[i] < 0.0 || ratings[i] > 5.0)
                cout << "Invalid rating! Enter a value between 0 and 5.\n";
        } while (ratings[i] < 0.0 || ratings[i] > 5.0);
    }

    quickSort(ratings, 0, n - 1);

    cout << "\nProduct ratings in descending order:\n";
    for (int i = 0; i < n; i++)
        cout << ratings[i] << " ";
    cout << endl;

    return 0;
}
