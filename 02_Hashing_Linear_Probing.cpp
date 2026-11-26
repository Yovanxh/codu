/*
Problem Statement 2:
Implement hashing techniques for efficient data storage and retrieval in real-world applications,
using linear probing to resolve collisions in practical scenarios.
Application: Retail Inventory Management System
*/

#include <iostream>
#include <string>
using namespace std;

// ==========================================
// CONSTANTS & DATA STRUCTURES
// ==========================================
const int EMPTY = -1;  // Sentinel value representing an unoccupied slot in the hash table
const int SIZE = 100;  // Maximum capacity of the hash table

struct Product
{
    int code;      // Key: Unique product code used for hashing
    string name;   // Name of the product
    float price;   // Price of the product
    int stock;     // Available stock quantity
};

// ==========================================
// FUNCTION: INSERT PRODUCT (With Linear Probing)
// ==========================================
void insertProduct(Product table[], int tableSize)
{
    Product p;
    cout << "\nEnter Product Code: ";
    cin >> p.code;

    // Validate key: Reject negative codes (prevents collision with EMPTY = -1 & negative modulo)
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

    // Hash function: Division / Modulo method
    int index = p.code % tableSize;
    int originalIndex = index;

    // Collision Resolution: Linear Probing (search sequentially: (index + 1) % tableSize)
    while (table[index].code != EMPTY)
    {
        // Check for duplicate key
        if (table[index].code == p.code)
        {
            cout << "Product Code " << p.code << " already exists at index " << index << ".\n";
            return;
        }

        index = (index + 1) % tableSize; // Move to the next slot circularly

        // If we loop all the way back to originalIndex, the table is full
        if (index == originalIndex)
        {
            cout << "Hash Table is Full. Product cannot be added.\n";
            return;
        }
    }

    // Place the product in the discovered empty slot
    table[index] = p;
    cout << "Product added successfully at index: " << index << endl;
}

// ==========================================
// FUNCTION: SEARCH PRODUCT (Linear Probing Lookup)
// ==========================================
void searchProduct(Product table[], int tableSize)
{
    int code;
    cout << "\nEnter Product Code to search: ";
    cin >> code;

    // Validate key input
    if (code < 0)
    {
        cout << "Invalid Product Code! Must be non-negative.\n";
        return;
    }

    // Compute expected initial hash index
    int index = code % tableSize;
    int originalIndex = index;

    // Probe sequentially until we find the key, hit an EMPTY slot, or loop completely
    while (table[index].code != EMPTY)
    {
        if (table[index].code == code)
        {
            cout << "\nProduct Found at index " << index << "!\n";
            cout << "Product Code : " << table[index].code << endl;
            cout << "Product Name : " << table[index].name << endl;
            cout << "Price        : " << table[index].price << endl;
            cout << "Stock        : " << table[index].stock << endl;
            return;
        }

        index = (index + 1) % tableSize;

        // Table fully probed without finding the product
        if (index == originalIndex)
            break;
    }
    cout << "Product not found.\n";
}

// ==========================================
// FUNCTION: UPDATE PRODUCT DETAILS
// ==========================================
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

    // Locate the product using linear probing
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

// ==========================================
// FUNCTION: DISPLAY HASH TABLE CONTENTS
// ==========================================
void displayProducts(Product table[], int tableSize)
{
    cout << "\n========== INVENTORY (HASH TABLE) ==========\n";
    for (int i = 0; i < tableSize; i++)
    {
        if (table[i].code == EMPTY)
            cout << "Index " << i << " : [ Empty Slot ]\n";
        else
            cout << "Index " << i << " : Code = " << table[i].code
                 << ", Name = " << table[i].name
                 << ", Price = " << table[i].price
                 << ", Stock = " << table[i].stock << endl;
    }
}

// ==========================================
// MAIN FUNCTION
// ==========================================
int main()
{
    Product table[SIZE];
    int tableSize, choice;

    cout << "===== RETAIL INVENTORY MANAGEMENT SYSTEM =====\n";

    // Validate table size within bounds (1 to SIZE)
    do
    {
        cout << "Enter Hash Table Size (1 to " << SIZE << "): ";
        cin >> tableSize;

        if (tableSize < 1 || tableSize > SIZE)
        {
            cout << "Invalid table size! Please enter a value between 1 and " << SIZE << ".\n";
        }
    } while (tableSize < 1 || tableSize > SIZE);

    // Initialize all slots as EMPTY (-1)
    for (int i = 0; i < tableSize; i++)
        table[i].code = EMPTY;

    // Menu-driven loop
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
            cout << "Invalid choice! Please select 1-5.\n";
        }
    } while (choice != 5);

    return 0;
}
