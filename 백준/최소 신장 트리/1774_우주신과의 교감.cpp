#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<double, pair<int, int>>> v;
int pos[1000001][2];
int par[1001];

int find (int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

bool Merge (int x, int y) {
    x = find(x);
    y = find(y);
    
    if (x == y) return false;
    else {
        par[y] = x;
        return true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, a, b;
    cin >> n >> m;
    // 위치 입력 1부터
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 2; j++)
            cin >> pos[i][j];
    // parent 초기화 1부터
    for (int i = 1; i <= n; i++)
        par[i] = i;
    // 이미 연결된 통로 입력받아 parent 작은 값으로 미리 설정
    while (m--) {
        cin >> a >> b;
        Merge(a, b);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double d = sqrt( pow(pos[i][0] - pos[j][0], 2.0) +
                            pow(pos[i][1] - pos[j][1], 2.0));
            v.push_back({ d, {i, j} });
        }
    }
    
    sort(v.begin(), v.end());
    
    double ans = 0;
    
    for (int i = 0; i < v.size(); i++) {
        double w = v[i].first;
        int a = v[i].second.first;
        int b = v[i].second.second;
        
        if (Merge(a, b)) {
            ans += w;
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}
