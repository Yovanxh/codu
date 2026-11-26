/*
Problem Statement 7:
Design and implement a program for double ended queue and its operations for a shopping mall under given Scenarios :-
a) Input Restricted Deque
b) Output Restricted Deque.
Application: Shopping Mall Queue Management
Fixes: Added readInt() for robust input validation, preventing infinite loops on non-numeric input.
*/

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
