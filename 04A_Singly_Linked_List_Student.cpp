/*
Problem Statement 4A:
Design and develop a program to implement real-life applications of a Singly Linked List
by enabling operations such as insertion, updating, searching, sorting, listing, and deletion.
Application: Student Record Management System
*/

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
