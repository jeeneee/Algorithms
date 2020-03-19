#include<algorithm>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int n;
float x, y;
vector<pair<float, pair<int, int>>> v;
float as[101][2];
int par[101];


int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

bool Merge(int x, int y) {

    x = find(x);
    y = find(y);

    if (x == y) return false;
    else {
        par[y] = x;
        return true;
    }
}

int main() {

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> as[i][j];

    for (int i = 1; i <= n; i++)
        par[i] = i;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            float lng = 0;
            for (int a = 0; a < 2; a++) {
                lng += pow(abs(as[i][a] - as[j][a]), 2);
            }
            lng = sqrt(lng);
            v.push_back({ lng,{ i + 1, j + 1 } });
        }
    }

    sort(v.begin(), v.end());
    float ans = 0;

    for (int i = 0; i < v.size(); i++) {
        float w = v[i].first;
        int x = v[i].second.first;
        int y = v[i].second.second;
        if (Merge(x, y))
            ans += w;
    }
    printf("%.2f", ans);
    return 0;
}
