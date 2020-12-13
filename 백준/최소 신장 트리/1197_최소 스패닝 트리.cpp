#include <iostream>
#include <vector>
#include <algorithm>

int getParent(int set[], int x) {
    if (set[x] == x) return x;
    return set[x] = getParent(set, set[x]);
}

void unionParent(int set[], int a, int b) {
    a = getParent(set, a);
    b = getParent(set, b);
    if (a < b) set[b] = a;
    else set[a] = b;
}

bool findParent(int set[], int a, int b) {
    a = getParent(set, a);
    b = getParent(set, b);
    return a == b;
}

class Edge {
public:
    int node[2];
    int weight;
    Edge(int from, int to, int weight) {
        this->node[0] = from;
        this->node[1] = to;
        this->weight = weight;
    }
};

bool compare (Edge a, Edge b) {
    return a.weight < b.weight;
}

int main() {
    int v, e, from, to, weight;
    scanf("%d %d", &v, &e);
    
    int *set = new int[v];
    
    for (int i = 0; i < v; i++) {
        set[i] = i;
    }
    
    std::vector<Edge> edge;
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &from, &to, &weight);
        edge.push_back(Edge(from, to, weight));
    }
    sort(edge.begin(), edge.end(), compare);
    int minSum = 0;
    int cnt = 0;
    for (int i = 0; i < edge.size(); i++) {
        if (!findParent(set, edge[i].node[0] - 1, edge[i].node[1] - 1)) {
            minSum += edge[i].weight;
            unionParent(set, edge[i].node[0] - 1, edge[i].node[1] - 1);
            if (++cnt == v - 1) break;
        }
    }
    free(set);
    printf("%d\n", minSum);
}
