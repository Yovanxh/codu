/*
Problem Statement 4B:
Design and develop a program to implement real-life applications of a Doubly Linked List
by enabling operations such as insertion, updating, searching, sorting, listing, and deletion.
Application: Music Playlist Manager
*/

#include <iostream>
#include <string>
using namespace std;

// ==========================================
// NODE CLASS: Doubly Linked Node
// ==========================================
class Node
{
public:
    int songID;      // Unique Song Identifier
    string title;    // Song Title
    Node* prev;      // Pointer to the previous node
    Node* next;      // Pointer to the next node
};

// ==========================================
// DOUBLY LINKED LIST CLASS (Playlist)
// ==========================================
class DoublyLinkedList
{
private:
    Node* head; // Points to the first song in the playlist

    // Helper: Verify if a song ID already exists in the playlist
    bool exists(int id)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->songID == id)
                return true;
            temp = temp->next;
        }
        return false;
    }

public:
    // Constructor
    DoublyLinkedList()
    {
        head = NULL;
    }

    // Destructor: Clean up all dynamically allocated playlist nodes
    ~DoublyLinkedList()
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
    // OPERATION 1: INSERT SONG AT END
    // ------------------------------------------
    void insertSong(int id, string title)
    {
        if (exists(id))
        {
            cout << "Duplicate Song ID! Song already exists in playlist.\n";
            return;
        }

        // Allocate and initialize new doubly linked node
        Node* newNode = new Node();
        newNode->songID = id;
        newNode->title = title;
        newNode->prev = NULL;
        newNode->next = NULL;

        // If list is empty, new node becomes head
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            // Traverse to the end of the list
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            // Link previous last node and new node bidirectionally
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Song added to playlist.\n";
    }

    // ------------------------------------------
    // OPERATION 2: UPDATE SONG TITLE
    // ------------------------------------------
    void updateSong(int id)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->songID == id)
            {
                cout << "Enter New Song Title: ";
                cin >> ws;
                getline(cin, temp->title);
                cout << "Song updated successfully.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Song not found.\n";
    }

    // ------------------------------------------
    // OPERATION 3: SEARCH SONG BY ID
    // ------------------------------------------
    void searchSong(int id)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->songID == id)
            {
                cout << "Song Found! ID: " << temp->songID << ", Title: " << temp->title << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Song not found.\n";
    }

    // ------------------------------------------
    // OPERATION 4: SORT PLAYLIST BY SONG ID
    // ------------------------------------------
    void sortPlaylist()
    {
        if (head == NULL || head->next == NULL)
            return;

        // Bubble sort by swapping data fields
        for (Node* i = head; i->next != NULL; i = i->next)
        {
            for (Node* j = i->next; j != NULL; j = j->next)
            {
                if (i->songID > j->songID)
                {
                    // Swap Song ID
                    int tempID = i->songID;
                    i->songID = j->songID;
                    j->songID = tempID;

                    // Swap Song Title
                    string tempTitle = i->title;
                    i->title = j->title;
                    j->title = tempTitle;
                }
            }
        }
        cout << "Playlist sorted by Song ID.\n";
    }

    // ------------------------------------------
    // OPERATION 5: DELETE SONG BY ID
    // ------------------------------------------
    void deleteSong(int id)
    {
        Node* temp = head;

        // Search for the node to delete
        while (temp != NULL && temp->songID != id)
            temp = temp->next;

        // If not found
        if (temp == NULL)
        {
            cout << "Song not found.\n";
            return;
        }

        // Adjust previous node's next pointer
        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next; // Deleting the head node

        // Adjust next node's prev pointer
        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp; // Free memory
        cout << "Song removed from playlist.\n";
    }

    // ------------------------------------------
    // OPERATION 6: DISPLAY PLAYLIST
    // ------------------------------------------
    void display()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "\nID\tSong Title\n";
        cout << "------------------------------------\n";
        while (temp != NULL)
        {
            cout << temp->songID << "\t" << temp->title << endl;
            temp = temp->next;
        }
    }
};

// ==========================================
// MAIN FUNCTION (Interactive Menu)
// ==========================================
int main()
{
    DoublyLinkedList playlist;
    int choice, id;
    string title;

    do
    {
        cout << "\n===== PLAYLIST MENU (DOUBLY LINKED LIST) =====\n";
        cout << "1. Insert Song\n2. Update Song\n3. Search Song\n4. Sort Playlist\n5. Display Playlist\n6. Delete Song\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Song ID: ";
            cin >> id;
            cout << "Enter Song Title: ";
            cin >> ws;
            getline(cin, title);
            playlist.insertSong(id, title);
            break;
        case 2:
            cout << "Enter Song ID to update: ";
            cin >> id;
            playlist.updateSong(id);
            break;
        case 3:
            cout << "Enter Song ID to search: ";
            cin >> id;
            playlist.searchSong(id);
            break;
        case 4:
            playlist.sortPlaylist();
            break;
        case 5:
            playlist.display();
            break;
        case 6:
            cout << "Enter Song ID to delete: ";
            cin >> id;
            playlist.deleteSong(id);
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
