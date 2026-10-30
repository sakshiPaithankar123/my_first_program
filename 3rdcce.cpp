
#include <iostream>
using namespace std;

const int N = 5;
const int INF = 99999;

class RoadNetwork {
private:
    char location[N][20];
    int graph[N][N];

public:
    // Constructor initializes locations and road distances
    RoadNetwork() {
        const char names[N][20] = {
            "College", "Hospital", "Market",
            "Railway", "BusStand"
        };

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 20; j++)
                location[i][j] = names[i][j];
        }

        // Initialize all roads as absent
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                graph[i][j] = (i == j) ? 0 : INF;
        }

        // Add roads with distances in kilometres
        graph[0][1] = graph[1][0] = 4;
        graph[0][2] = graph[2][0] = 2;
        graph[1][2] = graph[2][1] = 1;
        graph[1][3] = graph[3][1] = 5;
        graph[2][3] = graph[3][2] = 8;
        graph[2][4] = graph[4][2] = 10;
        graph[3][4] = graph[4][3] = 2;
    }

    // Display all locations
    void displayLocations() {
        cout << "\nAvailable Locations:\n";
        for (int i = 0; i < N; i++)
            cout << i + 1 << ". " << location[i] << "\n";
    }

    // Display all directly connected roads
    void displayRoads() {
        cout << "\nRoads and Distances:\n";
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (graph[i][j] != INF) {
                    cout << location[i] << " - "
                         << location[j] << " : "
                         << graph[i][j] << " km\n";
                }
            }
        }
    }

    // Find the shortest path using Dijkstra's algorithm
    void shortestPath(int source, int destination) {
        int dist[N], parent[N];
        bool visited[N];

        for (int i = 0; i < N; i++) {
            dist[i] = INF;
            parent[i] = -1;
            visited[i] = false;
        }

        dist[source] = 0;

        for (int count = 0; count < N; count++) {
            int u = -1;
            int minDist = INF;

            // Select nearest unvisited vertex
            for (int i = 0; i < N; i++) {
                if (!visited[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    u = i;
                }
            }

            if (u == -1)
                break;

            visited[u] = true;

            // Update distances of adjacent vertices
            for (int v = 0; v < N; v++) {
                if (!visited[v] && graph[u][v] != INF &&
                    dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }

        if (dist[destination] == INF) {
            cout << "\nNo route is available.\n";
            return;
        }

        // Reconstruct the shortest path
        int path[N], length = 0;
        int current = destination;

        while (current != -1) {
            path[length++] = current;
            current = parent[current];
        }

        cout << "\nShortest Route: ";
        for (int i = length - 1; i >= 0; i--) {
            cout << location[path[i]];
            if (i > 0)
                cout << " -> ";
        }

        cout << "\nTotal Distance: "
             << dist[destination] << " km\n";
    }
};

int main() {
    RoadNetwork road;
    int choice, source, destination;

    do {
        cout << "\n===== SHORTEST PATH FINDER =====\n";
        cout << "1. Display Locations\n";
        cout << "2. Display Roads\n";
        cout << "3. Find Shortest Path\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            road.displayLocations();
            break;

        case 2:
            road.displayRoads();
            break;

        case 3:
            road.displayLocations();

            cout << "Enter source number: ";
            cin >> source;
            cout << "Enter destination number: ";
            cin >> destination;

            if (source < 1 || source > N ||
                destination < 1 || destination > N) {
                cout << "Invalid location number.\n";
            } else {
                road.shortestPath(source - 1,
                                  destination - 1);
            }
            break;

        case 4:
            cout << "Exiting program. Thank you!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}


#include <iostream>
using namespace std;

const int N = 5;
const int INF = 99999;

class RoadNetwork {
private:
    char location[N][20];
    int graph[N][N];

public:
    // Constructor initializes locations and road distances
    RoadNetwork() {
        const char names[N][20] = {
            "College", "Hospital", "Market",
            "Railway", "BusStand"
        };

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 20; j++)
                location[i][j] = names[i][j];
        }

        // Initialize all roads as absent
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                graph[i][j] = (i == j) ? 0 : INF;
        }

        // Add roads with distances in kilometres
        graph[0][1] = graph[1][0] = 4;
        graph[0][2] = graph[2][0] = 2;
        graph[1][2] = graph[2][1] = 1;
        graph[1][3] = graph[3][1] = 5;
        graph[2][3] = graph[3][2] = 8;
        graph[2][4] = graph[4][2] = 10;
        graph[3][4] = graph[4][3] = 2;
    }

    // Display all locations
    void displayLocations() {
        cout << "\nAvailable Locations:\n";
        for (int i = 0; i < N; i++)
            cout << i + 1 << ". " << location[i] << "\n";
    }

    // Display all directly connected roads
    void displayRoads() {
        cout << "\nRoads and Distances:\n";
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (graph[i][j] != INF) {
                    cout << location[i] << " - "
                         << location[j] << " : "
                         << graph[i][j] << " km\n";
                }
            }
        }
    }

    // Find the shortest path using Dijkstra's algorithm
    void shortestPath(int source, int destination) {
        int dist[N], parent[N];
        bool visited[N];

        for (int i = 0; i < N; i++) {
            dist[i] = INF;
            parent[i] = -1;
            visited[i] = false;
        }

        dist[source] = 0;

        for (int count = 0; count < N; count++) {
            int u = -1;
            int minDist = INF;

            // Select nearest unvisited vertex
            for (int i = 0; i < N; i++) {
                if (!visited[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    u = i;
                }
            }

            if (u == -1)
                break;

            visited[u] = true;

            // Update distances of adjacent vertices
            for (int v = 0; v < N; v++) {
                if (!visited[v] && graph[u][v] != INF &&
                    dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }

        if (dist[destination] == INF) {
            cout << "\nNo route is available.\n";
            return;
        }

        // Reconstruct the shortest path
        int path[N], length = 0;
        int current = destination;

        while (current != -1) {
            path[length++] = current;
            current = parent[current];
        }

        cout << "\nShortest Route: ";
        for (int i = length - 1; i >= 0; i--) {
            cout << location[path[i]];
            if (i > 0)
                cout << " -> ";
        }

        cout << "\nTotal Distance: "
             << dist[destination] << " km\n";
    }
};

int main() {
    RoadNetwork road;
    int choice, source, destination;

    do {
        cout << "\n===== SHORTEST PATH FINDER =====\n";
        cout << "1. Display Locations\n";
        cout << "2. Display Roads\n";
        cout << "3. Find Shortest Path\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            road.displayLocations();
            break;

        case 2:
            road.displayRoads();
            break;

        case 3:
            road.displayLocations();

            cout << "Enter source number: ";
            cin >> source;
            cout << "Enter destination number: ";
            cin >> destination;

            if (source < 1 || source > N ||
                destination < 1 || destination > N) {
                cout << "Invalid location number.\n";
            } else {
                road.shortestPath(source - 1,
                                  destination - 1);
            }
            break;

        case 4:
            cout << "Exiting program. Thank you!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
#include <iostream>
using namespace std;

const int N = 5;
const int INF = 99999;

class RoadNetwork {
private:
    char location[N][20];
    int graph[N][N];

public:
    // Constructor initializes locations and road distances
    RoadNetwork() {
        const char names[N][20] = {
            "College", "Hospital", "Market",
            "Railway", "BusStand"
        };

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 20; j++)
                location[i][j] = names[i][j];
        }

        // Initialize all roads as absent
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                graph[i][j] = (i == j) ? 0 : INF;
        }

        // Add roads with distances in kilometres
        graph[0][1] = graph[1][0] = 4;
        graph[0][2] = graph[2][0] = 2;
        graph[1][2] = graph[2][1] = 1;
        graph[1][3] = graph[3][1] = 5;
        graph[2][3] = graph[3][2] = 8;
        graph[2][4] = graph[4][2] = 10;
        graph[3][4] = graph[4][3] = 2;
    }

    // Display all locations
    void displayLocations() {
        cout << "\nAvailable Locations:\n";
        for (int i = 0; i < N; i++)
            cout << i + 1 << ". " << location[i] << "\n";
    }

    // Display all directly connected roads
    void displayRoads() {
        cout << "\nRoads and Distances:\n";
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (graph[i][j] != INF) {
                    cout << location[i] << " - "
                         << location[j] << " : "
                         << graph[i][j] << " km\n";
                }
            }
        }
    }

    // Find the shortest path using Dijkstra's algorithm
    void shortestPath(int source, int destination) {
        int dist[N], parent[N];
        bool visited[N];

        for (int i = 0; i < N; i++) {
            dist[i] = INF;
            parent[i] = -1;
            visited[i] = false;
        }

        dist[source] = 0;

        for (int count = 0; count < N; count++) {
            int u = -1;
            int minDist = INF;

            // Select nearest unvisited vertex
            for (int i = 0; i < N; i++) {
                if (!visited[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    u = i;
                }
            }

            if (u == -1)
                break;

            visited[u] = true;

            // Update distances of adjacent vertices
            for (int v = 0; v < N; v++) {
                if (!visited[v] && graph[u][v] != INF &&
                    dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }

        if (dist[destination] == INF) {
            cout << "\nNo route is available.\n";
            return;
        }

        // Reconstruct the shortest path
        int path[N], length = 0;
        int current = destination;

        while (current != -1) {
            path[length++] = current;
            current = parent[current];
        }

        cout << "\nShortest Route: ";
        for (int i = length - 1; i >= 0; i--) {
            cout << location[path[i]];
            if (i > 0)
                cout << " -> ";
        }

        cout << "\nTotal Distance: "
             << dist[destination] << " km\n";
    }
};

int main() {
    RoadNetwork road;
    int choice, source, destination;

    do {
        cout << "\n===== SHORTEST PATH FINDER =====\n";
        cout << "1. Display Locations\n";
        cout << "2. Display Roads\n";
        cout << "3. Find Shortest Path\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            road.displayLocations();
            break;

        case 2:
            road.displayRoads();
            break;

        case 3:
            road.displayLocations();

            cout << "Enter source number: ";
            cin >> source;
            cout << "Enter destination number: ";
            cin >> destination;

            if (source < 1 || source > N ||
                destination < 1 || destination > N) {
                cout << "Invalid location number.\n";
            } else {
                road.shortestPath(source - 1,
                                  destination - 1);
            }
            break;

        case 4:
            cout << "Exiting program. Thank you!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
// ===== SHORTEST PATH FINDER =====
// 1. Display Locations
// 2. Display Roads
// 3. Find Shortest Path
// 4. Exit
// Enter your choice: 1

// Available Locations:
// 1. College
// 2. Hospital
// 3. Market
// 4. Railway
// 5. BusStand

// ===== SHORTEST PATH FINDER =====
// 1. Display Locations
// 2. Display Roads
// 3. Find Shortest Path
// 4. Exit
// Enter your choice: 3

// Available Locations:
// 1. College
// 2. Hospital
// 3. Market
// 4. Railway
// 5. BusStand
// Enter source number: 1
// Enter destination number: 2

// Shortest Route: College -> Market -> Hospital
// Total Distance: 3 km

// ===== SHORTEST PATH FINDER =====
// 1. Display Locations
// 2. Display Roads
// 3. Find Shortest Path
// 4. Exit
// Enter your choice: 
// PS C:\practice> ^C
// PS C:\practice> 