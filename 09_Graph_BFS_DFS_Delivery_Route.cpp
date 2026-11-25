/*
Problem Statement 9A & 9B:
Design and implement a Graph Traversal System to help a delivery company:
9A: Find the shortest route to a delivery location using BFS.
9B: Explore all possible routes for better traffic management using DFS.
Application: Delivery Route Graph System (BFS & DFS)
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define MAX 20

class DeliveryGraph
{
    int vertices;
    string locations[MAX];
    int adj[MAX][MAX];

public:
    DeliveryGraph(int v)
    {
        vertices = v;
        for (int i = 0; i < vertices; i++)
            for (int j = 0; j < vertices; j++)
                adj[i][j] = 0;
    }

    void setLocationName(int index, string name)
    {
        locations[index] = name;
    }

    void addRoute(int u, int v)
    {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // 9A: Shortest route using BFS
    void shortestRouteBFS(int start, int dest)
    {
        bool visited[MAX] = {false};
        int parent[MAX];
        for (int i = 0; i < vertices; i++)
            parent[i] = -1;

        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            if (curr == dest)
                break;

            for (int i = 0; i < vertices; i++)
            {
                if (adj[curr][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    parent[i] = curr;
                    q.push(i);
                }
            }
        }

        if (!visited[dest])
        {
            cout << "No route available between " << locations[start]
                 << " and " << locations[dest] << ".\n";
            return;
        }

        int path[MAX], pathLen = 0;
        for (int v = dest; v != -1; v = parent[v])
            path[pathLen++] = v;

        cout << "\nShortest Delivery Route (BFS): ";
        for (int i = pathLen - 1; i >= 0; i--)
        {
            cout << locations[path[i]];
            if (i > 0)
                cout << " -> ";
        }
        cout << "\nTotal Hops: " << pathLen - 1 << endl;
    }

    // 9B: Explore all possible routes using DFS
    void exploreAllRoutesDFS(int curr, int dest, bool visited[], int path[], int pathIndex)
    {
        visited[curr] = true;
        path[pathIndex] = curr;
        pathIndex++;

        if (curr == dest)
        {
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
            for (int i = 0; i < vertices; i++)
            {
                if (adj[curr][i] == 1 && !visited[i])
                    exploreAllRoutesDFS(i, dest, visited, path, pathIndex);
            }
        }

        visited[curr] = false;
    }

    void findAllRoutes(int start, int dest)
    {
        bool visited[MAX] = {false};
        int path[MAX];
        cout << "\nAll Possible Routes (DFS) from " << locations[start]
             << " to " << locations[dest] << ":\n";
        exploreAllRoutesDFS(start, dest, visited, path, 0);
    }
};

int main()
{
    int v, e, u, w, choice, start, dest;
    string name;

    cout << "===== DELIVERY ROUTE GRAPH SYSTEM =====\n";
    cout << "Enter number of delivery locations: ";
    cin >> v;

    DeliveryGraph g(v);
    for (int i = 0; i < v; i++)
    {
        cout << "Enter name for Location " << i << ": ";
        cin >> name;
        g.setLocationName(i, name);
    }

    cout << "Enter number of road connections: ";
    cin >> e;
    cout << "Enter connected location indices (u v):\n";
    for (int i = 0; i < e; i++)
    {
        cin >> u >> w;
        g.addRoute(u, w);
    }

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Find Shortest Route (BFS - 9A)\n";
        cout << "2. Explore All Possible Routes (DFS - 9B)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Start Location index and Destination index: ";
            cin >> start >> dest;
            g.shortestRouteBFS(start, dest);
            break;
        case 2:
            cout << "Enter Start Location index and Destination index: ";
            cin >> start >> dest;
            g.findAllRoutes(start, dest);
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
