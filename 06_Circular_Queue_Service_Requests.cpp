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
