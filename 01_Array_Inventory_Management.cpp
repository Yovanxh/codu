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
Fixes: Validates initial n (0 <= n <= 100), prevents negative price/quantity, and blocks duplicate Product IDs.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int id[100];
    string name[100];
    int quantity[100];
    float price[100];
    int n, choice, searchID;

    cout << "===== Inventory Management System =====\n";

    do
    {
        cout << "Enter initial number of products (0 to 100): ";
        cin >> n;
        if (n < 0 || n > 100)
            cout << "Invalid count! Must be between 0 and 100.\n";
    } while (n < 0 || n > 100);

    for (int i = 0; i < n; i++)
    {
        cout << "\nProduct " << i + 1 << endl;
        cout << "Enter Product ID: ";
        cin >> id[i];
        cout << "Enter Product Name: ";
        cin >> name[i];
        do
        {
            cout << "Enter Quantity (>= 0): ";
            cin >> quantity[i];
        } while (quantity[i] < 0);
        do
        {
            cout << "Enter Price (>= 0): ";
            cin >> price[i];
        } while (price[i] < 0);
    }

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert Product\n2. Update Product\n3. Delete Product\n4. Display Products\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (n >= 100)
            {
                cout << "Array is full (max 100)! Cannot insert.\n";
                break;
            }
            int newID;
            cout << "Enter Product ID: ";
            cin >> newID;

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

            id[n] = newID;
            cout << "Enter Product Name: ";
            cin >> name[n];
            do
            {
                cout << "Enter Quantity (>= 0): ";
                cin >> quantity[n];
            } while (quantity[n] < 0);
            do
            {
                cout << "Enter Price (>= 0): ";
                cin >> price[n];
            } while (price[n] < 0);

            n++;
            cout << "Product inserted successfully.\n";
            break;
        }
        case 2:
        {
            bool found = false;
            cout << "Enter Product ID to update: ";
            cin >> searchID;
            for (int i = 0; i < n; i++)
            {
                if (id[i] == searchID)
                {
                    cout << "Enter New Name: ";
                    cin >> name[i];
                    do
                    {
                        cout << "Enter New Quantity (>= 0): ";
                        cin >> quantity[i];
                    } while (quantity[i] < 0);
                    do
                    {
                        cout << "Enter New Price (>= 0): ";
                        cin >> price[i];
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
        case 3:
        {
            bool found = false;
            cout << "Enter Product ID to delete: ";
            cin >> searchID;
            for (int i = 0; i < n; i++)
            {
                if (id[i] == searchID)
                {
                    for (int j = i; j < n - 1; j++)
                    {
                        id[j] = id[j + 1];
                        name[j] = name[j + 1];
                        quantity[j] = quantity[j + 1];
                        price[j] = price[j + 1];
                    }
                    n--;
                    cout << "Product deleted successfully.\n";
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Product Not Found.\n";
            break;
        }
        case 4:
            if (n == 0)
            {
                cout << "Inventory is empty.\n";
                break;
            }
            cout << "\nID\tName\tQty\tPrice\n";
            for (int i = 0; i < n; i++)
                cout << id[i] << "\t" << name[i] << "\t" << quantity[i] << "\t" << price[i] << endl;
            break;
        case 5:
            cout << "Thank You!\n";
            break;
        default:
            cout << "Invalid Choice!\n";
        }
    } while (choice != 5);

    return 0;
}
