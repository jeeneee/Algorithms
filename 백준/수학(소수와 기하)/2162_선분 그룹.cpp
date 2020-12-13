//
//  2162_선분 그룹.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/23.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

vector<pair<pll, pll>> line;
vector<int> parent;
vector<int> num;

int ccw(pll &p1, pll &p2, pll &p3) {
    ll op = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    op -= p1.second * p2.first + p2.second * p3.first + p3.second * p1.first;
    
    if (op > 0) return 1;
    else if (op < 0) return -1;
    else return 0;
}

bool intersection(int line1, int line2) {
    pll p1 = line[line1].first;
    pll p2 = line[line1].second;
    pll p3 = line[line2].first;
    pll p4 = line[line2].second;
    
    int line1_2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int line2_1 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
    
    if (line1_2 == 0 && line2_1 == 0) {
        if (p1 > p2) swap(p1, p2);
        if (p3 > p4) swap(p3, p4);
        
        return p1 <= p4 && p3 <= p2;
    }
    return line1_2 <= 0 && line2_1 <= 0;
}

int getParent(int p) {
    if (parent[p] == p) return p;
    return getParent(parent[p]);
}

void union_find(int a, int b) {
    int p_a = getParent(a);
    int p_b = getParent(b);
    if (p_a < p_b)
        parent[p_b] = p_a;
    else
        parent[p_a] = p_b;
}

int main() {
    int n;
    scanf("%d", &n);
    line.resize(n);
    parent.resize(n);
    num.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &line[i].first.first, &line[i].first.second);
        scanf("%lld %lld", &line[i].second.first, &line[i].second.second);
        parent[i] = i;
        num[i] = 0;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (intersection(i, j))
                union_find(i, j);
        }
    }
    
    int group = 0, max_num = 0;
    for (int i = 0; i < n; ++i) {
        if (parent[i] == i) group++;
        int p = getParent(i);
        num[p]++;
        max_num = max(max_num, num[p]);
    }
    
    cout << group << '\n';
    cout << max_num << '\n';
    
    return 0;
}
