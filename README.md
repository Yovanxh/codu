# DSA Practical Programs (C++)

This repository contains all 17 practical programs for the **Data Structures and Algorithms (DSA) Practical Examination**, structured with questions and copyable C++ source code.

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
```

---

### 2. Hashing with Linear Probing (Retail Inventory System)

> **Question:**  
> Implement hashing techniques for efficient data storage and retrieval in real-world applications, using linear probing to resolve collisions in practical scenarios.  

```cpp
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

    // Fix 2: Reject negative product codes (prevents negative index & EMPTY = -1 collision)
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

    // Fix 1 & 3: Validate tableSize (1 to SIZE) before starting the menu
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
    int n, i, j, minIndex, temp;
    int marks[100];

    do
    {
        cout << "Enter number of students (1 to 100): ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "Invalid count! Must be between 1 and 100.\n";
    } while (n < 1 || n > 100);

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

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (marks[j] < marks[minIndex])
                minIndex = j;
        }
        temp = marks[i];
        marks[i] = marks[minIndex];
        marks[minIndex] = temp;
    }

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

void merge(int prices[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = prices[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = prices[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            prices[k++] = L[i++];
        else
            prices[k++] = R[j++];
    }

    while (i < n1)
        prices[k++] = L[i++];
    while (j < n2)
        prices[k++] = R[j++];
}

void mergeSort(int prices[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(prices, left, mid);
        mergeSort(prices, mid + 1, right);
        merge(prices, left, mid, right);
    }
}

int main()
{
    int n, prices[100];

    do
    {
        cout << "Enter number of flight ticket prices (1 to 100): ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "Invalid count! Must be between 1 and 100.\n";
    } while (n < 1 || n > 100);

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

    mergeSort(prices, 0, n - 1);

    cout << "\nFlight ticket prices in ascending order:\n";
    for (int i = 0; i < n; i++)
        cout << prices[i] << " ";
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
```

---

### 3D. Merge Sort (Job Applicants Experience — Descending)

> **Question:**  
> Develop a Merge Sort or Quick Sort based system to sort job applicants based on experience in descending order so that the most experienced candidates appear first.  

```cpp
#include <iostream>
using namespace std;

void merge(int experience[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = experience[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = experience[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
            experience[k++] = L[i++];
        else
            experience[k++] = R[j++];
    }

    while (i < n1)
        experience[k++] = L[i++];
    while (j < n2)
        experience[k++] = R[j++];
}

void mergeSort(int experience[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(experience, left, mid);
        mergeSort(experience, mid + 1, right);
        merge(experience, left, mid, right);
    }
}

int main()
{
    int n, experience[100];

    do
    {
        cout << "Enter number of job applicants (1 to 100): ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "Invalid count! Must be between 1 and 100.\n";
    } while (n < 1 || n > 100);

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

    mergeSort(experience, 0, n - 1);

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

struct Product
{
    int productID;
    string productName;
    float price;
    int quantity;
};

int sentinelSearch(Product products[], int n, int key)
{
    if (n <= 0)
        return -1;

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

    do
    {
        cout << "Enter number of products (1 to 100): ";
        cin >> n;
        if (n < 1 || n > 100)
            cout << "Invalid count! Must be between 1 and 100.\n";
    } while (n < 1 || n > 100);

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
```

---

### 4A. Singly Linked List (Student Record Management)

> **Question:**  
> Design and develop a program to implement real-life applications of a Singly Linked List by enabling operations such as insertion, updating, searching, sorting, listing, and deletion.  

```cpp
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int rollNo;
    string name;
    float marks;
    Node* next;
};

class SinglyLinkedList
{
private:
    Node* head;

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
    SinglyLinkedList()
    {
        head = NULL;
    }

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

    void insertStudent(int roll, string name, float marks)
    {
        if (exists(roll))
        {
            cout << "Duplicate Roll Number! Record already exists.\n";
            return;
        }

        Node* newNode = new Node();
        newNode->rollNo = roll;
        newNode->name = name;
        newNode->marks = marks;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Student record inserted successfully.\n";
    }

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

    void sortStudents()
    {
        if (head == NULL || head->next == NULL)
            return;

        for (Node* i = head; i->next != NULL; i = i->next)
        {
            for (Node* j = i->next; j != NULL; j = j->next)
            {
                if (i->rollNo > j->rollNo)
                {
                    int tempRoll = i->rollNo;
                    i->rollNo = j->rollNo;
                    j->rollNo = tempRoll;

                    string tempName = i->name;
                    i->name = j->name;
                    j->name = tempName;

                    float tempMarks = i->marks;
                    i->marks = j->marks;
                    j->marks = tempMarks;
                }
            }
        }
        cout << "Records sorted by Roll Number.\n";
    }

    void deleteStudent(int roll)
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }

        if (head->rollNo == roll)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Student deleted successfully.\n";
            return;
        }

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
            curr->next = temp->next;
            delete temp;
            cout << "Student deleted successfully.\n";
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "No student records available.\n";
            return;
        }
        Node* temp = head;
        cout << "\nRollNo\tName\tMarks\n";
        while (temp != NULL)
        {
            cout << temp->rollNo << "\t" << temp->name << "\t" << temp->marks << endl;
            temp = temp->next;
        }
    }
};

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
            cout << "Invalid choice!\n";
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

class Node
{
public:
    int songID;
    string title;
    Node* prev;
    Node* next;
};

class DoublyLinkedList
{
private:
    Node* head;

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
    DoublyLinkedList()
    {
        head = NULL;
    }

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

    void insertSong(int id, string title)
    {
        if (exists(id))
        {
            cout << "Duplicate Song ID! Song already exists in playlist.\n";
            return;
        }

        Node* newNode = new Node();
        newNode->songID = id;
        newNode->title = title;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Song added to playlist.\n";
    }

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

    void sortPlaylist()
    {
        if (head == NULL || head->next == NULL)
            return;

        for (Node* i = head; i->next != NULL; i = i->next)
        {
            for (Node* j = i->next; j != NULL; j = j->next)
            {
                if (i->songID > j->songID)
                {
                    int tempID = i->songID;
                    i->songID = j->songID;
                    j->songID = tempID;

                    string tempTitle = i->title;
                    i->title = j->title;
                    j->title = tempTitle;
                }
            }
        }
        cout << "Playlist sorted by Song ID.\n";
    }

    void deleteSong(int id)
    {
        Node* temp = head;
        while (temp != NULL && temp->songID != id)
            temp = temp->next;

        if (temp == NULL)
        {
            cout << "Song not found.\n";
            return;
        }

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
        cout << "Song removed from playlist.\n";
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "\nID\tSong Title\n";
        while (temp != NULL)
        {
            cout << temp->songID << "\t" << temp->title << endl;
            temp = temp->next;
        }
    }
};

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
            cout << "Invalid choice!\n";
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

class Node
{
public:
    int taskID;
    string taskName;
    Node* next;
};

class CircularLinkedList
{
private:
    Node* head;

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
    CircularLinkedList()
    {
        head = NULL;
    }

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

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Task inserted into circular queue.\n";
    }

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

    void sortTasks()
    {
        if (head == NULL || head->next == head)
            return;

        Node* i = head;
        do
        {
            Node* j = i->next;
            while (j != head)
            {
                if (i->taskID > j->taskID)
                {
                    int tempID = i->taskID;
                    i->taskID = j->taskID;
                    j->taskID = tempID;

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

    void deleteTask(int id)
    {
        if (head == NULL)
        {
            cout << "Task list is empty.\n";
            return;
        }

        Node *curr = head, *prev = NULL;
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

        if (curr == head && curr->next == head)
        {
            head = NULL;
            delete curr;
        }
        else if (curr == head)
        {
            prev = head;
            while (prev->next != head)
                prev = prev->next;
            head = head->next;
            prev->next = head;
            delete curr;
        }
        else
        {
            prev->next = curr->next;
            delete curr;
        }
        cout << "Task deleted successfully.\n";
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "No active tasks.\n";
            return;
        }
        Node* temp = head;
        cout << "\nTaskID\tTaskName\n";
        do
        {
            cout << temp->taskID << "\t" << temp->taskName << endl;
            temp = temp->next;
        } while (temp != head);
    }
};

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
            cout << "Invalid choice!\n";
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

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

bool infixToPostfix(string infix, string& postfix)
{
    stack<char> s;
    postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (s.empty())
            {
                // Unmatched closing parenthesis
                return false;
            }
            s.pop(); // Pop matching '('
        }
        else if (isOperator(ch))
        {
            while (!s.empty() && s.top() != '(' &&
                   (precedence(s.top()) > precedence(ch) ||
                    (precedence(s.top()) == precedence(ch) && ch != '^')))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
        else
        {
            return false; // Invalid character
        }
    }

    while (!s.empty())
    {
        if (s.top() == '(')
        {
            // Unmatched opening parenthesis
            return false;
        }
        postfix += s.top();
        s.pop();
    }
    return true;
}

int main()
{
    string infix, postfix;
    cout << "Enter an infix expression: ";
    cin >> infix;

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

int main()
{
    string postfix;
    stack<int> s;
    cout << "Enter a postfix expression (single-digit operands): ";
    cin >> postfix;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            if (s.size() < 2)
            {
                cout << "Invalid postfix expression! Insufficient operands.\n";
                return 0;
            }
            int b = s.top();
            s.pop();
            int a = s.top();
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
                if (b == 0)
                {
                    cout << "Division by zero error!\n";
                    return 0;
                }
                s.push(a / b);
                break;
            }
        }
        else
        {
            cout << "Invalid character '" << ch << "' in expression!\n";
            return 0;
        }
    }

    if (s.size() != 1)
    {
        cout << "Invalid postfix expression! Extra operands remaining.\n";
        return 0;
    }

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

class Node
{
public:
    int data;
    Node* next;
};

class Stack
{
private:
    Node* top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed into stack.\n";
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow! Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << top->data << " popped from stack.\n";
        top = top->next;
        delete temp;
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

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
            cout << "Invalid choice!\n";
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

#define SIZE 5

class CircularQueue
{
    string requests[SIZE];
    int front, rear, count;

public:
    CircularQueue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(string request)
    {
        if (count == SIZE)
        {
            cout << "Queue is full! Cannot add request.\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        requests[rear] = request;
        count++;
        cout << "Request added: " << request << endl;
    }

    void dequeue()
    {
        if (count == 0)
        {
            cout << "No pending service requests.\n";
            return;
        }
        cout << "Request resolved: " << requests[front] << endl;
        front = (front + 1) % SIZE;
        count--;
    }

    void display()
    {
        if (count == 0)
        {
            cout << "No pending requests.\n";
            return;
        }
        cout << "\nPending Service Requests:\n";
        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % SIZE;
            cout << requests[index] << endl;
        }
    }
};

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

#define SIZE 5

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

class Deque
{
    string customers[SIZE];
    int front, rear, count;

public:
    Deque()
    {
        front = -1;
        rear = -1;
        count = 0;
    }

    bool isFull() { return count == SIZE; }
    bool isEmpty() { return count == 0; }

    void insertRear(string name)
    {
        if (isFull())
        {
            cout << "Queue is full!\n";
            return;
        }
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;
        customers[rear] = name;
        count++;
        cout << name << " added successfully.\n";
    }

    void insertFront(string name)
    {
        if (isFull())
        {
            cout << "Queue is full!\n";
            return;
        }
        if (isEmpty())
            front = rear = 0;
        else
            front = (front - 1 + SIZE) % SIZE;
        customers[front] = name;
        count++;
        cout << name << " added successfully.\n";
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "No customers in the queue!\n";
            return;
        }
        cout << "Customer served: " << customers[front] << endl;
        if (front == rear)
        {
            front = rear = -1;
            count = 0;
        }
        else
        {
            front = (front + 1) % SIZE;
            count--;
        }
    }

    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "No customers in the queue!\n";
            return;
        }
        cout << "Customer removed: " << customers[rear] << endl;
        if (front == rear)
        {
            front = rear = -1;
            count = 0;
        }
        else
        {
            rear = (rear - 1 + SIZE) % SIZE;
            count--;
        }
    }

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

int main()
{
    Deque d;
    int type, choice;
    string name;

    cout << "SHOPPING MALL QUEUE MANAGEMENT\n";
    do
    {
        cout << "1. Input-Restricted Deque\n2. Output-Restricted Deque\n";
        type = readInt("Select deque type (only 1 or 2): ");
        if (type != 1 && type != 2)
            cout << "Invalid deque selection! Please enter only 1 or 2.\n";
    } while (type != 1 && type != 2);

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
            cout << "Invalid choice!\n";
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

class Node
{
public:
    int rollNo;
    string name;
    float marks;
    Node* left;
    Node* right;

    Node(int r, string n, float m)
    {
        rollNo = r;
        name = n;
        marks = m;
        left = right = NULL;
    }
};

class StudentBST
{
private:
    void destroyTree(Node* node)
    {
        if (node == NULL)
            return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    Node* root;

    StudentBST()
    {
        root = NULL;
    }

    ~StudentBST()
    {
        destroyTree(root);
        root = NULL;
    }

    Node* insert(Node* node, int roll, string name, float marks)
    {
        if (node == NULL)
            return new Node(roll, name, marks);

        if (roll < node->rollNo)
            node->left = insert(node->left, roll, name, marks);
        else if (roll > node->rollNo)
            node->right = insert(node->right, roll, name, marks);
        else
            cout << "Duplicate Roll Number not allowed!\n";

        return node;
    }

    void findMin(Node* node)
    {
        if (node == NULL)
        {
            cout << "Tree is empty.\n";
            return;
        }
        while (node->left != NULL)
            node = node->left;
        cout << "Smallest Roll No -> Roll: " << node->rollNo
             << ", Name: " << node->name << ", Marks: " << node->marks << endl;
    }

    void findMax(Node* node)
    {
        if (node == NULL)
        {
            cout << "Tree is empty.\n";
            return;
        }
        while (node->right != NULL)
            node = node->right;
        cout << "Largest Roll No -> Roll: " << node->rollNo
             << ", Name: " << node->name << ", Marks: " << node->marks << endl;
    }

    void search(Node* node, int key)
    {
        if (node == NULL)
        {
            cout << "Student with Roll No " << key << " not found.\n";
            return;
        }
        if (node->rollNo == key)
        {
            cout << "Student Found! Roll: " << node->rollNo
                 << ", Name: " << node->name << ", Marks: " << node->marks << endl;
            return;
        }
        if (key < node->rollNo)
            search(node->left, key);
        else
            search(node->right, key);
    }

    void inorder(Node* node)
    {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->rollNo << " (" << node->name << ")  ";
        inorder(node->right);
    }

    void preorder(Node* node)
    {
        if (node == NULL)
            return;
        cout << node->rollNo << " (" << node->name << ")  ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node)
    {
        if (node == NULL)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->rollNo << " (" << node->name << ")  ";
    }
};

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
            cout << "\nInorder   : ";
            bst.inorder(bst.root);
            cout << "\nPreorder  : ";
            bst.preorder(bst.root);
            cout << "\nPostorder : ";
            bst.postorder(bst.root);
            cout << endl;
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice!\n";
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

#define MAX 20

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

class DeliveryGraph
{
    int vertices;
    string locations[MAX];
    int adj[MAX][MAX];

public:
    DeliveryGraph(int v)
    {
        vertices = v;
        for (int i = 0; i < vertices; i++)
            for (int j = 0; j < vertices; j++)
                adj[i][j] = 0;
    }

    bool isValidVertex(int idx)
    {
        return (idx >= 0 && idx < vertices);
    }

    void setLocationName(int index, string name)
    {
        if (isValidVertex(index))
            locations[index] = name;
    }

    // Returns: 1 = added, 0 = invalid vertex/self-loop, -1 = duplicate road
    int addRoute(int u, int v)
    {
        if (!isValidVertex(u) || !isValidVertex(v) || u == v)
            return 0;
        if (adj[u][v] == 1)
            return -1;
        adj[u][v] = 1;
        adj[v][u] = 1;
        return 1;
    }

    void shortestRouteBFS(int start, int dest)
    {
        if (!isValidVertex(start) || !isValidVertex(dest))
        {
            cout << "Invalid location index! Must be between 0 and " << vertices - 1 << ".\n";
            return;
        }

        bool visited[MAX] = {false};
        int parent[MAX];
        for (int i = 0; i < vertices; i++)
            parent[i] = -1;

        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            if (curr == dest)
                break;

            for (int i = 0; i < vertices; i++)
            {
                if (adj[curr][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    parent[i] = curr;
                    q.push(i);
                }
            }
        }

        if (!visited[dest])
        {
            cout << "No route available between " << locations[start]
                 << " and " << locations[dest] << ".\n";
            return;
        }

        int path[MAX], pathLen = 0;
        for (int v = dest; v != -1; v = parent[v])
            path[pathLen++] = v;

        cout << "\nShortest Delivery Route (BFS): ";
        for (int i = pathLen - 1; i >= 0; i--)
        {
            cout << locations[path[i]];
            if (i > 0)
                cout << " -> ";
        }
        cout << "\nTotal Hops: " << pathLen - 1 << endl;
    }

    void exploreAllRoutesDFS(int curr, int dest, bool visited[], int path[], int pathIndex, bool& routeFound)
    {
        visited[curr] = true;
        path[pathIndex] = curr;
        pathIndex++;

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
            for (int i = 0; i < vertices; i++)
            {
                if (adj[curr][i] == 1 && !visited[i])
                    exploreAllRoutesDFS(i, dest, visited, path, pathIndex, routeFound);
            }
        }

        visited[curr] = false;
    }

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

int main()
{
    int v, e, u, w, choice, start, dest;
    string name;

    cout << "===== DELIVERY ROUTE GRAPH SYSTEM =====\n";
    do
    {
        v = readInt("Enter number of delivery locations (1 to 20): ");
        if (v < 1 || v > MAX)
            cout << "Invalid count! Must be between 1 and " << MAX << ".\n";
    } while (v < 1 || v > MAX);

    DeliveryGraph g(v);
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

    int maxEdges = (v * (v - 1)) / 2;
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
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
```
