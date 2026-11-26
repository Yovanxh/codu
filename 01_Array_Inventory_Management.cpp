/*
Problem Statement 1:
Design and develop a program to perform fundamental operations on an array for a selected application:-
Scope of Assignment :
The program should support the following functionalities:
- Insertion: Add a new element to the array.
- Updation: Modify an existing element in the array.
- Deletion: Remove an element from the array.
- Display: Show all elements stored in the array.
Application: Inventory Management System
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // ==========================================
    // DATA STRUCTURES: Parallel Arrays for Inventory
    // ==========================================
    int id[100];        // Stores unique Product IDs
    string name[100];   // Stores Product Names
    int quantity[100];  // Stores Quantity available in stock
    float price[100];   // Stores Unit Price of products
    int n;              // Current number of products in inventory
    int choice;         // Stores user's menu choice
    int searchID;       // Target ID to search for update/delete operations

    cout << "===== Inventory Management System =====\n";

    // ==========================================
    // INPUT INITIAL INVENTORY SIZE (With Validation)
    // ==========================================
    // Ensure the initial product count falls within the allocated array capacity (0 to 100)
    do
    {
        cout << "Enter initial number of products (0 to 100): ";
        cin >> n;
        if (n < 0 || n > 100)
            cout << "Invalid count! Must be between 0 and 100.\n";
    } while (n < 0 || n > 100);

    // ==========================================
    // POPULATE INITIAL PRODUCT DETAILS
    // ==========================================
    for (int i = 0; i < n; i++)
    {
        cout << "\nProduct " << i + 1 << endl;
        cout << "Enter Product ID: ";
        cin >> id[i];

        cout << "Enter Product Name: ";
        cin >> name[i];

        // Validate quantity: Stock cannot be negative
        do
        {
            cout << "Enter Quantity (>= 0): ";
            cin >> quantity[i];
            if (quantity[i] < 0)
                cout << "Quantity cannot be negative! Please re-enter.\n";
        } while (quantity[i] < 0);

        // Validate price: Price cannot be negative
        do
        {
            cout << "Enter Price (>= 0): ";
            cin >> price[i];
            if (price[i] < 0)
                cout << "Price cannot be negative! Please re-enter.\n";
        } while (price[i] < 0);
    }

    // ==========================================
    // MAIN MENU DRIVEN SYSTEM (CRUD OPERATIONS)
    // ==========================================
    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert Product\n";
        cout << "2. Update Product\n";
        cout << "3. Delete Product\n";
        cout << "4. Display Products\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        // ------------------------------------------
        // OPERATION 1: INSERT A NEW PRODUCT
        // ------------------------------------------
        case 1:
        {
            // Check overflow condition: Array is full
            if (n >= 100)
            {
                cout << "Array is full (max 100)! Cannot insert.\n";
                break;
            }

            int newID;
            cout << "Enter Product ID: ";
            cin >> newID;

            // Check for duplicate product IDs
            bool duplicate = false;
            for (int i = 0; i < n; i++)
            {
                if (id[i] == newID)
                {
                    duplicate = true;
                    break;
                }
            }
            if (duplicate)
            {
                cout << "Duplicate Product ID! Cannot insert.\n";
                break;
            }

            // Append new item at index n
            id[n] = newID;
            cout << "Enter Product Name: ";
            cin >> name[n];

            // Validate non-negative quantity
            do
            {
                cout << "Enter Quantity (>= 0): ";
                cin >> quantity[n];
                if (quantity[n] < 0)
                    cout << "Quantity cannot be negative! Re-enter.\n";
            } while (quantity[n] < 0);

            // Validate non-negative price
            do
            {
                cout << "Enter Price (>= 0): ";
                cin >> price[n];
                if (price[n] < 0)
                    cout << "Price cannot be negative! Re-enter.\n";
            } while (price[n] < 0);

            n++; // Increment total product count
            cout << "Product inserted successfully.\n";
            break;
        }

        // ------------------------------------------
        // OPERATION 2: UPDATE AN EXISTING PRODUCT
        // ------------------------------------------
        case 2:
        {
            bool found = false;
            cout << "Enter Product ID to update: ";
            cin >> searchID;

            // Search linearly for the product ID
            for (int i = 0; i < n; i++)
            {
                if (id[i] == searchID)
                {
                    cout << "Enter New Name: ";
                    cin >> name[i];

                    // Validate new quantity
                    do
                    {
                        cout << "Enter New Quantity (>= 0): ";
                        cin >> quantity[i];
                        if (quantity[i] < 0)
                            cout << "Quantity cannot be negative! Re-enter.\n";
                    } while (quantity[i] < 0);

                    // Validate new price
                    do
                    {
                        cout << "Enter New Price (>= 0): ";
                        cin >> price[i];
                        if (price[i] < 0)
                            cout << "Price cannot be negative! Re-enter.\n";
                    } while (price[i] < 0);

                    cout << "Product updated successfully.\n";
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Product Not Found.\n";
            break;
        }

        // ------------------------------------------
        // OPERATION 3: DELETE A PRODUCT
        // ------------------------------------------
        case 3:
        {
            bool found = false;
            cout << "Enter Product ID to delete: ";
            cin >> searchID;

            // Search linearly for the product to delete
            for (int i = 0; i < n; i++)
            {
                if (id[i] == searchID)
                {
                    // Shift subsequent elements left by 1 position to fill the gap
                    for (int j = i; j < n - 1; j++)
                    {
                        id[j] = id[j + 1];
                        name[j] = name[j + 1];
                        quantity[j] = quantity[j + 1];
                        price[j] = price[j + 1];
                    }
                    n--; // Decrement product count
                    cout << "Product deleted successfully.\n";
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Product Not Found.\n";
            break;
        }

        // ------------------------------------------
        // OPERATION 4: DISPLAY ALL PRODUCTS
        // ------------------------------------------
        case 4:
            // Check underflow condition: Inventory empty
            if (n == 0)
            {
                cout << "Inventory is empty.\n";
                break;
            }

            cout << "\nID\tName\tQty\tPrice\n";
            cout << "------------------------------------\n";
            for (int i = 0; i < n; i++)
                cout << id[i] << "\t" << name[i] << "\t" << quantity[i] << "\t" << price[i] << endl;
            break;

        // ------------------------------------------
        // OPERATION 5: EXIT THE PROGRAM
        // ------------------------------------------
        case 5:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice! Please select 1-5.\n";
        }
    } while (choice != 5);

    return 0;
}
