/*
Problem Statement 4C:
Design and develop a program to implement real-life applications of a Circular Linked List
by enabling operations such as insertion, updating, searching, sorting, listing, and deletion.
Application: Round-Robin Task Scheduler
*/

#include <iostream>
#include <string>
using namespace std;

// ==========================================
// NODE CLASS: Circular Node
// ==========================================
class Node
{
public:
    int taskID;       // Unique Task Identifier
    string taskName;  // Name of the scheduled task
    Node* next;       // Points to the next node (last node points to head)
};

// ==========================================
// CIRCULAR LINKED LIST CLASS (Task Scheduler)
// ==========================================
class CircularLinkedList
{
private:
    Node* head; // Points to the first task

    // Helper: Check if a task ID exists in the circular list
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
    // Constructor
    CircularLinkedList()
    {
        head = NULL;
    }

    // Destructor: Safely delete all nodes in the circular cycle
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

    // ------------------------------------------
    // OPERATION 1: INSERT TASK INTO CIRCULAR QUEUE
    // ------------------------------------------
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

        // If list is empty, point newNode to itself to form a circle
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            // Traverse to the node currently pointing back to head
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;

            // Link last node to new node, and new node to head
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Task inserted into circular queue.\n";
    }

    // ------------------------------------------
    // OPERATION 2: UPDATE TASK DETAILS
    // ------------------------------------------
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

    // ------------------------------------------
    // OPERATION 3: SEARCH TASK BY ID
    // ------------------------------------------
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

    // ------------------------------------------
    // OPERATION 4: SORT TASKS BY TASK ID
    // ------------------------------------------
    void sortTasks()
    {
        if (head == NULL || head->next == head)
            return;

        // Bubble sort on circular list
        Node* i = head;
        do
        {
            Node* j = i->next;
            while (j != head)
            {
                if (i->taskID > j->taskID)
                {
                    // Swap Task ID
                    int tempID = i->taskID;
                    i->taskID = j->taskID;
                    j->taskID = tempID;

                    // Swap Task Name
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

    // ------------------------------------------
    // OPERATION 5: DELETE TASK BY ID
    // ------------------------------------------
    void deleteTask(int id)
    {
        if (head == NULL)
        {
            cout << "Task list is empty.\n";
            return;
        }

        Node *curr = head, *prev = NULL;

        // Traverse circularly looking for the node with taskID == id
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

        // Case 1: Only one node in the entire list
        if (curr == head && curr->next == head)
        {
            head = NULL;
            delete curr;
        }
        // Case 2: Deleting head node with multiple nodes present
        else if (curr == head)
        {
            // Find the last node to update its next pointer
            prev = head;
            while (prev->next != head)
                prev = prev->next;
            head = head->next;    // Advance head
            prev->next = head;    // Update last node's circular link
            delete curr;
        }
        // Case 3: Deleting an intermediate or last node
        else
        {
            prev->next = curr->next;
            delete curr;
        }
        cout << "Task deleted successfully.\n";
    }

    // ------------------------------------------
    // OPERATION 6: DISPLAY ALL SCHEDULED TASKS
    // ------------------------------------------
    void display()
    {
        if (head == NULL)
        {
            cout << "No active tasks.\n";
            return;
        }
        Node* temp = head;
        cout << "\nTaskID\tTaskName\n";
        cout << "------------------------------------\n";
        do
        {
            cout << temp->taskID << "\t" << temp->taskName << endl;
            temp = temp->next;
        } while (temp != head); // Stop when we complete one full circle
    }
};

// ==========================================
// MAIN FUNCTION (Interactive Menu)
// ==========================================
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
            cout << "Invalid choice! Please select 1-7.\n";
        }
    } while (choice != 7);

    return 0;
}
