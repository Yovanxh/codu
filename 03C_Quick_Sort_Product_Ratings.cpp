/*
Problem Statement 3C:
Develop a sorting system using Quick Sort to sort product ratings in descending order
so that highly rated products appear first.
*/

#include <iostream>
using namespace std;

// ==========================================
// PARTITION FUNCTION (Descending Order)
// ==========================================
// Places the pivot element at its correct sorted position in descending order
// All elements greater than or equal to pivot are moved to the left
int partition(float ratings[], int low, int high)
{
    float pivot = ratings[high]; // Choosing the last element as pivot
    int i = low - 1;             // Index of greater element boundary

    // Traverse elements and compare with pivot
    for (int j = low; j < high; j++)
    {
        // For descending order, elements >= pivot go to the left side
        if (ratings[j] >= pivot)
        {
            i++;
            // Swap ratings[i] and ratings[j]
            float temp = ratings[i];
            ratings[i] = ratings[j];
            ratings[j] = temp;
        }
    }

    // Place pivot in its correct position (i + 1)
    float temp = ratings[i + 1];
    ratings[i + 1] = ratings[high];
    ratings[high] = temp;

    return i + 1; // Return pivot index
}

// ==========================================
// RECURSIVE QUICK SORT FUNCTION
// ==========================================
void quickSort(float ratings[], int low, int high)
{
    if (low < high)
    {
        // pi is the partitioning index; ratings[pi] is now in correct position
        int pi = partition(ratings, low, high);

        // Recursively sort elements before and after partition
        quickSort(ratings, low, pi - 1);
        quickSort(ratings, pi + 1, high);
    }
}

// ==========================================
// MAIN FUNCTION
// ==========================================
int main()
{
    int n;               // Number of products
    float ratings[100];  // Array of ratings (0.0 to 5.0)

    // Validate product count (1 to 100)
    do
    {
        cout << "Enter number of products (1 to 100): ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "Invalid count! Must be between 1 and 100.\n";
    } while (n < 1 || n > 100);

    // Input ratings with boundary checks (0.0 to 5.0)
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

    // Sort using Quick Sort in descending order
    quickSort(ratings, 0, n - 1);

    // Display sorted ratings
    cout << "\nProduct ratings in descending order (Highest rated first):\n";
    for (int i = 0; i < n; i++)
        cout << ratings[i] << " ";
    cout << endl;

    return 0;
}
