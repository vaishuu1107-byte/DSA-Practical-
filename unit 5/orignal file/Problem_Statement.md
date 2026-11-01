# Problem Statement: Hospital Department Connectivity and Shortest Route Using BFS and Dijkstra's Algorithm

## Student Details
- **Name:** Vaishali Rathod
- **Roll No.:** 26013
- **Branch:** Electronics and Telecommunication Engineering (ENTC)
- **College:** Amrutvahini College of Engineering, Sangamner
- **Subject:** Data Structures and Algorithms

## Title
Hospital Department Connectivity and Shortest Route Using BFS and Dijkstra's Algorithm in C++

## Problem Statement (BTL-3: Apply)
Develop a C++ program to represent hospital departments as vertices and corridors as weighted edges. Apply Breadth-First Search (BFS) from the Emergency Department to display reachable units and apply Dijkstra's algorithm to calculate the shortest route and distance to a selected department.

## Objectives
1. Represent hospital departments as graph vertices and interconnecting corridors as undirected weighted edges using an adjacency list.
2. Apply Breadth-First Search (BFS) starting from the Emergency Department (vertex `0`) to traverse and display all reachable hospital departments in level order.
3. Apply Dijkstra's single-source shortest-path algorithm using a min-priority queue to compute the minimum corridor distance and exact path from the Emergency Department to any selected destination department.
4. Reconstruct and display the step-by-step shortest corridor route along with total distance in meters.
5. Provide a menu-driven console interface for interactive navigation and testing.

## Functional Requirements
- **Display Hospital Graph:** Show each department ID, department name, and all connected corridors with their distances in meters.
- **BFS Traversal:** Traverse from the Emergency Department using a FIFO queue and list all reachable departments in level-by-level order.
- **Shortest Route (Dijkstra's Algorithm):** Read the destination department ID, compute the shortest corridor path and total distance from the Emergency Department, and display the complete path.
- **Exit:** Terminate the program cleanly when the user selects Exit.

## Data Structures Used
- **Adjacency List (`vector<vector<Edge>>`):** Stores outgoing weighted corridors for each department vertex.
- **FIFO Queue (`queue<int>`):** Manages level-order exploration in Breadth-First Search (BFS).
- **Min-Priority Queue (`priority_queue`):** Selects the next closest unfinalized department in Dijkstra's algorithm.
