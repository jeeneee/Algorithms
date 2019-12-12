#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
    int distance;
    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
};

bool compare(Edge a, Edge b) {
    return a.distance < b.distance;
}

int main() {
    const int n = 7;    // 노드의 개수
    int set[n];
//    int m = 11;       // 간선의 개수
    
    vector<Edge> v;
    v.push_back(Edge(1, 7, 12));
    v.push_back(Edge(1, 4, 28));
    v.push_back(Edge(1, 2, 67));
    v.push_back(Edge(1, 5, 17));
    v.push_back(Edge(2, 4, 24));
    v.push_back(Edge(2, 5, 62));
    v.push_back(Edge(3, 5, 20));
    v.push_back(Edge(3, 6, 37));
    v.push_back(Edge(4, 7, 13));
    v.push_back(Edge(5, 6, 45));
    v.push_back(Edge(5, 7, 73));
    
    sort(v.begin(), v.end(), compare);
    
    for (int i = 0; i < n; i++) {
        set[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        if (!findParent(set, v[i].node[0] - 1, v[i].node[1] - 1)){
            sum += v[i].distance;
            unionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
        }
    }
    
    printf("%d \n", sum);
}

