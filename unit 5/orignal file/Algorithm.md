# Algorithm: Hospital Department Connectivity and Shortest Route Using BFS and Dijkstra's Algorithm

## Student Details
- **Name:** Vaishali Rathod | **Roll No.:** 26013 | **Branch:** ENTC
- **College:** Amrutvahini College of Engineering, Sangamner

## Objective
Implement a weighted undirected graph in C++ representing hospital departments (vertices) and corridors (weighted edges), perform Breadth-First Search (BFS) from the Emergency Department to list reachable units, and execute Dijkstra's algorithm to compute the shortest corridor route and distance to a target department.

## Data Structure
1. **`Edge` Structure:**
   - `to`: destination department vertex index.
   - `weight`: corridor length in meters.
2. **`HospitalGraph` Class:**
   - `numDepartments`: total number of hospital units (`V`).
   - `deptNames`: `vector<string>` mapping vertex ID to department name.
   - `adjList`: `vector<vector<Edge>>` storing connected corridors for each vertex.

## Step-by-Step Algorithm

### 1. Initialize the Hospital Graph
1. Start.
2. Create a `HospitalGraph` object with `V = 6` departments:
   - `0`: Emergency Department
   - `1`: Radiology (X-Ray/CT)
   - `2`: ICU
   - `3`: Operation Theatre
   - `4`: Pathology Lab
   - `5`: Pharmacy
3. Add undirected weighted edges (`addCorridor(u, v, distance)`) representing physical corridors in meters.

### 2. Breadth-First Search — `bfsFromEmergency(startDept = 0)`
1. Initialize a boolean array `visited[0..V-1]` to `false` and create an empty FIFO queue `q`.
2. Mark `visited[startDept] = true` and enqueue `startDept`.
3. While `q` is not empty:
   - Dequeue the front vertex `curr` and display its ID and department name.
   - For each neighbor `edge.to` in `adjList[curr]`:
     - If `visited[edge.to]` is `false`, mark `visited[edge.to] = true` and enqueue `edge.to`.
4. Return to the main menu.

### 3. Dijkstra's Shortest Path — `shortestRouteDijkstra(startDept, destDept)`
1. Initialize `dist[0..V-1] = INF` and `parent[0..V-1] = -1`.
2. Set `dist[startDept] = 0` and push `(0, startDept)` into a min-priority queue `pq`.
3. While `pq` is not empty:
   - Extract the pair `(d, u)` with minimum distance.
   - If `d > dist[u]`, ignore the outdated entry and continue.
   - For each corridor `edge` in `adjList[u]`:
     - If `dist[u] + edge.weight < dist[edge.to]`:
       - Update `dist[edge.to] = dist[u] + edge.weight`.
       - Set `parent[edge.to] = u`.
       - Push `(dist[edge.to], edge.to)` into `pq`.
4. If `dist[destDept] == INF`, display `"No Route Available"`.
5. Otherwise, backtrack from `destDept` to `startDept` using `parent[]`, reverse the sequence, and print the shortest route and total distance in meters.

## Complexity Analysis

Let `V` be the number of hospital departments and `E` be the number of corridors.

| Operation | Time Complexity | Auxiliary Space | Explanation |
|---|---|---|---|
| Add Corridor (`addCorridor`) | O(1) | O(1) | Appends edge to two adjacency lists. |
| Display Graph (`displayGraph`) | O(V + E) | O(1) | Visits every department and corridor list. |
| BFS Traversal (`bfsFromEmergency`) | O(V + E) | O(V) | Visits each reachable vertex and edge once using queue. |
| Dijkstra's Algorithm (`shortestRouteDijkstra`) | O((V + E) log V) | O(V) | Binary heap priority queue relaxations and parent tracking. |
