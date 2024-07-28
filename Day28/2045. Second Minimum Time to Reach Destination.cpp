#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Create adjacency list for the graph
        vector<vector<int>> graph(n + 1);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Distance array to store the shortest and second shortest distances
        vector<vector<int>> dist(n + 1, vector<int>(2, INT_MAX));
        dist[1][0] = 0;

        // Priority queue to perform Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});

        while (!pq.empty()) {
            auto [currentDist, node] = pq.top();
            pq.pop();

            for (int neighbor : graph[node]) {
                int newDist = currentDist + time;
                if ((currentDist / change) % 2 == 1) {
                    newDist += change - (currentDist % change);
                }

                if (newDist < dist[neighbor][0]) {
                    dist[neighbor][1] = dist[neighbor][0];
                    dist[neighbor][0] = newDist;
                    pq.push({newDist, neighbor});
                } else if (newDist > dist[neighbor][0] && newDist < dist[neighbor][1]) {
                    dist[neighbor][1] = newDist;
                    pq.push({newDist, neighbor});
                }
            }
        }

        return dist[n][1];
    }
};
