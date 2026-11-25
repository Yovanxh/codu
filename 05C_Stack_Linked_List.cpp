/*
Problem Statement 5C:
Implement a program for Stack using Linked List.
*/

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
