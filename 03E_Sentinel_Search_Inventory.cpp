/*
Problem Statement 3E:
Develop a Sentinel Search algorithm to efficiently search for a product ID in an inventory list.
If the product is found, display its details; otherwise, return a "Product Not Available" message.
*/

#include <iostream>
#include <string>
using namespace std;

struct Product
{
    int productID;
    string productName;
    float price;
    int quantity;
};

int sentinelSearch(Product products[], int n, int key)
{
    Product last = products[n - 1];
    products[n - 1].productID = key;

    int i = 0;
    while (products[i].productID != key)
    {
        i++;
    }

    products[n - 1] = last;

    if (i < n - 1 || products[n - 1].productID == key)
        return i;
    return -1;
}

int main()
{
    int n;
    Product products[100];
    cout << "Enter number of products: ";
    cin >> n;

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

    int key;
    cout << "\nEnter Product ID to search: ";
    cin >> key;

    int result = sentinelSearch(products, n, key);
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
