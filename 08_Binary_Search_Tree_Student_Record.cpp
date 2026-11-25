/*
Problem Statement 8A & 8B:
A software company is developing a student record management system for a university.
The system needs to efficiently store and retrieve student records based on their unique roll numbers using a Binary Search Tree (BST).
The university requires the following operations:
8A:
- Finding the student with the smallest roll number (minimum key).
- Finding the student with the largest roll number (maximum key).
- Searching for a student using a given roll number.
8B:
- BST Display: Inorder, Preorder, and Postorder traversals.
Application: Student Record Management System (BST)
Fixes: Adds destroyTree() + ~StudentBST() destructor for full memory cleanup and handles empty tree traversal gracefully.
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
    Node* left;
    Node* right;

    Node(int r, string n, float m)
    {
        rollNo = r;
        name = n;
        marks = m;
        left = right = NULL;
    }
};

class StudentBST
{
private:
    void destroyTree(Node* node)
    {
        if (node == NULL)
            return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    Node* root;

    StudentBST()
    {
        root = NULL;
    }

    ~StudentBST()
    {
        destroyTree(root);
        root = NULL;
    }

    Node* insert(Node* node, int roll, string name, float marks)
    {
        if (node == NULL)
            return new Node(roll, name, marks);

        if (roll < node->rollNo)
            node->left = insert(node->left, roll, name, marks);
        else if (roll > node->rollNo)
            node->right = insert(node->right, roll, name, marks);
        else
            cout << "Duplicate Roll Number not allowed!\n";

        return node;
    }

    void findMin(Node* node)
    {
        if (node == NULL)
        {
            cout << "Tree is empty.\n";
            return;
        }
        while (node->left != NULL)
            node = node->left;
        cout << "Smallest Roll No -> Roll: " << node->rollNo
             << ", Name: " << node->name << ", Marks: " << node->marks << endl;
    }

    void findMax(Node* node)
    {
        if (node == NULL)
        {
            cout << "Tree is empty.\n";
            return;
        }
        while (node->right != NULL)
            node = node->right;
        cout << "Largest Roll No -> Roll: " << node->rollNo
             << ", Name: " << node->name << ", Marks: " << node->marks << endl;
    }

    void search(Node* node, int key)
    {
        if (node == NULL)
        {
            cout << "Student with Roll No " << key << " not found.\n";
            return;
        }
        if (node->rollNo == key)
        {
            cout << "Student Found! Roll: " << node->rollNo
                 << ", Name: " << node->name << ", Marks: " << node->marks << endl;
            return;
        }
        if (key < node->rollNo)
            search(node->left, key);
        else
            search(node->right, key);
    }

    void inorder(Node* node)
    {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->rollNo << " (" << node->name << ")  ";
        inorder(node->right);
    }

    void preorder(Node* node)
    {
        if (node == NULL)
            return;
        cout << node->rollNo << " (" << node->name << ")  ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node)
    {
        if (node == NULL)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->rollNo << " (" << node->name << ")  ";
    }
};

int main()
{
    StudentBST bst;
    int choice, roll;
    string name;
    float marks;

    do
    {
        cout << "\n===== STUDENT BST MANAGEMENT =====\n";
        cout << "1. Insert Student Record\n";
        cout << "2. Find Smallest Roll Number (Min)\n";
        cout << "3. Find Largest Roll Number (Max)\n";
        cout << "4. Search Student by Roll Number\n";
        cout << "5. Display Traversals (Inorder / Preorder / Postorder)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Roll Number: ";
            cin >> roll;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Marks: ";
            cin >> marks;
            bst.root = bst.insert(bst.root, roll, name, marks);
            break;
        case 2:
            bst.findMin(bst.root);
            break;
        case 3:
            bst.findMax(bst.root);
            break;
        case 4:
            cout << "Enter Roll Number to search: ";
            cin >> roll;
            bst.search(bst.root, roll);
            break;
        case 5:
            if (bst.root == NULL)
            {
                cout << "Tree is empty.\n";
                break;
            }
            cout << "\nInorder   : ";
            bst.inorder(bst.root);
            cout << "\nPreorder  : ";
            bst.preorder(bst.root);
            cout << "\nPostorder : ";
            bst.postorder(bst.root);
            cout << endl;
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
