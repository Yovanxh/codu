/*
Problem Statement 4B:
Design and develop a program to implement real-life applications of a Doubly Linked List
by enabling operations such as insertion, updating, searching, sorting, listing, and deletion.
Application: Music Playlist Manager
*/

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int songID;
    string title;
    Node* prev;
    Node* next;
};

class DoublyLinkedList
{
private:
    Node* head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void insertSong(int id, string title)
    {
        Node* newNode = new Node();
        newNode->songID = id;
        newNode->title = title;
        newNode->prev = NULL;
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
            newNode->prev = temp;
        }
        cout << "Song added to playlist.\n";
    }

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

    void sortPlaylist()
    {
        if (head == NULL || head->next == NULL)
            return;

        for (Node* i = head; i->next != NULL; i = i->next)
        {
            for (Node* j = i->next; j != NULL; j = j->next)
            {
                if (i->songID > j->songID)
                {
                    swap(i->songID, j->songID);
                    swap(i->title, j->title);
                }
            }
        }
        cout << "Playlist sorted by Song ID.\n";
    }

    void deleteSong(int id)
    {
        Node* temp = head;
        while (temp != NULL && temp->songID != id)
            temp = temp->next;

        if (temp == NULL)
        {
            cout << "Song not found.\n";
            return;
        }

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
        cout << "Song removed from playlist.\n";
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "\nID\tSong Title\n";
        while (temp != NULL)
        {
            cout << temp->songID << "\t" << temp->title << endl;
            temp = temp->next;
        }
    }
};

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
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
