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

// ==========================================
// BST NODE CLASS
// ==========================================
class Node
{
public:
    int rollNo;     // Key: Unique student roll number
    string name;    // Student name
    float marks;    // Student marks
    Node* left;     // Pointer to the left child (holds keys < rollNo)
    Node* right;    // Pointer to the right child (holds keys > rollNo)

    // Node Constructor
    Node(int r, string n, float m)
    {
        rollNo = r;
        name = n;
        marks = m;
        left = right = NULL;
    }
};

// ==========================================
// BINARY SEARCH TREE (BST) CLASS
// ==========================================
class StudentBST
{
private:
    // Helper: Recursively deletes all nodes in postorder to prevent memory leaks
    void destroyTree(Node* node)
    {
        if (node == NULL)
            return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    Node* root; // Root pointer of the Binary Search Tree

    // Constructor: Initializes empty tree
    StudentBST()
    {
        root = NULL;
    }

    // Destructor: Automatically frees tree memory
    ~StudentBST()
    {
        destroyTree(root);
        root = NULL;
    }

    // ------------------------------------------
    // OPERATION 1: INSERT RECORD INTO BST
    // ------------------------------------------
    Node* insert(Node* node, int roll, string name, float marks)
    {
        // Base case: Found insertion point
        if (node == NULL)
            return new Node(roll, name, marks);

        // If new key is smaller, insert into left subtree
        if (roll < node->rollNo)
            node->left = insert(node->left, roll, name, marks);
        // If new key is greater, insert into right subtree
        else if (roll > node->rollNo)
            node->right = insert(node->right, roll, name, marks);
        // Duplicate key rejection
        else
            cout << "Duplicate Roll Number not allowed!\n";

        return node;
    }

    // ------------------------------------------
    // OPERATION 8A: FIND MINIMUM ROLL NUMBER
    // ------------------------------------------
    // In a BST, the leftmost node always contains the minimum key
    void findMin(Node* node)
    {
        if (node == NULL)
        {
            cout << "Tree is empty.\n";
            return;
        }
        // Traverse as far left as possible
        while (node->left != NULL)
            node = node->left;

        cout << "Smallest Roll No -> Roll: " << node->rollNo
             << ", Name: " << node->name << ", Marks: " << node->marks << endl;
    }

    // ------------------------------------------
    // OPERATION 8A: FIND MAXIMUM ROLL NUMBER
    // ------------------------------------------
    // In a BST, the rightmost node always contains the maximum key
    void findMax(Node* node)
    {
        if (node == NULL)
        {
            cout << "Tree is empty.\n";
            return;
        }
        // Traverse as far right as possible
        while (node->right != NULL)
            node = node->right;

        cout << "Largest Roll No -> Roll: " << node->rollNo
             << ", Name: " << node->name << ", Marks: " << node->marks << endl;
    }

    // ------------------------------------------
    // OPERATION 8A: SEARCH BY ROLL NUMBER
    // ------------------------------------------
    void search(Node* node, int key)
    {
        if (node == NULL)
        {
            cout << "Student with Roll No " << key << " not found.\n";
            return;
        }

        // Key matched
        if (node->rollNo == key)
        {
            cout << "Student Found! Roll: " << node->rollNo
                 << ", Name: " << node->name << ", Marks: " << node->marks << endl;
            return;
        }

        // If key is smaller, search left subtree; otherwise search right subtree
        if (key < node->rollNo)
            search(node->left, key);
        else
            search(node->right, key);
    }

    // ------------------------------------------
    // OPERATION 8B: INORDER TRAVERSAL (Left, Root, Right)
    // Produces sorted ascending order of keys
    // ------------------------------------------
    void inorder(Node* node)
    {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->rollNo << " (" << node->name << ")  ";
        inorder(node->right);
    }

    // ------------------------------------------
    // OPERATION 8B: PREORDER TRAVERSAL (Root, Left, Right)
    // Useful for copying/serializing the tree structure
    // ------------------------------------------
    void preorder(Node* node)
    {
        if (node == NULL)
            return;
        cout << node->rollNo << " (" << node->name << ")  ";
        preorder(node->left);
        preorder(node->right);
    }

    // ------------------------------------------
    // OPERATION 8B: POSTORDER TRAVERSAL (Left, Right, Root)
    // Useful for bottom-up cleanup/deletion
    // ------------------------------------------
    void postorder(Node* node)
    {
        if (node == NULL)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->rollNo << " (" << node->name << ")  ";
    }
};

// ==========================================
// MAIN FUNCTION (Interactive Menu)
// ==========================================
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
            cout << "\nInorder   (Left-Root-Right): ";
            bst.inorder(bst.root);
            cout << "\nPreorder  (Root-Left-Right): ";
            bst.preorder(bst.root);
            cout << "\nPostorder (Left-Right-Root): ";
            bst.postorder(bst.root);
            cout << endl;
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please select 1-6.\n";
        }
    } while (choice != 6);

    return 0;
}
