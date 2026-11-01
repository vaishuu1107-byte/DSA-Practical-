# Conclusion (Modified): Dynamic Hospital Department Graph with Route Comparison and Disconnected Unit Handling

## Student Details
- **Name:** Vaishali Rathod
- **Roll No.:** 26013
- **Branch:** ENTC
- **College:** Amrutvahini College of Engineering, Sangamner

## Conclusion
1. **Dynamic Graph Expansion (Modification A):** The modified system allows hospital administrators to add new departments (such as `[7] Blood Bank`) and construct or update weighted corridors at runtime without restarting the program or reallocating fixed-size matrices.
2. **Before-and-After Update Comparison (Modification B):** Automatically capturing traversal and shortest-path snapshots before and after adding a corridor quantifies infrastructure improvements—for example, adding a 20m corridor between ICU and Pharmacy reduces the Emergency-to-Pharmacy shortest route from **75 meters** (`Emergency -> Radiology -> Pathology Lab -> Pharmacy`) to **65 meters** (`Emergency -> Radiology -> ICU -> Pharmacy`), saving 10 meters during critical transport.
3. **Disconnected Vertex & Unavailable Path Handling (Modification C):** Unlinked units (such as `[6] Isolation Ward` prior to corridor construction, or newly added `[7] Blood Bank`) are automatically flagged during BFS traversal and reported as `PATH UNAVAILABLE` in Dijkstra's algorithm, preventing invalid routing decisions and confirming when a new corridor successfully connects an isolated unit (90m route after linking Isolation Ward to Pharmacy).
