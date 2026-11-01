#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <limits>
#include <iomanip>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

class HospitalGraph {
private:
    int numDepartments;
    vector<string> deptNames;
    vector<vector<Edge>> adjList;

public:
    HospitalGraph(int n) : numDepartments(n), deptNames(n), adjList(n) {}

    void setDepartmentName(int id, const string& name) {
        if (id >= 0 && id < numDepartments) {
            deptNames[id] = name;
        }
    }

    void addCorridor(int u, int v, int distance) {
        if (u >= 0 && u < numDepartments && v >= 0 && v < numDepartments && distance > 0) {
            adjList[u].push_back({v, distance});
            adjList[v].push_back({u, distance});
        }
    }

    void displayGraph() const {
        cout << "\n--- Hospital Department Corridor Network ---\n";
        for (int i = 0; i < numDepartments; ++i) {
            cout << "[" << i << "] " << left << setw(22) << deptNames[i] << " -> ";
            if (adjList[i].empty()) {
                cout << "No connected corridors";
            } else {
                for (size_t j = 0; j < adjList[i].size(); ++j) {
                    cout << deptNames[adjList[i][j].to] << " (" << adjList[i][j].weight << "m)";
                    if (j + 1 < adjList[i].size()) cout << ", ";
                }
            }
            cout << "\n";
        }
    }

    // Apply BFS from Emergency Department (vertex 0) to display reachable units
    void bfsFromEmergency(int startDept = 0) const {
        if (startDept < 0 || startDept >= numDepartments) {
            cout << "Invalid starting department ID.\n";
            return;
        }

        vector<bool> visited(numDepartments, false);
        queue<int> q;

        visited[startDept] = true;
        q.push(startDept);

        cout << "\n--- BFS Traversal from " << deptNames[startDept] << " ---\n";
        cout << "Reachable Hospital Units in Level Order:\n";

        int step = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << "  " << step++ << ". [" << curr << "] " << deptNames[curr] << "\n";

            for (const auto& edge : adjList[curr]) {
                if (!visited[edge.to]) {
                    visited[edge.to] = true;
                    q.push(edge.to);
                }
            }
        }
    }

    // Apply Dijkstra's algorithm to calculate shortest route and distance
    void shortestRouteDijkstra(int startDept, int destDept) const {
        if (startDept < 0 || startDept >= numDepartments || destDept < 0 || destDept >= numDepartments) {
            cout << "Invalid department ID selected.\n";
            return;
        }

        vector<int> dist(numDepartments, INF);
        vector<int> parent(numDepartments, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[startDept] = 0;
        pq.push({0, startDept});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (const auto& edge : adjList[u]) {
                if (dist[u] != INF && dist[u] + edge.weight < dist[edge.to]) {
                    dist[edge.to] = dist[u] + edge.weight;
                    parent[edge.to] = u;
                    pq.push({dist[edge.to], edge.to});
                }
            }
        }

        cout << "\n--- Dijkstra's Shortest Path Result ---\n";
        cout << "Source      : [" << startDept << "] " << deptNames[startDept] << "\n";
        cout << "Destination : [" << destDept << "] " << deptNames[destDept] << "\n";

        if (dist[destDept] == INF) {
            cout << "Status      : No Route Available (Destination is unreachable).\n";
            return;
        }

        vector<int> path;
        for (int v = destDept; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << "Shortest Route : ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << deptNames[path[i]];
            if (i + 1 < path.size()) cout << " -> ";
        }
        cout << "\nTotal Distance : " << dist[destDept] << " meters\n";
    }

    void listDepartments() const {
        cout << "\nAvailable Hospital Departments:\n";
        for (int i = 0; i < numDepartments; ++i) {
            cout << "  " << i << " : " << deptNames[i] << "\n";
        }
    }
};

int main() {
    HospitalGraph hospital(6);

    hospital.setDepartmentName(0, "Emergency Department");
    hospital.setDepartmentName(1, "Radiology (X-Ray/CT)");
    hospital.setDepartmentName(2, "ICU");
    hospital.setDepartmentName(3, "Operation Theatre");
    hospital.setDepartmentName(4, "Pathology Lab");
    hospital.setDepartmentName(5, "Pharmacy");

    // Preloaded hospital corridors with distances in meters
    hospital.addCorridor(0, 1, 30);
    hospital.addCorridor(0, 2, 50);
    hospital.addCorridor(1, 2, 15);
    hospital.addCorridor(1, 4, 25);
    hospital.addCorridor(2, 3, 20);
    hospital.addCorridor(4, 3, 35);
    hospital.addCorridor(4, 5, 20);
    hospital.addCorridor(3, 5, 15);

    int choice, dest;
    do {
        cout << "\n=============================================\n";
        cout << "   HOSPITAL DEPARTMENT GRAPH NAVIGATION\n";
        cout << "=============================================\n";
        cout << "1. Display Hospital Graph (Departments & Corridors)\n";
        cout << "2. Apply BFS from Emergency Department\n";
        cout << "3. Find Shortest Route using Dijkstra's Algorithm\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid choice.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                hospital.displayGraph();
                break;
            case 2:
                hospital.bfsFromEmergency(0);
                break;
            case 3:
                hospital.listDepartments();
                cout << "Enter Destination Department ID (0 to 5): ";
                cin >> dest;
                hospital.shortestRouteDijkstra(0, dest);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
