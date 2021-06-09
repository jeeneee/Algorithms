#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<vector<int>> graph;
vector<long long> weight;
long long answer = 0;

void init(vector<int>& a, vector<vector<int>>& edges) {
    int n = a.size();
    graph.resize(n);
    for (int i = 0; i < n; i++) weight.push_back(a[i]);
    for (auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
}

void dfs(int prev, int cur) {
    for (auto child : graph[cur]) {
        if (child != prev)
            dfs(cur, child);
    }
    weight[prev] += weight[cur];
    answer += abs(weight[cur]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    if (accumulate(a.begin(), a.end(), 0) != 0) return -1;

    init(a, edges);
    dfs(0, 0);
    return answer;
}