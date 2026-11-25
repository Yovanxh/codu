/*
Problem Statement 7:
Design and implement a program for double ended queue and its operations for a shopping mall under given Scenarios :-
a) Input Restricted Deque
b) Output Restricted Deque.
Application: Shopping Mall Queue Management
*/

#include <iostream>
#include <string>
using namespace std;

#define SIZE 5

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
    cout << "1. Input-Restricted Deque\n2. Output-Restricted Deque\n";
    cout << "Select deque type: ";
    cin >> type;

    do
    {
        cout << "\n1. Insert at Rear\n2. Insert at Front\n3. Delete from Front\n4. Delete from Rear\n5. Display Queue\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

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
                cout << "Insertion allowed only at rear!\n";
            break;
        case 3:
            d.deleteFront();
            break;
        case 4:
            if (type == 1)
                d.deleteRear();
            else
                cout << "Deletion allowed only from front!\n";
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
