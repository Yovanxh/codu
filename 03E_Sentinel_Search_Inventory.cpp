/*
Problem Statement 3E:
Develop a Sentinel Search algorithm to efficiently search for a product ID in an inventory list.
If the product is found, display its details; otherwise, return a "Product Not Available" message.
*/

#include <iostream>
#include <string>
using namespace std;

// ==========================================
// DATA STRUCTURE: Product Record
// ==========================================
struct Product
{
    int productID;       // Unique ID to search for
    string productName;  // Name of the product
    float price;         // Unit price
    int quantity;        // Quantity in inventory
};

// ==========================================
// SENTINEL SEARCH ALGORITHM
// ==========================================
// Sentinel Search eliminates the boundary check condition (i < n) in every loop iteration
// by placing the search key temporarily at the end of the array as a "sentinel".
int sentinelSearch(Product products[], int n, int key)
{
    // Safety check for empty inventory
    if (n <= 0)
        return -1;

    // Step 1: Save the original last element
    Product last = products[n - 1];

    // Step 2: Set the search key at the last position (the sentinel)
    products[n - 1].productID = key;

    // Step 3: Search without bounds check (guaranteed to terminate)
    int i = 0;
    while (products[i].productID != key)
    {
        i++;
    }

    // Step 4: Restore original last element
    products[n - 1] = last;

    // Step 5: Check if key was found before the sentinel, or if the original last item matched
    if (i < n - 1 || products[n - 1].productID == key)
        return i; // Found at index i

    return -1; // Product not found in original inventory
}

// ==========================================
// MAIN FUNCTION
// ==========================================
int main()
{
    int n;
    Product products[100];

    // Validate product count (1 to 100)
    do
    {
        cout << "Enter number of products (1 to 100): ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "Invalid count! Must be between 1 and 100.\n";
    } while (n < 1 || n > 100);

    // Populate inventory records
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for Product " << i + 1 << endl;
        cout << "Enter Product ID: ";
        cin >> products[i].productID;
        cout << "Enter Product Name: ";
        cin >> products[i].productName;
        cout << "Enter Price: ";
        cin >> products[i].price;
        cout << "Enter Quantity: ";
        cin >> products[i].quantity;
    }

    // Input target key to search
    int key;
    cout << "\nEnter Product ID to search: ";
    cin >> key;

    // Perform Sentinel Search
    int result = sentinelSearch(products, n, key);

    // Display result
    if (result != -1)
    {
        cout << "\nProduct Found!\n";
        cout << "Product ID: " << products[result].productID << endl;
        cout << "Product Name: " << products[result].productName << endl;
        cout << "Price: " << products[result].price << endl;
        cout << "Quantity: " << products[result].quantity << endl;
    }
    else
    {
        cout << "\nProduct Not Available\n";
    }

    return 0;
}
