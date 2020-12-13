/*
1. 작은 값이 먼저 들어가야 하는 줄 알았다. 하지만 상관이 없다.
2. ios::sync... cin.tie 아무 소용 없다. 무조건 scanf printf 쓰자.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;

int par[MAX];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

int main() {
    int n, m, a, b, op;
    scanf("%d %d", &n, &m);
    // initialize parents
    for (int i = 0; i <= n; i++)
        par[i] = i;
    
    while (m--) {
        scanf("%d %d %d", &op, &a, &b);
        if (op == 0) {
            par[find(b)] = find(a);
        }
        else{
            if(find(a) == find(b))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}


