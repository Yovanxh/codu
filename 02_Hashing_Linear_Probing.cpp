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

    // Reject negative product codes (prevents negative index & EMPTY = -1 collision)
    if (p.code < 0)
    {
        cout << "Invalid Product Code! Product code must be non-negative (0 or greater).\n";
        return;
    }

    cout << "Enter Product Name: ";
    cin >> p.name;
    cout << "Enter Product Price: ";
    cin >> p.price;
    cout << "Enter Stock Quantity: ";
    cin >> p.stock;

    int index = p.code % tableSize;
    int originalIndex = index;

    // Linear Probing
    while (table[index].code != EMPTY)
    {
        if (table[index].code == p.code)
        {
            cout << "Product Code " << p.code << " already exists at index " << index << ".\n";
            return;
        }
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

    if (code < 0)
    {
        cout << "Invalid Product Code! Must be non-negative.\n";
        return;
    }

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

void updateProduct(Product table[], int tableSize)
{
    int code;
    cout << "\nEnter Product Code to update: ";
    cin >> code;

    if (code < 0)
    {
        cout << "Invalid Product Code! Must be non-negative.\n";
        return;
    }

    int index = code % tableSize;
    int originalIndex = index;

    while (table[index].code != EMPTY)
    {
        if (table[index].code == code)
        {
            cout << "\nCurrent Price: " << table[index].price;
            cout << "\nEnter New Price: ";
            cin >> table[index].price;
            cout << "Current Stock: " << table[index].stock;
            cout << "\nEnter New Stock: ";
            cin >> table[index].stock;
            cout << "Product details updated successfully!\n";
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

    // Validate tableSize (1 to SIZE) before starting the menu
    do
    {
        cout << "Enter Hash Table Size (1 to " << SIZE << "): ";
        cin >> tableSize;

        if (tableSize < 1 || tableSize > SIZE)
        {
            cout << "Invalid table size! Please enter a value between 1 and " << SIZE << ".\n";
        }
    } while (tableSize < 1 || tableSize > SIZE);

    // Initialize hash table
    for (int i = 0; i < tableSize; i++)
        table[i].code = EMPTY;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Add Product\n";
        cout << "2. Search Product\n";
        cout << "3. Update Product\n";
        cout << "4. Display Inventory\n";
        cout << "5. Exit\n";
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
            updateProduct(table, tableSize);
            break;
        case 4:
            displayProducts(table, tableSize);
            break;
        case 5:
            cout << "Thank you!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
