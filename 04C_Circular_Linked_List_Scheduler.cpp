/*
Problem Statement 4C:
Design and develop a program to implement real-life applications of a Circular Linked List
by enabling operations such as insertion, updating, searching, sorting, listing, and deletion.
Application: Round-Robin Task Scheduler
*/

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

public:
    CircularLinkedList()
    {
        head = NULL;
    }

    void insertTask(int id, string name)
    {
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
                    swap(i->taskID, j->taskID);
                    swap(i->taskName, j->taskName);
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
