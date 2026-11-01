# Problem Statement (Modified): Dynamic Hospital Department Graph with Route Comparison and Disconnected Unit Handling

## Student Details
- **Name:** Vaishali Rathod
- **Roll No.:** 26013
- **Branch:** Electronics and Telecommunication Engineering (ENTC)
- **College:** Amrutvahini College of Engineering, Sangamner
- **Subject:** Data Structures and Algorithms

## Title
Modified Hospital Department Connectivity and Shortest Route System Using BFS and Dijkstra's Algorithm in C++

## Original Problem Statement (BTL-3: Apply)
Develop a C++ program to represent hospital departments as vertices and corridors as weighted edges. Apply BFS from the emergency department to display reachable units and apply Dijkstra's algorithm to calculate the shortest route and distance to a selected department.

## Suggested Modifications Implemented (BTL-3: Apply)
- **Modification A:** Modify the program to accept additional vertices (new hospital departments) or edges (new/updated weighted corridors) dynamically and display the updated graph and results.
- **Modification B:** Modify the program to compare the relevant traversal (BFS reachability) and shortest-path (Dijkstra's route and distance) results before and after a graph update.
- **Modification C:** Modify the program to handle disconnected vertices or an unavailable path and display an appropriate diagnostic warning message.

## Objectives
1. Support dynamic insertion of new hospital department vertices and new/updated weighted corridor edges at runtime (**Modification A**).
2. Capture pre-update and post-update snapshots of both BFS traversal order and Dijkstra's shortest path to display a side-by-side comparison after graph updates (**Modification B**).
3. Detect isolated/disconnected hospital departments during BFS and unreachable destinations during Dijkstra's algorithm, displaying clear status warnings (**Modification C**).
