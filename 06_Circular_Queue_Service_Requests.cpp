/*
Problem Statement 6:
Implement a Circular Queue-based system to manage real-life service requests,
ensuring efficient customer handling using the FIFO approach,
where resolved requests free up slots for new entries without data shifting.
Application: Service Request Management
*/

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
