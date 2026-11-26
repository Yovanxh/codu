# DSA Practical Programs (C++)

This repository contains all 17 practical programs for the **Data Structures and Algorithms (DSA) Practical Examination**, structured with question statements, detailed explanatory comments for each block of code, and clean copyable C++ source code.

> 📚 **Viva & Oral Exam Prep:** Looking for oral exam short questions & answers? Check out the **[120 Oral / Viva Exam Questions & Answers (Unit 1 to 6)](./DSA_Oral_Exam_Questions_and_Answers.md)**.

---

## Index of Practicals

| Practical | Problem Description | File |
| :--- | :--- | :--- |
| **1** | [Fundamental Operations on an Array (Inventory Management)](#1-fundamental-operations-on-an-array-inventory-management-system) | [`01_Array_Inventory_Management.cpp`](./01_Array_Inventory_Management.cpp) |
| **2** | [Hashing with Linear Probing (Retail Inventory System)](#2-hashing-with-linear-probing-retail-inventory-system) | [`02_Hashing_Linear_Probing.cpp`](./02_Hashing_Linear_Probing.cpp) |
| **3A** | [Selection Sort (Student Marks - Ascending)](#3a-selection-sort-student-marks--ascending) | [`03A_Selection_Sort_Marks.cpp`](./03A_Selection_Sort_Marks.cpp) |
| **3B** | [Merge Sort (Flight Ticket Prices - Ascending)](#3b-merge-sort-flight-ticket-prices--ascending) | [`03B_Merge_Sort_Flight_Prices.cpp`](./03B_Merge_Sort_Flight_Prices.cpp) |
| **3C** | [Quick Sort (Product Ratings - Descending)](#3c-quick-sort-product-ratings--descending) | [`03C_Quick_Sort_Product_Ratings.cpp`](./03C_Quick_Sort_Product_Ratings.cpp) |
| **3D** | [Merge Sort (Job Applicants Experience - Descending)](#3d-merge-sort-job-applicants-experience--descending) | [`03D_Merge_Sort_Job_Applicants.cpp`](./03D_Merge_Sort_Job_Applicants.cpp) |
| **3E** | [Sentinel Search (Inventory Product Lookup)](#3e-sentinel-search-inventory-product-lookup) | [`03E_Sentinel_Search_Inventory.cpp`](./03E_Sentinel_Search_Inventory.cpp) |
| **4A** | [Singly Linked List (Student Record Management)](#4a-singly-linked-list-student-record-management) | [`04A_Singly_Linked_List_Student.cpp`](./04A_Singly_Linked_List_Student.cpp) |
| **4B** | [Doubly Linked List (Music Playlist Manager)](#4b-doubly-linked-list-music-playlist-manager) | [`04B_Doubly_Linked_List_Playlist.cpp`](./04B_Doubly_Linked_List_Playlist.cpp) |
| **4C** | [Circular Linked List (Round-Robin Task Scheduler)](#4c-circular-linked-list-round-robin-task-scheduler) | [`04C_Circular_Linked_List_Scheduler.cpp`](./04C_Circular_Linked_List_Scheduler.cpp) |
| **5A** | [Infix to Postfix Conversion](#5a-infix-to-postfix-conversion) | [`05A_Infix_to_Postfix.cpp`](./05A_Infix_to_Postfix.cpp) |
| **5B** | [Postfix Evaluation](#5b-postfix-evaluation) | [`05B_Postfix_Evaluation.cpp`](./05B_Postfix_Evaluation.cpp) |
| **5C** | [Stack Using Linked List](#5c-stack-using-linked-list) | [`05C_Stack_Linked_List.cpp`](./05C_Stack_Linked_List.cpp) |
| **6** | [Circular Queue (Service Request Management)](#6-circular-queue-service-request-management) | [`06_Circular_Queue_Service_Requests.cpp`](./06_Circular_Queue_Service_Requests.cpp) |
| **7** | [Double Ended Queue (Shopping Mall Billing Queue)](#7-double-ended-queue-shopping-mall-billing-queue) | [`07_Double_Ended_Queue_Mall.cpp`](./07_Double_Ended_Queue_Mall.cpp) |
| **8A & 8B** | [Binary Search Tree (Student Record Management System)](#8a--8b-binary-search-tree-student-record-management-system) | [`08_Binary_Search_Tree_Student_Record.cpp`](./08_Binary_Search_Tree_Student_Record.cpp) |
| **9A & 9B** | [Graph Traversal System (Delivery Route Finder - BFS & DFS)](#9a--9b-graph-traversal-system-delivery-route-finder--bfs--dfs) | [`09_Graph_BFS_DFS_Delivery_Route.cpp`](./09_Graph_BFS_DFS_Delivery_Route.cpp) |

---

### 1. Fundamental Operations on an Array (Inventory Management System)

> **Question:**  
> Design and develop a program to perform fundamental operations on an array for a selected application:-  
> **Scope of Assignment:**  
> The program should support the following functionalities:  
> - **Insertion:** Add a new element to the array.  
> - **Updation:** Modify an existing element in the array.  
> - **Deletion:** Remove an element from the array.  
> - **Display:** Show all elements stored in the array.  

```cpp
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
```

---

### 2. Hashing with Linear Probing (Retail Inventory System)

> **Question:**  
> Implement hashing techniques for efficient data storage and retrieval in real-world applications, using linear probing to resolve collisions in practical scenarios.  

```cpp
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
```

---

### 3A. Selection Sort (Student Marks — Ascending)

> **Question:**  
> Develop a program that takes student marks as input and sorts them in ascending order using Selection Sort.  

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n;          // Number of students
    int i, j;       // Loop index variables
    int minIndex;   // Tracks the index of the minimum element found in the unsorted subarray
    int temp;       // Temporary variable used for swapping elements
    int marks[100]; // Array to hold marks of up to 100 students

    // ==========================================
    // INPUT: NUMBER OF STUDENTS (With Validation)
    // ==========================================
    do
    {
        cout << "Enter number of students (1 to 100): ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "Invalid count! Must be between 1 and 100.\n";
    } while (n < 1 || n > 100);

    // ==========================================
    // INPUT: STUDENT MARKS (0 to 100 validation)
    // ==========================================
    cout << "Enter marks of " << n << " students (0 to 100):\n";
    for (i = 0; i < n; i++)
    {
        do
        {
            cout << "Student " << i + 1 << ": ";
            cin >> marks[i];
            if (marks[i] < 0 || marks[i] > 100)
                cout << "Invalid marks! Enter a value between 0 and 100.\n";
        } while (marks[i] < 0 || marks[i] > 100);
    }

    // ==========================================
    // ALGORITHM: SELECTION SORT (Ascending Order)
    // ==========================================
    // Repeatedly finds the minimum element from the unsorted portion and puts it at the beginning
    for (i = 0; i < n - 1; i++)
    {
        // Assume the first element of the unsorted segment is the smallest
        minIndex = i;

        // Iterate through the unsorted portion to find the true minimum
        for (j = i + 1; j < n; j++)
        {
            if (marks[j] < marks[minIndex])
                minIndex = j; // Update index of current smallest value
        }

        // Swap the found minimum element with the first element of unsorted portion
        temp = marks[i];
        marks[i] = marks[minIndex];
        marks[minIndex] = temp;
    }

    // ==========================================
    // OUTPUT: DISPLAY SORTED MARKS
    // ==========================================
    cout << "\nStudent marks in ascending order:\n";
    for (i = 0; i < n; i++)
        cout << marks[i] << " ";
    cout << endl;

    return 0;
}
```

---

### 3B. Merge Sort (Flight Ticket Prices — Ascending)

> **Question:**  
> Implement a Merge Sort or Insertion Sort algorithm to sort flight ticket prices in ascending order so that customers can quickly find the lowest fares.  

```cpp
#include <iostream>
using namespace std;

// ==========================================
// MERGE FUNCTION: Combines two sorted subarrays
// ==========================================
// First subarray:  prices[left .. mid]
// Second subarray: prices[mid+1 .. right]
void merge(int prices[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // Length of left temporary array
    int n2 = right - mid;     // Length of right temporary array

    int L[100], R[100];       // Temporary arrays to hold sub-problems

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = prices[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = prices[mid + 1 + j];

    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray in original array

    // Merge temporary arrays back into prices[left .. right] in ascending order
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            prices[k++] = L[i++];
        else
            prices[k++] = R[j++];
    }

    // Copy remaining elements of L[], if any
    while (i < n1)
        prices[k++] = L[i++];

    // Copy remaining elements of R[], if any
    while (j < n2)
        prices[k++] = R[j++];
}

// ==========================================
// RECURSIVE MERGE SORT FUNCTION
// ==========================================
void mergeSort(int prices[], int left, int right)
{
    // Base Condition: Single element or invalid bounds
    if (left < right)
    {
        // Calculate midpoint to prevent integer overflow
        int mid = left + (right - left) / 2;

        // Recursively sort the left half
        mergeSort(prices, left, mid);

        // Recursively sort the right half
        mergeSort(prices, mid + 1, right);

        // Merge the two sorted halves together
        merge(prices, left, mid, right);
    }
}

// ==========================================
// MAIN FUNCTION
// ==========================================
int main()
{
    int n;           // Total count of flight ticket prices
    int prices[100]; // Array of ticket prices

    // Input count with validation (1 to 100)
    do
    {
        cout << "Enter number of flight ticket prices (1 to 100): ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "Invalid count! Must be between 1 and 100.\n";
    } while (n < 1 || n > 100);

    // Input prices with positive-value validation
    cout << "Enter " << n << " flight ticket prices:\n";
    for (int i = 0; i < n; i++)
    {
        do
        {
            cout << "Price " << i + 1 << ": ";
            cin >> prices[i];
            if (prices[i] <= 0)
                cout << "Invalid price! Must be greater than 0.\n";
        } while (prices[i] <= 0);
    }

    // Execute Merge Sort from start index 0 to n-1
    mergeSort(prices, 0, n - 1);

    // Display sorted prices in ascending order
    cout << "\nFlight ticket prices in ascending order:\n";
    for (int i = 0; i < n; i++)
        cout << prices[i] << " ";

    // Lowest flight fare is now at index 0
    cout << "\nLowest flight fare: " << prices[0] << endl;

    return 0;
}
```

---

### 3C. Quick Sort (Product Ratings — Descending)

> **Question:**  
> Develop a sorting system using Quick Sort to sort product ratings in descending order so that highly rated products appear first.  

```cpp
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
```

---

### 3D. Merge Sort (Job Applicants Experience — Descending)

> **Question:**  
> Develop a Merge Sort or Quick Sort based system to sort job applicants based on experience in descending order so that the most experienced candidates appear first.  

```cpp
#include <iostream>
using namespace std;

// ==========================================
// MERGE FUNCTION: Merge in Descending Order
// ==========================================
void merge(int experience[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;     // Size of right subarray
    int L[100], R[100];       // Temporary buffers

    // Populate temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = experience[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = experience[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge in DESCENDING order: greater elements placed first
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
            experience[k++] = L[i++];
        else
            experience[k++] = R[j++];
    }

    // Append remaining elements from L[]
    while (i < n1)
        experience[k++] = L[i++];

    // Append remaining elements from R[]
    while (j < n2)
        experience[k++] = R[j++];
}

// ==========================================
// RECURSIVE MERGE SORT (Divide and Conquer)
// ==========================================
void mergeSort(int experience[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(experience, left, mid);        // Sort left partition
        mergeSort(experience, mid + 1, right);    // Sort right partition
        merge(experience, left, mid, right);     // Combine partitions
    }
}

// ==========================================
// MAIN FUNCTION
// ==========================================
int main()
{
    int n;                // Total number of applicants
    int experience[100];  // Applicant experience in years

    // Input total applicant count with validation
    do
    {
        cout << "Enter number of job applicants (1 to 100): ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "Invalid count! Must be between 1 and 100.\n";
    } while (n < 1 || n > 100);

    // Input each applicant's experience (reject negative years)
    cout << "Enter experience of each applicant (in years >= 0):\n";
    for (int i = 0; i < n; i++)
    {
        do
        {
            cout << "Applicant " << i + 1 << ": ";
            cin >> experience[i];
            if (experience[i] < 0)
                cout << "Invalid experience! Cannot be negative.\n";
        } while (experience[i] < 0);
    }

    // Execute Merge Sort
    mergeSort(experience, 0, n - 1);

    // Output ranked applicants
    cout << "\nJob applicants sorted by experience (descending order):\n";
    for (int i = 0; i < n; i++)
        cout << "Applicant " << i + 1 << " - " << experience[i] << " years\n";

    return 0;
}
```

---

### 3E. Sentinel Search (Inventory Product Lookup)

> **Question:**  
> Develop a Sentinel Search algorithm to efficiently search for a product ID in an inventory list. If the product is found, display its details; otherwise, return a “Product Not Available” message.  

```cpp
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
```

---

### 4A. Singly Linked List (Student Record Management)

> **Question:**  
> Design and develop a program to implement real-life applications of a Singly Linked List by enabling operations such as insertion, updating, searching, sorting, listing, and deletion.  

```cpp
#include <iostream>
#include <string>
using namespace std;

// ==========================================
// NODE CLASS: Representation of a Single Node
// ==========================================
class Node
{
public:
    int rollNo;     // Student Roll Number (Key)
    string name;    // Student Name
    float marks;    // Student Marks
    Node* next;     // Pointer to the next node in the list
};

// ==========================================
// SINGLY LINKED LIST CLASS
// ==========================================
class SinglyLinkedList
{
private:
    Node* head; // Points to the first node in the linked list

    // Helper function: Checks if a student with the given roll number already exists
    bool exists(int roll)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->rollNo == roll)
                return true;
            temp = temp->next;
        }
        return false;
    }

public:
    // Constructor: Initializes an empty list
    SinglyLinkedList()
    {
        head = NULL;
    }

    // Destructor: Deallocates all dynamically allocated nodes to prevent memory leaks
    ~SinglyLinkedList()
    {
        Node* temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    // ------------------------------------------
    // OPERATION 1: INSERT RECORD AT END
    // ------------------------------------------
    void insertStudent(int roll, string name, float marks)
    {
        // Block duplicates
        if (exists(roll))
        {
            cout << "Duplicate Roll Number! Record already exists.\n";
            return;
        }

        // Create and initialize new node
        Node* newNode = new Node();
        newNode->rollNo = roll;
        newNode->name = name;
        newNode->marks = marks;
        newNode->next = NULL;

        // If list is empty, make new node the head
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            // Traverse to the last node
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            // Link the last node to the new node
            temp->next = newNode;
        }
        cout << "Student record inserted successfully.\n";
    }

    // ------------------------------------------
    // OPERATION 2: UPDATE RECORD BY ROLL NUMBER
    // ------------------------------------------
    void updateStudent(int roll)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->rollNo == roll)
            {
                cout << "Enter New Name: ";
                cin >> temp->name;
                cout << "Enter New Marks: ";
                cin >> temp->marks;
                cout << "Student record updated successfully.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found.\n";
    }

    // ------------------------------------------
    // OPERATION 3: SEARCH RECORD BY ROLL NUMBER
    // ------------------------------------------
    void searchStudent(int roll)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->rollNo == roll)
            {
                cout << "\nStudent Found!\n";
                cout << "Roll No: " << temp->rollNo << ", Name: " << temp->name << ", Marks: " << temp->marks << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found.\n";
    }

    // ------------------------------------------
    // OPERATION 4: SORT RECORDS (Bubble Sort by Roll No)
    // ------------------------------------------
    void sortStudents()
    {
        // Nothing to sort if empty or single node
        if (head == NULL || head->next == NULL)
            return;

        // Bubble sort on linked list by swapping node data
        for (Node* i = head; i->next != NULL; i = i->next)
        {
            for (Node* j = i->next; j != NULL; j = j->next)
            {
                if (i->rollNo > j->rollNo)
                {
                    // Swap Roll Number
                    int tempRoll = i->rollNo;
                    i->rollNo = j->rollNo;
                    j->rollNo = tempRoll;

                    // Swap Name
                    string tempName = i->name;
                    i->name = j->name;
                    j->name = tempName;

                    // Swap Marks
                    float tempMarks = i->marks;
                    i->marks = j->marks;
                    j->marks = tempMarks;
                }
            }
        }
        cout << "Records sorted by Roll Number.\n";
    }

    // ------------------------------------------
    // OPERATION 5: DELETE RECORD BY ROLL NUMBER
    // ------------------------------------------
    void deleteStudent(int roll)
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }

        // Case 1: Node to be deleted is the head node
        if (head->rollNo == roll)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Student deleted successfully.\n";
            return;
        }

        // Case 2: Node is intermediate or at the end
        Node* curr = head;
        while (curr->next != NULL && curr->next->rollNo != roll)
            curr = curr->next;

        if (curr->next == NULL)
        {
            cout << "Student not found.\n";
        }
        else
        {
            Node* temp = curr->next;
            curr->next = temp->next; // Bypass the node to delete
            delete temp;             // Free memory
            cout << "Student deleted successfully.\n";
        }
    }

    // ------------------------------------------
    // OPERATION 6: DISPLAY ALL RECORDS
    // ------------------------------------------
    void display()
    {
        if (head == NULL)
        {
            cout << "No student records available.\n";
            return;
        }
        Node* temp = head;
        cout << "\nRollNo\tName\tMarks\n";
        cout << "------------------------------------\n";
        while (temp != NULL)
        {
            cout << temp->rollNo << "\t" << temp->name << "\t" << temp->marks << endl;
            temp = temp->next;
        }
    }
};

// ==========================================
// MAIN FUNCTION (Interactive Menu)
// ==========================================
int main()
{
    SinglyLinkedList list;
    int choice, roll;
    string name;
    float marks;

    do
    {
        cout << "\n===== SINGLY LINKED LIST MENU =====\n";
        cout << "1. Insert\n2. Update\n3. Search\n4. Sort\n5. Display\n6. Delete\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Roll No: ";
            cin >> roll;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Marks: ";
            cin >> marks;
            list.insertStudent(roll, name, marks);
            break;
        case 2:
            cout << "Enter Roll No to update: ";
            cin >> roll;
            list.updateStudent(roll);
            break;
        case 3:
            cout << "Enter Roll No to search: ";
            cin >> roll;
            list.searchStudent(roll);
            break;
        case 4:
            list.sortStudents();
            break;
        case 5:
            list.display();
            break;
        case 6:
            cout << "Enter Roll No to delete: ";
            cin >> roll;
            list.deleteStudent(roll);
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please select 1-7.\n";
        }
    } while (choice != 7);

    return 0;
}
```

---

### 4B. Doubly Linked List (Music Playlist Manager)

> **Question:**  
> Design and develop a program to implement real-life applications of a Doubly Linked List by enabling operations such as insertion, updating, searching, sorting, listing, and deletion.  

```cpp
#include <iostream>
#include <string>
using namespace std;

// ==========================================
// NODE CLASS: Doubly Linked Node
// ==========================================
class Node
{
public:
    int songID;      // Unique Song Identifier
    string title;    // Song Title
    Node* prev;      // Pointer to the previous node
    Node* next;      // Pointer to the next node
};

// ==========================================
// DOUBLY LINKED LIST CLASS (Playlist)
// ==========================================
class DoublyLinkedList
{
private:
    Node* head; // Points to the first song in the playlist

    // Helper: Verify if a song ID already exists in the playlist
    bool exists(int id)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->songID == id)
                return true;
            temp = temp->next;
        }
        return false;
    }

public:
    // Constructor
    DoublyLinkedList()
    {
        head = NULL;
    }

    // Destructor: Clean up all dynamically allocated playlist nodes
    ~DoublyLinkedList()
    {
        Node* temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    // ------------------------------------------
    // OPERATION 1: INSERT SONG AT END
    // ------------------------------------------
    void insertSong(int id, string title)
    {
        if (exists(id))
        {
            cout << "Duplicate Song ID! Song already exists in playlist.\n";
            return;
        }

        // Allocate and initialize new doubly linked node
        Node* newNode = new Node();
        newNode->songID = id;
        newNode->title = title;
        newNode->prev = NULL;
        newNode->next = NULL;

        // If list is empty, new node becomes head
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            // Traverse to the end of the list
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            // Link previous last node and new node bidirectionally
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Song added to playlist.\n";
    }

    // ------------------------------------------
    // OPERATION 2: UPDATE SONG TITLE
    // ------------------------------------------
    void updateSong(int id)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->songID == id)
            {
                cout << "Enter New Song Title: ";
                cin >> ws;
                getline(cin, temp->title);
                cout << "Song updated successfully.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Song not found.\n";
    }

    // ------------------------------------------
    // OPERATION 3: SEARCH SONG BY ID
    // ------------------------------------------
    void searchSong(int id)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->songID == id)
            {
                cout << "Song Found! ID: " << temp->songID << ", Title: " << temp->title << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Song not found.\n";
    }

    // ------------------------------------------
    // OPERATION 4: SORT PLAYLIST BY SONG ID
    // ------------------------------------------
    void sortPlaylist()
    {
        if (head == NULL || head->next == NULL)
            return;

        // Bubble sort by swapping data fields
        for (Node* i = head; i->next != NULL; i = i->next)
        {
            for (Node* j = i->next; j != NULL; j = j->next)
            {
                if (i->songID > j->songID)
                {
                    // Swap Song ID
                    int tempID = i->songID;
                    i->songID = j->songID;
                    j->songID = tempID;

                    // Swap Song Title
                    string tempTitle = i->title;
                    i->title = j->title;
                    j->title = tempTitle;
                }
            }
        }
        cout << "Playlist sorted by Song ID.\n";
    }

    // ------------------------------------------
    // OPERATION 5: DELETE SONG BY ID
    // ------------------------------------------
    void deleteSong(int id)
    {
        Node* temp = head;

        // Search for the node to delete
        while (temp != NULL && temp->songID != id)
            temp = temp->next;

        // If not found
        if (temp == NULL)
        {
            cout << "Song not found.\n";
            return;
        }

        // Adjust previous node's next pointer
        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next; // Deleting the head node

        // Adjust next node's prev pointer
        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp; // Free memory
        cout << "Song removed from playlist.\n";
    }

    // ------------------------------------------
    // OPERATION 6: DISPLAY PLAYLIST
    // ------------------------------------------
    void display()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "\nID\tSong Title\n";
        cout << "------------------------------------\n";
        while (temp != NULL)
        {
            cout << temp->songID << "\t" << temp->title << endl;
            temp = temp->next;
        }
    }
};

// ==========================================
// MAIN FUNCTION (Interactive Menu)
// ==========================================
int main()
{
    DoublyLinkedList playlist;
    int choice, id;
    string title;

    do
    {
        cout << "\n===== PLAYLIST MENU (DOUBLY LINKED LIST) =====\n";
        cout << "1. Insert Song\n2. Update Song\n3. Search Song\n4. Sort Playlist\n5. Display Playlist\n6. Delete Song\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Song ID: ";
            cin >> id;
            cout << "Enter Song Title: ";
            cin >> ws;
            getline(cin, title);
            playlist.insertSong(id, title);
            break;
        case 2:
            cout << "Enter Song ID to update: ";
            cin >> id;
            playlist.updateSong(id);
            break;
        case 3:
            cout << "Enter Song ID to search: ";
            cin >> id;
            playlist.searchSong(id);
            break;
        case 4:
            playlist.sortPlaylist();
            break;
        case 5:
            playlist.display();
            break;
        case 6:
            cout << "Enter Song ID to delete: ";
            cin >> id;
            playlist.deleteSong(id);
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please select 1-7.\n";
        }
    } while (choice != 7);

    return 0;
}
```

---

### 4C. Circular Linked List (Round-Robin Task Scheduler)

> **Question:**  
> Design and develop a program to implement real-life applications of a Circular Linked List by enabling operations such as insertion, updating, searching, sorting, listing, and deletion.  

```cpp
#include <iostream>
#include <string>
using namespace std;

// ==========================================
// NODE CLASS: Circular Node
// ==========================================
class Node
{
public:
    int taskID;       // Unique Task Identifier
    string taskName;  // Name of the scheduled task
    Node* next;       // Points to the next node (last node points to head)
};

// ==========================================
// CIRCULAR LINKED LIST CLASS (Task Scheduler)
// ==========================================
class CircularLinkedList
{
private:
    Node* head; // Points to the first task

    // Helper: Check if a task ID exists in the circular list
    bool exists(int id)
    {
        if (head == NULL)
            return false;
        Node* temp = head;
        do
        {
            if (temp->taskID == id)
                return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }

public:
    // Constructor
    CircularLinkedList()
    {
        head = NULL;
    }

    // Destructor: Safely delete all nodes in the circular cycle
    ~CircularLinkedList()
    {
        if (head == NULL)
            return;
        Node* curr = head->next;
        while (curr != head)
        {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete head;
        head = NULL;
    }

    // ------------------------------------------
    // OPERATION 1: INSERT TASK INTO CIRCULAR QUEUE
    // ------------------------------------------
    void insertTask(int id, string name)
    {
        if (exists(id))
        {
            cout << "Duplicate Task ID! Task already exists.\n";
            return;
        }

        Node* newNode = new Node();
        newNode->taskID = id;
        newNode->taskName = name;

        // If list is empty, point newNode to itself to form a circle
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            // Traverse to the node currently pointing back to head
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;

            // Link last node to new node, and new node to head
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Task inserted into circular queue.\n";
    }

    // ------------------------------------------
    // OPERATION 2: UPDATE TASK DETAILS
    // ------------------------------------------
    void updateTask(int id)
    {
        if (head == NULL)
        {
            cout << "Task list is empty.\n";
            return;
        }
        Node* temp = head;
        do
        {
            if (temp->taskID == id)
            {
                cout << "Enter New Task Name: ";
                cin >> temp->taskName;
                cout << "Task updated successfully.\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Task not found.\n";
    }

    // ------------------------------------------
    // OPERATION 3: SEARCH TASK BY ID
    // ------------------------------------------
    void searchTask(int id)
    {
        if (head == NULL)
        {
            cout << "Task list is empty.\n";
            return;
        }
        Node* temp = head;
        do
        {
            if (temp->taskID == id)
            {
                cout << "Task Found! ID: " << temp->taskID << ", Name: " << temp->taskName << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Task not found.\n";
    }

    // ------------------------------------------
    // OPERATION 4: SORT TASKS BY TASK ID
    // ------------------------------------------
    void sortTasks()
    {
        if (head == NULL || head->next == head)
            return;

        // Bubble sort on circular list
        Node* i = head;
        do
        {
            Node* j = i->next;
            while (j != head)
            {
                if (i->taskID > j->taskID)
                {
                    // Swap Task ID
                    int tempID = i->taskID;
                    i->taskID = j->taskID;
                    j->taskID = tempID;

                    // Swap Task Name
                    string tempName = i->taskName;
                    i->taskName = j->taskName;
                    j->taskName = tempName;
                }
                j = j->next;
            }
            i = i->next;
        } while (i->next != head);

        cout << "Tasks sorted by Task ID.\n";
    }

    // ------------------------------------------
    // OPERATION 5: DELETE TASK BY ID
    // ------------------------------------------
    void deleteTask(int id)
    {
        if (head == NULL)
        {
            cout << "Task list is empty.\n";
            return;
        }

        Node *curr = head, *prev = NULL;

        // Traverse circularly looking for the node with taskID == id
        while (curr->taskID != id)
        {
            if (curr->next == head)
            {
                cout << "Task not found.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        // Case 1: Only one node in the entire list
        if (curr == head && curr->next == head)
        {
            head = NULL;
            delete curr;
        }
        // Case 2: Deleting head node with multiple nodes present
        else if (curr == head)
        {
            // Find the last node to update its next pointer
            prev = head;
            while (prev->next != head)
                prev = prev->next;
            head = head->next;    // Advance head
            prev->next = head;    // Update last node's circular link
            delete curr;
        }
        // Case 3: Deleting an intermediate or last node
        else
        {
            prev->next = curr->next;
            delete curr;
        }
        cout << "Task deleted successfully.\n";
    }

    // ------------------------------------------
    // OPERATION 6: DISPLAY ALL SCHEDULED TASKS
    // ------------------------------------------
    void display()
    {
        if (head == NULL)
        {
            cout << "No active tasks.\n";
            return;
        }
        Node* temp = head;
        cout << "\nTaskID\tTaskName\n";
        cout << "------------------------------------\n";
        do
        {
            cout << temp->taskID << "\t" << temp->taskName << endl;
            temp = temp->next;
        } while (temp != head); // Stop when we complete one full circle
    }
};

// ==========================================
// MAIN FUNCTION (Interactive Menu)
// ==========================================
int main()
{
    CircularLinkedList scheduler;
    int choice, id;
    string name;

    do
    {
        cout << "\n===== TASK SCHEDULER (CIRCULAR LINKED LIST) =====\n";
        cout << "1. Insert Task\n2. Update Task\n3. Search Task\n4. Sort Tasks\n5. Display Tasks\n6. Delete Task\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Task ID: ";
            cin >> id;
            cout << "Enter Task Name: ";
            cin >> name;
            scheduler.insertTask(id, name);
            break;
        case 2:
            cout << "Enter Task ID to update: ";
            cin >> id;
            scheduler.updateTask(id);
            break;
        case 3:
            cout << "Enter Task ID to search: ";
            cin >> id;
            scheduler.searchTask(id);
            break;
        case 4:
            scheduler.sortTasks();
            break;
        case 5:
            scheduler.display();
            break;
        case 6:
            cout << "Enter Task ID to delete: ";
            cin >> id;
            scheduler.deleteTask(id);
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please select 1-7.\n";
        }
    } while (choice != 7);

    return 0;
}
```

---

### 5A. Infix to Postfix Conversion

> **Question:**  
> Given as input an infix expression. Implement a program for following conversions :- Infix to postfix.  

```cpp
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// ==========================================
// HELPER: CHECK IF CHARACTER IS AN OPERATOR
// ==========================================
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// ==========================================
// OPERATOR PRECEDENCE
// ==========================================
// Returns higher integer for operators with higher mathematical precedence
int precedence(char op)
{
    if (op == '^')
        return 3; // Exponentiation has highest precedence
    else if (op == '*' || op == '/')
        return 2; // Multiplication and Division
    else if (op == '+' || op == '-')
        return 1; // Addition and Subtraction
    else
        return 0; // Parentheses or non-operators
}

// ==========================================
// INFIX TO POSTFIX CONVERSION (Using Stack)
// ==========================================
bool infixToPostfix(string infix, string& postfix)
{
    stack<char> s; // Stack to hold operators and opening parentheses
    postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        // 1. If scanned character is an operand (alphanumeric), append directly to postfix
        if (isalnum(ch))
        {
            postfix += ch;
        }
        // 2. If '(', push it onto the stack
        else if (ch == '(')
        {
            s.push(ch);
        }
        // 3. If ')', pop from stack to output until '(' is encountered
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (s.empty())
            {
                // Unmatched closing parenthesis error
                return false;
            }
            s.pop(); // Discard the matching '('
        }
        // 4. If an operator is encountered
        else if (isOperator(ch))
        {
            // Pop operators with higher or equal precedence (except right-associative '^')
            while (!s.empty() && s.top() != '(' &&
                   (precedence(s.top()) > precedence(ch) ||
                    (precedence(s.top()) == precedence(ch) && ch != '^')))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch); // Push current operator onto stack
        }
        else
        {
            return false; // Invalid token in expression
        }
    }

    // 5. Pop all remaining operators from the stack
    while (!s.empty())
    {
        if (s.top() == '(')
        {
            // Unmatched opening parenthesis error
            return false;
        }
        postfix += s.top();
        s.pop();
    }
    return true;
}

// ==========================================
// MAIN FUNCTION
// ==========================================
int main()
{
    string infix, postfix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    // Convert and display result
    if (infixToPostfix(infix, postfix))
        cout << "Postfix expression: " << postfix << endl;
    else
        cout << "Invalid infix expression! Check parentheses or operators.\n";

    return 0;
}
```

---

### 5B. Postfix Evaluation

> **Question:**  
> Given as input a postfix expression. Implement a program for following conversion : postfix evaluation.  

```cpp
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// ==========================================
// MAIN FUNCTION: POSTFIX EVALUATION USING STACK
// ==========================================
int main()
{
    string postfix;
    stack<int> s; // Stack to hold intermediate integer operands

    cout << "Enter a postfix expression (single-digit operands): ";
    cin >> postfix;

    // Scan the postfix expression from left to right
    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        // 1. If operand, convert char digit to int and push onto stack
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        // 2. If operator, pop two operands, perform operation, and push result
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            // Verify sufficient operands on stack
            if (s.size() < 2)
            {
                cout << "Invalid postfix expression! Insufficient operands.\n";
                return 0;
            }

            int b = s.top(); // Second operand was on top
            s.pop();
            int a = s.top(); // First operand was below it
            s.pop();

            switch (ch)
            {
            case '+':
                s.push(a + b);
                break;
            case '-':
                s.push(a - b);
                break;
            case '*':
                s.push(a * b);
                break;
            case '/':
                // Handle division by zero error
                if (b == 0)
                {
                    cout << "Division by zero error!\n";
                    return 0;
                }
                s.push(a / b);
                break;
            }
        }
        // 3. Reject unrecognized characters
        else
        {
            cout << "Invalid character '" << ch << "' in expression!\n";
            return 0;
        }
    }

    // After processing, stack must have exactly one element (the final result)
    if (s.size() != 1)
    {
        cout << "Invalid postfix expression! Extra operands remaining.\n";
        return 0;
    }

    // Display evaluated final result
    cout << "Result = " << s.top() << endl;
    return 0;
}
```

---

### 5C. Stack Using Linked List

> **Question:**  
> Implement a program for Stack using Linked List.  

```cpp
#include <iostream>
using namespace std;

// ==========================================
// NODE CLASS: Stack Node
// ==========================================
class Node
{
public:
    int data;    // Value stored in the stack element
    Node* next;  // Pointer to the next node down the stack
};

// ==========================================
// STACK CLASS (Linked List Implementation)
// ==========================================
class Stack
{
private:
    Node* top; // Points to the top element of the stack

public:
    // Constructor: Initialize empty stack
    Stack()
    {
        top = NULL;
    }

    // Destructor: Clean up remaining allocated nodes
    ~Stack()
    {
        while (top != NULL)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // ------------------------------------------
    // OPERATION 1: PUSH (Insert at Top)
    // ------------------------------------------
    void push(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top; // Link new node to previous top
        top = newNode;       // Make new node the new top
        cout << value << " pushed into stack.\n";
    }

    // ------------------------------------------
    // OPERATION 2: POP (Delete from Top)
    // ------------------------------------------
    void pop()
    {
        // Underflow condition: Stack is empty
        if (top == NULL)
        {
            cout << "Stack Underflow! Stack is empty.\n";
            return;
        }

        Node* temp = top;
        cout << top->data << " popped from stack.\n";
        top = top->next; // Advance top pointer down
        delete temp;     // Free popped node memory
    }

    // ------------------------------------------
    // OPERATION 3: DISPLAY STACK ELEMENTS
    // ------------------------------------------
    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty.\n";
            return;
        }

        Node* temp = top;
        cout << "Stack elements (Top to Bottom): ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ==========================================
// MAIN FUNCTION (Interactive Menu)
// ==========================================
int main()
{
    Stack s;
    int choice, value;

    do
    {
        cout << "\n----- STACK MENU -----\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            cout << "Program terminated.\n";
            break;
        default:
            cout << "Invalid choice! Please select 1-4.\n";
        }
    } while (choice != 4);

    return 0;
}
```

---

### 6. Circular Queue (Service Request Management)

> **Question:**  
> Implement a Circular Queue-based system to manage real-life service requests, ensuring efficient customer handling using the FIFO approach, where resolved requests free up slots for new entries without data shifting.  

```cpp
#include <iostream>
#include <string>
using namespace std;

#define SIZE 5 // Maximum capacity of circular queue

// ==========================================
// CIRCULAR QUEUE CLASS
// ==========================================
class CircularQueue
{
    string requests[SIZE]; // Fixed-size circular array for request descriptions
    int front;             // Index pointing to the first service request
    int rear;              // Index pointing to the last service request
    int count;             // Current number of elements stored

public:
    // Constructor
    CircularQueue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    // ------------------------------------------
    // OPERATION 1: ENQUEUE (Add Request at Rear)
    // ------------------------------------------
    void enqueue(string request)
    {
        // Overflow condition: Queue is full
        if (count == SIZE)
        {
            cout << "Queue is full! Cannot add request.\n";
            return;
        }

        // Circular increment of rear pointer
        rear = (rear + 1) % SIZE;
        requests[rear] = request;
        count++; // Increment element count
        cout << "Request added: " << request << endl;
    }

    // ------------------------------------------
    // OPERATION 2: DEQUEUE (Resolve Request at Front)
    // ------------------------------------------
    void dequeue()
    {
        // Underflow condition: Queue is empty
        if (count == 0)
        {
            cout << "No pending service requests.\n";
            return;
        }

        // Resolve customer request at front
        cout << "Request resolved: " << requests[front] << endl;

        // Circular increment of front pointer
        front = (front + 1) % SIZE;
        count--; // Decrement element count
    }

    // ------------------------------------------
    // OPERATION 3: DISPLAY ALL PENDING REQUESTS
    // ------------------------------------------
    void display()
    {
        if (count == 0)
        {
            cout << "No pending requests.\n";
            return;
        }

        cout << "\nPending Service Requests (FIFO order):\n";
        cout << "------------------------------------\n";
        for (int i = 0; i < count; i++)
        {
            // Calculate circular offset from front
            int index = (front + i) % SIZE;
            cout << i + 1 << ". " << requests[index] << endl;
        }
    }
};

// ==========================================
// MAIN FUNCTION (Interactive Menu)
// ==========================================
int main()
{
    CircularQueue q;
    int choice;
    string request;

    do
    {
        cout << "\n--- Service Request Management ---\n";
        cout << "1. Add Request\n2. Resolve Request\n3. Display Requests\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter service request: ";
            cin >> ws;
            getline(cin, request);
            q.enqueue(request);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting system...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
```

---

### 7. Double Ended Queue (Shopping Mall Billing Queue)

> **Question:**  
> Design and implement a program for double ended queue and its operations for a shopping mall under given Scenarios :-  
> a) Input Restricted Deque  
> b) Output Restricted Deque.  

```cpp
#include <iostream>
#include <string>
using namespace std;

#define SIZE 5 // Maximum capacity of Deque

// ==========================================
// HELPER: ROBUST INTEGER INPUT READER
// ==========================================
int readInt(const string& prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
            return value;
        cout << "Invalid input! Please enter a number.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

// ==========================================
// DOUBLE ENDED QUEUE (DEQUE) CLASS
// ==========================================
class Deque
{
    string customers[SIZE]; // Circular array buffer
    int front;              // Index of the front element
    int rear;               // Index of the rear element
    int count;              // Number of active customers in queue

public:
    // Constructor
    Deque()
    {
        front = -1;
        rear = -1;
        count = 0;
    }

    // Helper functions for state checking
    bool isFull()  { return count == SIZE; }
    bool isEmpty() { return count == 0; }

    // ------------------------------------------
    // OPERATION 1: INSERT AT REAR
    // ------------------------------------------
    void insertRear(string name)
    {
        if (isFull())
        {
            cout << "Queue is full!\n";
            return;
        }

        // First insertion in empty queue
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE; // Circular advance of rear

        customers[rear] = name;
        count++;
        cout << name << " added successfully.\n";
    }

    // ------------------------------------------
    // OPERATION 2: INSERT AT FRONT
    // ------------------------------------------
    void insertFront(string name)
    {
        if (isFull())
        {
            cout << "Queue is full!\n";
            return;
        }

        // First insertion in empty queue
        if (isEmpty())
            front = rear = 0;
        else
            front = (front - 1 + SIZE) % SIZE; // Circular backward movement of front

        customers[front] = name;
        count++;
        cout << name << " added successfully.\n";
    }

    // ------------------------------------------
    // OPERATION 3: DELETE FROM FRONT
    // ------------------------------------------
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "No customers in the queue!\n";
            return;
        }

        cout << "Customer served: " << customers[front] << endl;

        // If queue becomes empty after serving
        if (front == rear)
        {
            front = rear = -1;
            count = 0;
        }
        else
        {
            front = (front + 1) % SIZE; // Circular advance of front
            count--;
        }
    }

    // ------------------------------------------
    // OPERATION 4: DELETE FROM REAR
    // ------------------------------------------
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "No customers in the queue!\n";
            return;
        }

        cout << "Customer removed: " << customers[rear] << endl;

        // If queue becomes empty after deletion
        if (front == rear)
        {
            front = rear = -1;
            count = 0;
        }
        else
        {
            rear = (rear - 1 + SIZE) % SIZE; // Circular backward movement of rear
            count--;
        }
    }

    // ------------------------------------------
    // OPERATION 5: DISPLAY QUEUE
    // ------------------------------------------
    void display()
    {
        if (isEmpty())
        {
            cout << "No customers waiting.\n";
            return;
        }

        cout << "Customers in queue: ";
        for (int i = 0; i < count; i++)
            cout << customers[(front + i) % SIZE] << " ";
        cout << endl;
    }
};

// ==========================================
// MAIN FUNCTION (Interactive Menu)
// ==========================================
int main()
{
    Deque d;
    int type, choice;
    string name;

    cout << "SHOPPING MALL QUEUE MANAGEMENT\n";

    // ------------------------------------------
    // SELECT DEQUE TYPE RESTRICTION
    // ------------------------------------------
    do
    {
        cout << "1. Input-Restricted Deque (Insert at rear only, delete from both ends)\n";
        cout << "2. Output-Restricted Deque (Delete from front only, insert at both ends)\n";
        type = readInt("Select deque type (only 1 or 2): ");
        if (type != 1 && type != 2)
            cout << "Invalid deque selection! Please enter only 1 or 2.\n";
    } while (type != 1 && type != 2);

    // ------------------------------------------
    // MENU-DRIVEN OPERATIONS
    // ------------------------------------------
    do
    {
        cout << "\n1. Insert at Rear\n2. Insert at Front\n3. Delete from Front\n4. Delete from Rear\n5. Display Queue\n6. Exit\n";
        choice = readInt("Enter choice: ");

        switch (choice)
        {
        case 1:
            cout << "Enter customer name: ";
            cin >> ws;
            getline(cin, name);
            d.insertRear(name);
            break;
        case 2:
            // Input-restricted allows insertion only at rear
            if (type == 2)
            {
                cout << "Enter customer name: ";
                cin >> ws;
                getline(cin, name);
                d.insertFront(name);
            }
            else
                cout << "Insertion allowed only at rear in Input-Restricted Deque!\n";
            break;
        case 3:
            d.deleteFront();
            break;
        case 4:
            // Output-restricted allows deletion only from front
            if (type == 1)
                d.deleteRear();
            else
                cout << "Deletion allowed only from front in Output-Restricted Deque!\n";
            break;
        case 5:
            d.display();
            break;
        case 6:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Please enter 1-6.\n";
        }
    } while (choice != 6);

    return 0;
}
```

---

### 8A & 8B. Binary Search Tree (Student Record Management System)

> **Question:**  
> A software company is developing a student record management system for a university. The system needs to efficiently store and retrieve student records based on their unique roll numbers using a Binary Search Tree (BST).  
> The university requires the following operations:  
> - **8A:** Finding the student with the smallest roll number (minimum key).  
> - **8A:** Finding the student with the largest roll number (maximum key).  
> - **8A:** Searching for a student using a given roll number.  
> - **8B:** BST Display- Inorder, Preorder and Postorder.  

```cpp
#include <iostream>
#include <string>
using namespace std;

// ==========================================
// BST NODE CLASS
// ==========================================
class Node
{
public:
    int rollNo;     // Key: Unique student roll number
    string name;    // Student name
    float marks;    // Student marks
    Node* left;     // Pointer to the left child (holds keys < rollNo)
    Node* right;    // Pointer to the right child (holds keys > rollNo)

    // Node Constructor
    Node(int r, string n, float m)
    {
        rollNo = r;
        name = n;
        marks = m;
        left = right = NULL;
    }
};

// ==========================================
// BINARY SEARCH TREE (BST) CLASS
// ==========================================
class StudentBST
{
private:
    // Helper: Recursively deletes all nodes in postorder to prevent memory leaks
    void destroyTree(Node* node)
    {
        if (node == NULL)
            return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    Node* root; // Root pointer of the Binary Search Tree

    // Constructor: Initializes empty tree
    StudentBST()
    {
        root = NULL;
    }

    // Destructor: Automatically frees tree memory
    ~StudentBST()
    {
        destroyTree(root);
        root = NULL;
    }

    // ------------------------------------------
    // OPERATION 1: INSERT RECORD INTO BST
    // ------------------------------------------
    Node* insert(Node* node, int roll, string name, float marks)
    {
        // Base case: Found insertion point
        if (node == NULL)
            return new Node(roll, name, marks);

        // If new key is smaller, insert into left subtree
        if (roll < node->rollNo)
            node->left = insert(node->left, roll, name, marks);
        // If new key is greater, insert into right subtree
        else if (roll > node->rollNo)
            node->right = insert(node->right, roll, name, marks);
        // Duplicate key rejection
        else
            cout << "Duplicate Roll Number not allowed!\n";

        return node;
    }

    // ------------------------------------------
    // OPERATION 8A: FIND MINIMUM ROLL NUMBER
    // ------------------------------------------
    // In a BST, the leftmost node always contains the minimum key
    void findMin(Node* node)
    {
        if (node == NULL)
        {
            cout << "Tree is empty.\n";
            return;
        }
        // Traverse as far left as possible
        while (node->left != NULL)
            node = node->left;

        cout << "Smallest Roll No -> Roll: " << node->rollNo
             << ", Name: " << node->name << ", Marks: " << node->marks << endl;
    }

    // ------------------------------------------
    // OPERATION 8A: FIND MAXIMUM ROLL NUMBER
    // ------------------------------------------
    // In a BST, the rightmost node always contains the maximum key
    void findMax(Node* node)
    {
        if (node == NULL)
        {
            cout << "Tree is empty.\n";
            return;
        }
        // Traverse as far right as possible
        while (node->right != NULL)
            node = node->right;

        cout << "Largest Roll No -> Roll: " << node->rollNo
             << ", Name: " << node->name << ", Marks: " << node->marks << endl;
    }

    // ------------------------------------------
    // OPERATION 8A: SEARCH BY ROLL NUMBER
    // ------------------------------------------
    void search(Node* node, int key)
    {
        if (node == NULL)
        {
            cout << "Student with Roll No " << key << " not found.\n";
            return;
        }

        // Key matched
        if (node->rollNo == key)
        {
            cout << "Student Found! Roll: " << node->rollNo
                 << ", Name: " << node->name << ", Marks: " << node->marks << endl;
            return;
        }

        // If key is smaller, search left subtree; otherwise search right subtree
        if (key < node->rollNo)
            search(node->left, key);
        else
            search(node->right, key);
    }

    // ------------------------------------------
    // OPERATION 8B: INORDER TRAVERSAL (Left, Root, Right)
    // Produces sorted ascending order of keys
    // ------------------------------------------
    void inorder(Node* node)
    {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->rollNo << " (" << node->name << ")  ";
        inorder(node->right);
    }

    // ------------------------------------------
    // OPERATION 8B: PREORDER TRAVERSAL (Root, Left, Right)
    // Useful for copying/serializing the tree structure
    // ------------------------------------------
    void preorder(Node* node)
    {
        if (node == NULL)
            return;
        cout << node->rollNo << " (" << node->name << ")  ";
        preorder(node->left);
        preorder(node->right);
    }

    // ------------------------------------------
    // OPERATION 8B: POSTORDER TRAVERSAL (Left, Right, Root)
    // Useful for bottom-up cleanup/deletion
    // ------------------------------------------
    void postorder(Node* node)
    {
        if (node == NULL)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->rollNo << " (" << node->name << ")  ";
    }
};

// ==========================================
// MAIN FUNCTION (Interactive Menu)
// ==========================================
int main()
{
    StudentBST bst;
    int choice, roll;
    string name;
    float marks;

    do
    {
        cout << "\n===== STUDENT BST MANAGEMENT =====\n";
        cout << "1. Insert Student Record\n";
        cout << "2. Find Smallest Roll Number (Min)\n";
        cout << "3. Find Largest Roll Number (Max)\n";
        cout << "4. Search Student by Roll Number\n";
        cout << "5. Display Traversals (Inorder / Preorder / Postorder)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Roll Number: ";
            cin >> roll;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Marks: ";
            cin >> marks;
            bst.root = bst.insert(bst.root, roll, name, marks);
            break;
        case 2:
            bst.findMin(bst.root);
            break;
        case 3:
            bst.findMax(bst.root);
            break;
        case 4:
            cout << "Enter Roll Number to search: ";
            cin >> roll;
            bst.search(bst.root, roll);
            break;
        case 5:
            if (bst.root == NULL)
            {
                cout << "Tree is empty.\n";
                break;
            }
            cout << "\nInorder   (Left-Root-Right): ";
            bst.inorder(bst.root);
            cout << "\nPreorder  (Root-Left-Right): ";
            bst.preorder(bst.root);
            cout << "\nPostorder (Left-Right-Root): ";
            bst.postorder(bst.root);
            cout << endl;
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please select 1-6.\n";
        }
    } while (choice != 6);

    return 0;
}
```

---

### 9A & 9B. Graph Traversal System (Delivery Route Finder — BFS & DFS)

> **Question:**  
> Design and implement a Graph Traversal System to help a delivery company:  
> - **9A:** Find the shortest route to a delivery location using BFS.  
> - **9B:** Explore all possible routes for better traffic management using DFS.  

```cpp
#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define MAX 20 // Maximum supported delivery locations (vertices)

// ==========================================
// HELPER: ROBUST INTEGER INPUT READER
// ==========================================
// Prevents terminal lockup / infinite loops when non-numeric inputs are entered
int readInt(const string& prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
            return value;
        cout << "Invalid numeric input! Please enter a valid integer.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

// ==========================================
// DELIVERY GRAPH CLASS (Adjacency Matrix)
// ==========================================
class DeliveryGraph
{
    int vertices;           // Number of locations
    string locations[MAX];  // Names of delivery locations
    int adj[MAX][MAX];      // Adjacency Matrix: adj[u][v] = 1 if road exists between u and v

public:
    // Constructor: Initialize matrix to all zeros (no edges)
    DeliveryGraph(int v)
    {
        vertices = v;
        for (int i = 0; i < vertices; i++)
            for (int j = 0; j < vertices; j++)
                adj[i][j] = 0;
    }

    // Helper: Validates whether vertex index is within bounds [0, vertices-1]
    bool isValidVertex(int idx)
    {
        return (idx >= 0 && idx < vertices);
    }

    // Assign a human-readable location name to a vertex index
    void setLocationName(int index, string name)
    {
        if (isValidVertex(index))
            locations[index] = name;
    }

    // Add an undirected road between location u and location v
    // Returns: 1 = added, 0 = invalid vertex/self-loop, -1 = duplicate road
    int addRoute(int u, int v)
    {
        if (!isValidVertex(u) || !isValidVertex(v) || u == v)
            return 0; // Invalid indices or self-loop
        if (adj[u][v] == 1)
            return -1; // Road connection already present

        // Graph is undirected: road works both ways
        adj[u][v] = 1;
        adj[v][u] = 1;
        return 1;
    }

    // ------------------------------------------
    // OPERATION 9A: SHORTEST DELIVERY ROUTE USING BFS
    // ------------------------------------------
    // Breadth-First Search (BFS) explores level-by-level using a queue,
    // guaranteeing the shortest path in terms of number of hops (edges).
    void shortestRouteBFS(int start, int dest)
    {
        if (!isValidVertex(start) || !isValidVertex(dest))
        {
            cout << "Invalid location index! Must be between 0 and " << vertices - 1 << ".\n";
            return;
        }

        bool visited[MAX] = {false}; // Tracks visited locations
        int parent[MAX];             // Tracks predecessor node to reconstruct path
        for (int i = 0; i < vertices; i++)
            parent[i] = -1;

        queue<int> q;                // BFS queue

        // Enqueue start location and mark visited
        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            // Destination reached: stop early
            if (curr == dest)
                break;

            // Check all neighboring vertices
            for (int i = 0; i < vertices; i++)
            {
                if (adj[curr][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    parent[i] = curr; // Record predecessor
                    q.push(i);
                }
            }
        }

        // If destination was never reached
        if (!visited[dest])
        {
            cout << "No route available between " << locations[start]
                 << " and " << locations[dest] << ".\n";
            return;
        }

        // Reconstruct path backwards from dest to start via parent pointers
        int path[MAX], pathLen = 0;
        for (int v = dest; v != -1; v = parent[v])
            path[pathLen++] = v;

        // Display shortest path in forward order
        cout << "\nShortest Delivery Route (BFS): ";
        for (int i = pathLen - 1; i >= 0; i--)
        {
            cout << locations[path[i]];
            if (i > 0)
                cout << " -> ";
        }
        cout << "\nTotal Hops: " << pathLen - 1 << endl;
    }

    // ------------------------------------------
    // OPERATION 9B: EXPLORE ALL ROUTES USING DFS
    // ------------------------------------------
    // Depth-First Search with backtracking to discover every possible path
    void exploreAllRoutesDFS(int curr, int dest, bool visited[], int path[], int pathIndex, bool& routeFound)
    {
        visited[curr] = true;      // Mark current location in active path
        path[pathIndex] = curr;    // Add current vertex to path history
        pathIndex++;

        // If target reached, print the current full route
        if (curr == dest)
        {
            routeFound = true;
            for (int i = 0; i < pathIndex; i++)
            {
                cout << locations[path[i]];
                if (i < pathIndex - 1)
                    cout << " -> ";
            }
            cout << endl;
        }
        else
        {
            // Recur for all adjacent unvisited vertices
            for (int i = 0; i < vertices; i++)
            {
                if (adj[curr][i] == 1 && !visited[i])
                    exploreAllRoutesDFS(i, dest, visited, path, pathIndex, routeFound);
            }
        }

        // Backtrack: Unmark current vertex so other paths can traverse through it
        visited[curr] = false;
    }

    // Wrapper function for DFS all routes
    void findAllRoutes(int start, int dest)
    {
        if (!isValidVertex(start) || !isValidVertex(dest))
        {
            cout << "Invalid location index! Must be between 0 and " << vertices - 1 << ".\n";
            return;
        }

        bool visited[MAX] = {false};
        int path[MAX];
        bool routeFound = false;

        cout << "\nAll Possible Routes (DFS) from " << locations[start]
             << " to " << locations[dest] << ":\n";
        exploreAllRoutesDFS(start, dest, visited, path, 0, routeFound);

        if (!routeFound)
            cout << "No route available between " << locations[start]
                 << " and " << locations[dest] << ".\n";
    }
};

// ==========================================
// MAIN FUNCTION (Interactive Menu)
// ==========================================
int main()
{
    int v, e, u, w, choice, start, dest;
    string name;

    cout << "===== DELIVERY ROUTE GRAPH SYSTEM =====\n";

    // ------------------------------------------
    // INPUT NUMBER OF LOCATIONS (VERTICES)
    // ------------------------------------------
    do
    {
        v = readInt("Enter number of delivery locations (1 to 20): ");
        if (v < 1 || v > MAX)
            cout << "Invalid count! Must be between 1 and " << MAX << ".\n";
    } while (v < 1 || v > MAX);

    DeliveryGraph g(v);

    // Input names for each delivery location
    for (int i = 0; i < v; i++)
    {
        do
        {
            cout << "Enter name for Location " << i << ": ";
            cin >> ws;
            getline(cin, name);
            if (name.empty())
                cout << "Location name cannot be empty!\n";
        } while (name.empty());
        g.setLocationName(i, name);
    }

    // ------------------------------------------
    // INPUT ROAD CONNECTIONS (EDGES)
    // ------------------------------------------
    int maxEdges = (v * (v - 1)) / 2; // Maximum edges in an undirected graph
    do
    {
        e = readInt("Enter number of road connections (0 to " + to_string(maxEdges) + "): ");
        if (e < 0 || e > maxEdges)
            cout << "Invalid count! Must be between 0 and " << maxEdges << ".\n";
    } while (e < 0 || e > maxEdges);

    cout << "Enter connected location indices (0 to " << v - 1 << "):\n";
    for (int i = 0; i < e; i++)
    {
        cout << "Connection " << i + 1 << " (u v): ";
        if (!(cin >> u >> w))
        {
            cout << "Invalid numeric input! Re-enter connection " << i + 1 << ".\n";
            cin.clear();
            cin.ignore(10000, '\n');
            i--;
            continue;
        }

        int status = g.addRoute(u, w);
        if (status == 0)
        {
            cout << "Invalid connection! Indices must be distinct and between 0 and " << v - 1 << ".\n";
            i--;
        }
        else if (status == -1)
        {
            cout << "Duplicate road! Connection already exists. Enter a different road.\n";
            i--;
        }
    }

    // ------------------------------------------
    // ROUTE NAVIGATION MENU
    // ------------------------------------------
    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Find Shortest Route (BFS - 9A)\n";
        cout << "2. Explore All Possible Routes (DFS - 9B)\n";
        cout << "3. Exit\n";
        choice = readInt("Enter your choice: ");

        switch (choice)
        {
        case 1:
            start = readInt("Enter Start Location index: ");
            dest = readInt("Enter Destination index: ");
            g.shortestRouteBFS(start, dest);
            break;
        case 2:
            start = readInt("Enter Start Location index: ");
            dest = readInt("Enter Destination index: ");
            g.findAllRoutes(start, dest);
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please select 1-3.\n";
        }
    } while (choice != 3);

    return 0;
}
```
