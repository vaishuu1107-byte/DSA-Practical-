# Algorithm (Modified): Dynamic Hospital Graph with Before/After Comparison and Disconnected Vertex Handling

## Student Details
- **Name:** Vaishali Rathod | **Roll No.:** 26013 | **Branch:** ENTC
- **College:** Amrutvahini College of Engineering, Sangamner

## Step-by-Step Algorithm

### 1. Initialize Hospital Graph with Connected and Disconnected Units
1. Start and initialize `HospitalGraphModified` with 7 departments:
   - Connected core (`0` to `5`): Emergency Department, Radiology, ICU, Operation Theatre, Pathology Lab, Pharmacy.
   - Disconnected unit (`6`): Isolation Ward (initially has no corridor edges to demonstrate Modification C).

### 2. BFS Traversal with Disconnected Vertex Detection (`computeBFS` / `displayBFS`)
1. Run standard FIFO queue BFS from Emergency Department (`0`), recording visited vertices in `snap.reachableOrder`.
2. Scan all vertices `0..V-1`; any vertex with `visited[i] == false` is appended to `snap.disconnectedDepts`.
3. Display all reachable units in level order, followed by an explicit warning listing every disconnected/unreachable department (**Modification C**).

### 3. Dijkstra's Algorithm with Unavailable Path Handling (`computeDijkstra` / `displayDijkstra`)
1. Run Dijkstra's shortest-path relaxation from `startDept` using a min-priority queue.
2. If `dist[destDept] == INF`, set `snap.reachable = false` and print:
   `PATH UNAVAILABLE! Department [id] is disconnected from Emergency Department.` (**Modification C**).
3. Otherwise, reconstruct the shortest route via `parent[]` and display the route and total distance in meters.

### 4. Dynamic Addition of Vertices and Edges (`addDepartment` / `addCorridor`)
1. **Add Vertex (Modification A):** Append the new department name to `deptNames` and an empty edge vector to `adjList`, then display the updated hospital graph.
2. **Add/Update Edge & Compare (Modifications A & B):**
   - Capture `bfsBefore = computeBFS(0)` and `pathBefore = computeDijkstra(0, targetDept)`.
   - Insert or update the undirected weighted corridor `(u, v, w)` and display the updated graph.
   - Capture `bfsAfter = computeBFS(0)` and `pathAfter = computeDijkstra(0, targetDept)`.
   - Call `compareBeforeAndAfter()` to print the side-by-side comparison of reachable/disconnected counts, old vs. new shortest path, and distance savings in meters.

## Complexity Analysis

| Operation | Time Complexity | Auxiliary Space |
|---|---|---|
| Add New Department (`addDepartment`) | O(1) amortized | O(1) |
| Add / Update Corridor (`addCorridor`) | O(deg(u) + deg(v)) | O(1) |
| BFS + Disconnected Check (`computeBFS`) | O(V + E) | O(V) |
| Dijkstra + Path Check (`computeDijkstra`) | O((V + E) log V) | O(V) |
| Before vs. After Update Comparison | O((V + E) log V) | O(V) |
