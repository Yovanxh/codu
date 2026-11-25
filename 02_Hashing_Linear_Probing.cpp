/*
Problem Statement 2:
Implement hashing techniques for efficient data storage and retrieval in real-world applications,
using linear probing to resolve collisions in practical scenarios.
Application: Retail Inventory Management System
*/

#include <iostream>
#include <string>
using namespace std;

const int EMPTY = -1;
const int SIZE = 100;

struct Product
{
    int code;
    string name;
    float price;
    int stock;
};

void insertProduct(Product table[], int tableSize)
{
    Product p;
    cout << "\nEnter Product Code: ";
    cin >> p.code;
    cout << "Enter Product Name: ";
    cin >> p.name;
    cout << "Enter Product Price: ";
    cin >> p.price;
    cout << "Enter Stock Quantity: ";
    cin >> p.stock;

    int index = p.code % tableSize;
    int originalIndex = index;

    while (table[index].code != EMPTY)
    {
        index = (index + 1) % tableSize;
        if (index == originalIndex)
        {
            cout << "Hash Table is Full. Product cannot be added.\n";
            return;
        }
    }

    table[index] = p;
    cout << "Product added successfully at index: " << index << endl;
}

void searchProduct(Product table[], int tableSize)
{
    int code;
    cout << "\nEnter Product Code to search: ";
    cin >> code;

    int index = code % tableSize;
    int originalIndex = index;

    while (table[index].code != EMPTY)
    {
        if (table[index].code == code)
        {
            cout << "\nProduct Found!\n";
            cout << "Product Code : " << table[index].code << endl;
            cout << "Product Name : " << table[index].name << endl;
            cout << "Price        : " << table[index].price << endl;
            cout << "Stock        : " << table[index].stock << endl;
            return;
        }
        index = (index + 1) % tableSize;
        if (index == originalIndex)
            break;
    }
    cout << "Product not found.\n";
}

void displayProducts(Product table[], int tableSize)
{
    cout << "\n========== INVENTORY ==========\n";
    for (int i = 0; i < tableSize; i++)
    {
        if (table[i].code == EMPTY)
            cout << "Index " << i << " : Empty\n";
        else
            cout << "Index " << i << " : Code = " << table[i].code
                 << ", Name = " << table[i].name
                 << ", Price = " << table[i].price
                 << ", Stock = " << table[i].stock << endl;
    }
}

int main()
{
    Product table[SIZE];
    int tableSize, choice;

    cout << "===== RETAIL INVENTORY MANAGEMENT SYSTEM =====\n";
    cout << "Enter Hash Table Size: ";
    cin >> tableSize;

    for (int i = 0; i < tableSize; i++)
        table[i].code = EMPTY;

    do
    {
        cout << "\n1. Add Product\n2. Search Product\n3. Display Inventory\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertProduct(table, tableSize);
            break;
        case 2:
            searchProduct(table, tableSize);
            break;
        case 3:
            displayProducts(table, tableSize);
            break;
        case 4:
            cout << "Thank you!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
