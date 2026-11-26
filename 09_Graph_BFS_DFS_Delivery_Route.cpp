/*
Problem Statement 9A & 9B:
Design and implement a Graph Traversal System to help a delivery company:
9A: Find the shortest route to a delivery location using BFS.
9B: Explore all possible routes for better traffic management using DFS.
Application: Delivery Route Graph System (BFS & DFS)
Fixes: Added readInt() for robust numeric input handling, validated maxEdges, self-loops, duplicate roads, distinct indices, and empty names.
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define MAX 20 // Maximum supported delivery locations (vertices)

// ==========================================
// HELPER: ROBUST INTEGER INPUT READER
// ==========================================
// Prevents terminal lockup / infinite loops when non-numeric inputs are entered
int readInt(const string& prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
            return value;
        cout << "Invalid numeric input! Please enter a valid integer.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

// ==========================================
// DELIVERY GRAPH CLASS (Adjacency Matrix)
// ==========================================
class DeliveryGraph
{
    int vertices;           // Number of locations
    string locations[MAX];  // Names of delivery locations
    int adj[MAX][MAX];      // Adjacency Matrix: adj[u][v] = 1 if road exists between u and v

public:
    // Constructor: Initialize matrix to all zeros (no edges)
    DeliveryGraph(int v)
    {
        vertices = v;
        for (int i = 0; i < vertices; i++)
            for (int j = 0; j < vertices; j++)
                adj[i][j] = 0;
    }

    // Helper: Validates whether vertex index is within bounds [0, vertices-1]
    bool isValidVertex(int idx)
    {
        return (idx >= 0 && idx < vertices);
    }

    // Assign a human-readable location name to a vertex index
    void setLocationName(int index, string name)
    {
        if (isValidVertex(index))
            locations[index] = name;
    }

    // Add an undirected road between location u and location v
    // Returns: 1 = added, 0 = invalid vertex/self-loop, -1 = duplicate road
    int addRoute(int u, int v)
    {
        if (!isValidVertex(u) || !isValidVertex(v) || u == v)
            return 0; // Invalid indices or self-loop
        if (adj[u][v] == 1)
            return -1; // Road connection already present

        // Graph is undirected: road works both ways
        adj[u][v] = 1;
        adj[v][u] = 1;
        return 1;
    }

    // ------------------------------------------
    // OPERATION 9A: SHORTEST DELIVERY ROUTE USING BFS
    // ------------------------------------------
    // Breadth-First Search (BFS) explores level-by-level using a queue,
    // guaranteeing the shortest path in terms of number of hops (edges).
    void shortestRouteBFS(int start, int dest)
    {
        if (!isValidVertex(start) || !isValidVertex(dest))
        {
            cout << "Invalid location index! Must be between 0 and " << vertices - 1 << ".\n";
            return;
        }

        bool visited[MAX] = {false}; // Tracks visited locations
        int parent[MAX];             // Tracks predecessor node to reconstruct path
        for (int i = 0; i < vertices; i++)
            parent[i] = -1;

        queue<int> q;                // BFS queue

        // Enqueue start location and mark visited
        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            // Destination reached: stop early
            if (curr == dest)
                break;

            // Check all neighboring vertices
            for (int i = 0; i < vertices; i++)
            {
                if (adj[curr][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    parent[i] = curr; // Record predecessor
                    q.push(i);
                }
            }
        }

        // If destination was never reached
        if (!visited[dest])
        {
            cout << "No route available between " << locations[start]
                 << " and " << locations[dest] << ".\n";
            return;
        }

        // Reconstruct path backwards from dest to start via parent pointers
        int path[MAX], pathLen = 0;
        for (int v = dest; v != -1; v = parent[v])
            path[pathLen++] = v;

        // Display shortest path in forward order
        cout << "\nShortest Delivery Route (BFS): ";
        for (int i = pathLen - 1; i >= 0; i--)
        {
            cout << locations[path[i]];
            if (i > 0)
                cout << " -> ";
        }
        cout << "\nTotal Hops: " << pathLen - 1 << endl;
    }

    // ------------------------------------------
    // OPERATION 9B: EXPLORE ALL ROUTES USING DFS
    // ------------------------------------------
    // Depth-First Search with backtracking to discover every possible path
    void exploreAllRoutesDFS(int curr, int dest, bool visited[], int path[], int pathIndex, bool& routeFound)
    {
        visited[curr] = true;      // Mark current location in active path
        path[pathIndex] = curr;    // Add current vertex to path history
        pathIndex++;

        // If target reached, print the current full route
        if (curr == dest)
        {
            routeFound = true;
            for (int i = 0; i < pathIndex; i++)
            {
                cout << locations[path[i]];
                if (i < pathIndex - 1)
                    cout << " -> ";
            }
            cout << endl;
        }
        else
        {
            // Recur for all adjacent unvisited vertices
            for (int i = 0; i < vertices; i++)
            {
                if (adj[curr][i] == 1 && !visited[i])
                    exploreAllRoutesDFS(i, dest, visited, path, pathIndex, routeFound);
            }
        }

        // Backtrack: Unmark current vertex so other paths can traverse through it
        visited[curr] = false;
    }

    // Wrapper function for DFS all routes
    void findAllRoutes(int start, int dest)
    {
        if (!isValidVertex(start) || !isValidVertex(dest))
        {
            cout << "Invalid location index! Must be between 0 and " << vertices - 1 << ".\n";
            return;
        }

        bool visited[MAX] = {false};
        int path[MAX];
        bool routeFound = false;

        cout << "\nAll Possible Routes (DFS) from " << locations[start]
             << " to " << locations[dest] << ":\n";
        exploreAllRoutesDFS(start, dest, visited, path, 0, routeFound);

        if (!routeFound)
            cout << "No route available between " << locations[start]
                 << " and " << locations[dest] << ".\n";
    }
};

// ==========================================
// MAIN FUNCTION (Interactive Menu)
// ==========================================
int main()
{
    int v, e, u, w, choice, start, dest;
    string name;

    cout << "===== DELIVERY ROUTE GRAPH SYSTEM =====\n";

    // ------------------------------------------
    // INPUT NUMBER OF LOCATIONS (VERTICES)
    // ------------------------------------------
    do
    {
        v = readInt("Enter number of delivery locations (1 to 20): ");
        if (v < 1 || v > MAX)
            cout << "Invalid count! Must be between 1 and " << MAX << ".\n";
    } while (v < 1 || v > MAX);

    DeliveryGraph g(v);

    // Input names for each delivery location
    for (int i = 0; i < v; i++)
    {
        do
        {
            cout << "Enter name for Location " << i << ": ";
            cin >> ws;
            getline(cin, name);
            if (name.empty())
                cout << "Location name cannot be empty!\n";
        } while (name.empty());
        g.setLocationName(i, name);
    }

    // ------------------------------------------
    // INPUT ROAD CONNECTIONS (EDGES)
    // ------------------------------------------
    int maxEdges = (v * (v - 1)) / 2; // Maximum edges in an undirected graph
    do
    {
        e = readInt("Enter number of road connections (0 to " + to_string(maxEdges) + "): ");
        if (e < 0 || e > maxEdges)
            cout << "Invalid count! Must be between 0 and " << maxEdges << ".\n";
    } while (e < 0 || e > maxEdges);

    cout << "Enter connected location indices (0 to " << v - 1 << "):\n";
    for (int i = 0; i < e; i++)
    {
        cout << "Connection " << i + 1 << " (u v): ";
        if (!(cin >> u >> w))
        {
            cout << "Invalid numeric input! Re-enter connection " << i + 1 << ".\n";
            cin.clear();
            cin.ignore(10000, '\n');
            i--;
            continue;
        }

        int status = g.addRoute(u, w);
        if (status == 0)
        {
            cout << "Invalid connection! Indices must be distinct and between 0 and " << v - 1 << ".\n";
            i--;
        }
        else if (status == -1)
        {
            cout << "Duplicate road! Connection already exists. Enter a different road.\n";
            i--;
        }
    }

    // ------------------------------------------
    // ROUTE NAVIGATION MENU
    // ------------------------------------------
    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Find Shortest Route (BFS - 9A)\n";
        cout << "2. Explore All Possible Routes (DFS - 9B)\n";
        cout << "3. Exit\n";
        choice = readInt("Enter your choice: ");

        switch (choice)
        {
        case 1:
            start = readInt("Enter Start Location index: ");
            dest = readInt("Enter Destination index: ");
            g.shortestRouteBFS(start, dest);
            break;
        case 2:
            start = readInt("Enter Start Location index: ");
            dest = readInt("Enter Destination index: ");
            g.findAllRoutes(start, dest);
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please select 1-3.\n";
        }
    } while (choice != 3);

    return 0;
}
