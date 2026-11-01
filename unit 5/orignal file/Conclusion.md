# Conclusion: Hospital Department Connectivity and Shortest Route Using BFS and Dijkstra's Algorithm

## Student Details
- **Name:** Vaishali Rathod
- **Roll No.:** 26013
- **Branch:** ENTC
- **College:** Amrutvahini College of Engineering, Sangamner

## Conclusion
1. The Hospital Department Graph Navigation System models a multi-department hospital floor plan as a weighted undirected graph where departments act as vertices and corridors act as weighted edges in meters.
2. Applying **Breadth-First Search (BFS)** from the Emergency Department (`[0]`) explores all reachable hospital units in level-by-level proximity order in **O(V + E)** time, verifying full connectivity across emergency and clinical care units.
3. Applying **Dijkstra's Shortest Path Algorithm** with a min-priority queue computes the optimal emergency transfer route and exact distance in **O((V + E) log V)** time—for instance, identifying the 65-meter route from Emergency Department to Operation Theatre (`Emergency -> Radiology -> ICU -> Operation Theatre`) over longer direct alternatives.
4. Using an adjacency list representation ensures memory efficiency proportional to **O(V + E)** and supports rapid traversal and route reconstruction for hospital logistics and patient transport.
