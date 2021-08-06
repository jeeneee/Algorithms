#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

const int INF = 2e9;
vector<vector<pii>> graph;
unordered_map<int, int> map;

int dijktra(int start, int end, int n) {
    vector<vector<int>> costs(1 << 11, vector<int>(n + 1, INF));
    priority_queue<pipii, vector<pipii>, greater<>> pq;
    costs[0][start] = 0;
    pq.push({costs[0][start], {start, 0}});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second.first;
        int state = pq.top().second.second;
        pq.pop();

        if (cur == end) return cost;

        for (auto& adj : graph[cur]) {
            int next = adj.first;
            int ncost = adj.second;
            int nstate = state ^ map[next];
            if (state & map[cur] && state & map[next] ||
                !(state & map[cur]) && !(state & map[next])) {
                if (ncost > 0 && cost + ncost < costs[nstate][next]) {
                    costs[nstate][next] = cost + ncost;
                    pq.push({cost + ncost, {next, nstate}});
                }
            } else if (!(state & map[cur]) && state & map[next] ||
                       (state & map[cur]) && !(state & map[next])) {
                if (ncost < 0 && cost - ncost < costs[nstate][next]) {
                    costs[nstate][next] = cost - ncost;
                    pq.push({cost - ncost, {next, nstate}});
                }
            }
        }
    }
    return INF;
}

int solution(int n, int start, int end, vector<vector<int>> roads,
             vector<int> traps) {
    graph.resize(n + 1);
    for (int i = 0; i < traps.size(); i++) {
        map[traps[i]] = 1 << i;
    }
    for (auto& road : roads) {
        graph[road[0]].push_back({road[1], road[2]});
        if (map[road[0]] || map[road[1]]) {
            graph[road[1]].push_back({road[0], -road[2]});
        }
    }
    return dijktra(start, end, n);
}

int main() {
    vector<vector<int>> roads = {{1, 2, 1}, {3, 2, 2}, {2, 4, 3}};
    vector<int> traps = {2, 3};
    cout << solution(4, 1, 4, roads, traps) << endl;
    return 0;
}