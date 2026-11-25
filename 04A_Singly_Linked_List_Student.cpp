/*
Problem Statement 4A:
Design and develop a program to implement real-life applications of a Singly Linked List
by enabling operations such as insertion, updating, searching, sorting, listing, and deletion.
Application: Student Record Management System
Fixes: Blocks duplicate Roll Numbers on insertion and adds a ~SinglyLinkedList() destructor to free memory.
*/

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
