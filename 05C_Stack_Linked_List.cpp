/*
Problem Statement 5C:
Implement a program for Stack using Linked List.
*/

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
