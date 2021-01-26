#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int MAX = 200 + 1;
const int INF = 2e9;
vector<pii> graph[MAX];

vector<int> dijkstra(int src, int n) {
    vector<int> dist(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[src] = 0;
    pq.push({dist[src], src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (d > dist[v]) continue;

        for (auto& adj : graph[v]) {
            int adj_v = adj.first;
            int adj_d = d + adj.second;
            if (adj_d < dist[adj_v]) {
                dist[adj_v] = adj_d;
                pq.push({dist[adj_v], adj_v});
            }
        }
    }
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    for (auto& fare : fares) {
        graph[fare[0]].push_back({fare[1], fare[2]});
        graph[fare[1]].push_back({fare[0], fare[2]});
    }

    vector<int> cost_ab = dijkstra(s, n);
    vector<int> cost_a = dijkstra(a, n);
    vector<int> cost_b = dijkstra(b, n);

    for (int i = 1; i <= n; i++)
        answer = min(answer, cost_ab[i] + cost_a[i] + cost_b[i]);

    return answer;
}

int main() {
    vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2},
                                 {3, 1, 41}, {5, 1, 24}, {4, 6, 50},
                                 {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
    cout << solution(6, 4, 6, 2, fares) << endl;
    return 0;
}