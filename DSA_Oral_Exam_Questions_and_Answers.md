# Data Structures and Algorithms: Practical Oral / Viva Exam Preparation

**Course Code:** 2312211T | **Class:** S.Y. B.Tech CSE (Data Science) | **Academic Year:** 2025-26  
**Total Questions:** 120 Questions (20 Questions per Unit)

---

## Table of Contents
- [Unit 1: Introduction to Data Structures](#unit-1-introduction-to-data-structures)
- [Unit 2: Searching and Sorting](#unit-2-searching-and-sorting)
- [Unit 3: Linked List](#unit-3-linked-list)
- [Unit 4: Stacks and Queues](#unit-4-stacks-and-queues)
- [Unit 5: Trees](#unit-5-trees)
- [Unit 6: Graphs](#unit-6-graphs)

---

## Unit 1: Introduction to Data Structures

| No. | Question | Answer |
| :---: | :--- | :--- |
| **1** | What is a data structure? | A way of organizing and storing data so it can be accessed and modified efficiently. |
| **2** | Difference between data and information? | Data is raw facts. Information is processed data that has meaning. |
| **3** | What is an ADT? | An Abstract Data Type defines a data model and its operations, without specifying implementation (e.g., Stack, Queue). |
| **4** | Linear vs non-linear data structures? | Linear: elements in sequence (array, linked list, stack, queue). Non-linear: hierarchical or networked (tree, graph). |
| **5** | What is an algorithm? | A finite, step-by-step procedure to solve a problem, with clear input and output. |
| **6** | What is time complexity? | The amount of time an algorithm takes as a function of input size $n$. |
| **7** | What is space complexity? | The amount of memory an algorithm needs as a function of input size $n$. |
| **8** | What is Big O notation? | An asymptotic upper bound on growth rate (worst-case behavior). |
| **9** | What is Omega ($\Omega$) notation? | An asymptotic lower bound (best-case behavior). |
| **10** | What is Theta ($\Theta$) notation? | A tight bound: the algorithm is bounded both above and below by the same function. |
| **11** | Time complexity of a single loop running $n$ times? | $O(n)$. |
| **12** | Time complexity of two nested loops, each running $n$ times? | $O(n^2)$. |
| **13** | How do you analyze a recursive algorithm? | Write a recurrence relation (e.g., $T(n) = T(n-1) + 1$) and solve it. Space includes the call stack. |
| **14** | Time complexity of binary search? | $O(\log n)$. |
| **15** | What is hashing? | Mapping a key to an array index using a hash function for fast access. |
| **16** | What is a hash function? | A function that converts a key into an index in the hash table. |
| **17** | Name some hash functions. | Division method ($k \bmod m$), multiplication method, mid-square, folding. |
| **18** | What is a collision? | Two different keys mapping to the same index. |
| **19** | Collision resolution techniques? | Chaining (separate chaining) and open addressing (linear probing, quadratic probing, double hashing). |
| **20** | Average time complexity of hash table search/insert? | $O(1)$ on average; $O(n)$ in the worst case. |

---

## Unit 2: Searching and Sorting

| No. | Question | Answer |
| :---: | :--- | :--- |
| **1** | How does Fibonacci search work? | It divides the sorted array using Fibonacci numbers instead of midpoints. |
| **2** | Time complexity of Fibonacci search? | $O(\log n)$. |
| **3** | What is a prerequisite for Fibonacci search? | The array must be sorted. |
| **4** | What is Sentinel search? | A linear search variant that places the key at the end of the array, removing the bounds check from each iteration. |
| **5** | Why is Sentinel search faster than plain linear search? | It makes one comparison per iteration instead of two, though it is still $O(n)$. |
| **6** | How does Insertion sort work? | It builds a sorted portion by inserting each element into its correct position. |
| **7** | Complexity of Insertion sort? | Best $O(n)$, average and worst $O(n^2)$, space $O(1)$. |
| **8** | How does Selection sort work? | It repeatedly selects the minimum from the unsorted part and swaps it into place. |
| **9** | Complexity of Selection sort? | $O(n^2)$ in all cases. |
| **10** | Is Selection sort stable? | No (in its usual implementation). |
| **11** | How does Merge sort work? | Divide and conquer: split the array in halves, sort each recursively, then merge. |
| **12** | Complexity of Merge sort? | $O(n \log n)$ in all cases; space $O(n)$. |
| **13** | How does Quick sort work? | It picks a pivot, partitions elements into smaller and larger groups, and recursively sorts both parts. |
| **14** | Quick sort best, average, and worst case? | Best and average $O(n \log n)$; worst $O(n^2)$, e.g., already sorted data with a bad pivot. |
| **15** | How can you avoid Quick sort's worst case? | Use a random pivot or median-of-three. |
| **16** | What is Radix sort? | A non-comparison sort that sorts numbers digit by digit, from least significant to most significant, using a stable sort such as counting sort. |
| **17** | Complexity of Radix sort? | $O(d \cdot (n + k))$, where $d$ is the number of digits and $k$ is the base. |
| **18** | What is a stable sorting algorithm? | One that preserves the relative order of equal elements. |
| **19** | Which sorts are stable? | Insertion, Merge, Radix, Bubble. (Selection and Quick are typically not.) |
| **20** | What is an in-place sorting algorithm? | One that uses $O(1)$ extra space (e.g., Insertion, Selection, Quick). Merge sort is not in-place. |

---

## Unit 3: Linked List

| No. | Question | Answer |
| :---: | :--- | :--- |
| **1** | What is a linked list? | A linear data structure of nodes, each containing data and a pointer to the next node. |
| **2** | Array vs linked list? | Arrays use contiguous memory with $O(1)$ random access and fixed size. Linked lists use dynamic memory with $O(n)$ access and easy insertion and deletion. |
| **3** | Types of linked lists? | Singly, doubly, and circular (singly or doubly). |
| **4** | What does a node of a singly linked list contain? | A data field and a next pointer. |
| **5** | What does a node of a doubly linked list contain? | Data, a prev pointer, and a next pointer. |
| **6** | What is a circular linked list? | One where the last node points back to the first node instead of NULL. |
| **7** | Time complexity of insertion at the beginning? | $O(1)$. |
| **8** | Time complexity of insertion at the end (singly, with only a head pointer)? | $O(n)$; it is $O(1)$ if a tail pointer is kept. |
| **9** | How do you delete a node in a singly linked list? | Find the previous node, set `prev->next = node->next`, and free the node. |
| **10** | How do you traverse a linked list? | Start at the head and follow next pointers until NULL. |
| **11** | Time complexity of searching in a linked list? | $O(n)$. |
| **12** | How do you reverse a singly linked list? | Use three pointers (`prev`, `curr`, `next`) and reverse each link iteratively. $O(n)$ time, $O(1)$ space. |
| **13** | Which sorting is suitable for linked lists? | Merge sort, because it needs no random access. |
| **14** | How do you detect a cycle in a linked list? | Floyd's algorithm: a slow pointer and a fast pointer meet if there is a cycle. |
| **15** | Advantages of a doubly linked list? | Traversal in both directions and easier deletion of a given node. It costs extra memory for the prev pointer. |
| **16** | Why use a circular linked list? | For round-robin scheduling and applications that cycle repeatedly. |
| **17** | How is a polynomial represented using a linked list? | Each node stores a coefficient, an exponent, and a next pointer. |
| **18** | How do you add two polynomials? | Traverse both lists and add coefficients of terms with equal exponents. Otherwise copy the term with the larger exponent. |
| **19** | How do you multiply two polynomials? | Multiply each term of one by every term of the other, then combine like terms. |
| **20** | What is a skip list? | A linked list with multiple levels of "express lanes" that gives $O(\log n)$ average search. |

---

## Unit 4: Stacks and Queues

| No. | Question | Answer |
| :---: | :--- | :--- |
| **1** | What is a stack? | A linear structure following LIFO (Last In, First Out). |
| **2** | Basic stack operations? | `push`, `pop`, `peek`/`top`, `isEmpty`, `isFull`. |
| **3** | What is stack overflow? | Pushing onto a full stack. |
| **4** | What is stack underflow? | Popping from an empty stack. |
| **5** | How is a stack implemented using a linked list? | Insert and delete at the head, so push and pop are $O(1)$ with no size limit. |
| **6** | Applications of stacks? | Function calls, expression evaluation, parenthesis matching, undo, recursion, DFS. |
| **7** | What are infix, prefix, and postfix? | Operator placement: A+B (infix), +AB (prefix), AB+ (postfix). |
| **8** | Why is postfix preferred for evaluation? | It needs no parentheses or precedence rules; a stack evaluates it in one pass. |
| **9** | How do you evaluate a postfix expression? | Scan left to right; push operands; on an operator, pop two operands, apply it, and push the result. |
| **10** | Postfix of A+B*C? | ABC*+ |
| **11** | How do you check balanced parentheses? | Push opening brackets; on a closing bracket, pop and check that it matches. The stack must be empty at the end. |
| **12** | What is recursion? | A function calling itself with a smaller problem, with a base case to stop. |
| **13** | How is recursion handled in memory? | Through the call stack, with one activation record per call. |
| **14** | What is a queue? | A linear structure following FIFO (First In, First Out). |
| **15** | Basic queue operations? | `enqueue`, `dequeue`, `front`, `rear`, `isEmpty`, `isFull`. |
| **16** | Problem with a linear queue using an array? | Space at the front is not reused after dequeues, even when the queue looks full. |
| **17** | How does a circular queue solve this? | It wraps rear around using modulo: `rear = (rear + 1) % size`. |
| **18** | What is a deque? | A double-ended queue that allows insertion and deletion at both ends. |
| **19** | What is a priority queue? | A queue where each element has a priority and the highest-priority element is served first. Usually implemented with a heap. |
| **20** | Applications of queues? | CPU scheduling, printer spooling, BFS, buffering, and bandwidth management. |

---

## Unit 5: Trees

| No. | Question | Answer |
| :---: | :--- | :--- |
| **1** | What is a tree? | A non-linear hierarchical structure of nodes connected by edges, with one root and no cycles. |
| **2** | Define root, leaf, and parent. | Root: topmost node. Leaf: node with no children. Parent: node with child nodes. |
| **3** | What is a binary tree? | A tree where each node has at most two children (left and right). |
| **4** | Types of binary trees? | Full, complete, perfect, skewed, and balanced. |
| **5** | Maximum nodes at level $i$ in a binary tree? | $2^i$ (root at level 0). |
| **6** | Maximum nodes in a binary tree of height $h$? | $2^{h+1} - 1$ (height of a single node = 0). |
| **7** | What is a Binary Search Tree (BST)? | A binary tree where the left subtree has smaller keys and the right subtree has larger keys than the node. |
| **8** | BST search time complexity? | $O(h)$: $O(\log n)$ average, $O(n)$ worst (skewed). |
| **9** | How do you insert into a BST? | Compare with the node; go left if smaller, right if larger; insert at the first empty spot. |
| **10** | Cases for deleting a node in a BST? | Leaf (remove it), one child (replace with the child), two children (replace with the inorder successor or predecessor). |
| **11** | What are the three DFS traversals? | Inorder (L, Root, R), Preorder (Root, L, R), Postorder (L, R, Root). |
| **12** | What does inorder traversal of a BST give? | Keys in sorted (ascending) order. |
| **13** | Which traversal is used to copy a tree? | Preorder. |
| **14** | Which traversal is used to delete a tree? | Postorder. |
| **15** | How do you do non-recursive inorder traversal? | Use an explicit stack: go left pushing nodes, pop and visit, then move right. |
| **16** | What is level-order traversal? | Visiting nodes level by level using a queue (BFS). |
| **17** | What is an AVL tree? | A self-balancing BST where the balance factor of every node is $-1, 0,$ or $+1$. |
| **18** | What is the balance factor? | Height of the left subtree minus height of the right subtree. |
| **19** | What are the AVL rotations? | LL (right rotation), RR (left rotation), LR, and RL (double rotations). |
| **20** | Why use AVL over BST? | It guarantees $O(\log n)$ search, insert, and delete by preventing skewing. |

---

## Unit 6: Graphs

| No. | Question | Answer |
| :---: | :--- | :--- |
| **1** | What is a graph? | A set of vertices (nodes) connected by edges, $G = (V, E)$. |
| **2** | Directed vs undirected graph? | Directed edges have a direction ($A \to B$); undirected edges are two-way. |
| **3** | What is a weighted graph? | A graph where each edge has a cost or weight. |
| **4** | Define degree, path, and cycle. | Degree: number of edges at a vertex. Path: sequence of connected vertices. Cycle: path that starts and ends at the same vertex. |
| **5** | What is a connected graph? | A graph where there is a path between every pair of vertices. |
| **6** | What is an adjacency matrix? | A $V \times V$ matrix where cell $[i][j] = 1$ (or the weight) if there is an edge from $i$ to $j$. |
| **7** | Space complexity of an adjacency matrix? | $O(V^2)$. |
| **8** | What is an adjacency list? | An array of linked lists where each vertex stores its neighbors. |
| **9** | Space complexity of an adjacency list? | $O(V + E)$. |
| **10** | When is an adjacency list better? | For sparse graphs, since it saves memory. |
| **11** | How does BFS work? | It explores level by level from the source using a queue. |
| **12** | How does DFS work? | It goes as deep as possible along a path, then backtracks, using a stack or recursion. |
| **13** | Time complexity of BFS and DFS? | $O(V + E)$ with an adjacency list; $O(V^2)$ with a matrix. |
| **14** | BFS applications? | Shortest path in unweighted graphs, level-wise traversal, finding connected components. |
| **15** | What is a spanning tree? | A subgraph that connects all vertices with no cycles and $V - 1$ edges. |
| **16** | What is a Minimum Spanning Tree (MST)? | The spanning tree with the minimum total edge weight. |
| **17** | Name MST algorithms. | Prim's, Kruskal's, and Borůvka's. |
| **18** | How does Kruskal's algorithm work? | It sorts edges by weight and adds each edge if it doesn't form a cycle (using Union-Find). Time: $O(E \log E)$. |
| **19** | How does Dijkstra's algorithm work? | It repeatedly picks the unvisited vertex with the smallest distance and relaxes its neighbors' distances. |
| **20** | Limitation of Dijkstra's algorithm? | It doesn't work with negative edge weights. Complexity is $O(V^2)$ with an array, or $O((V+E) \log V)$ with a min-heap. |
