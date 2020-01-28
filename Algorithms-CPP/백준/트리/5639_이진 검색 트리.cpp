//
//  5639_이진 검색 트리.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/27.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

int tree[10001], n;

void sol(int left, int right) {
    if (left > right)
        return;
    
    int root = tree[left];
    int s = left, e = right;
    while(tree[s] >= root) ++s;
    while(tree[e] > root) --e;
    sol(s, e);
    sol(e + 1, right);
    cout << root << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int x;
    while (cin >> x) {
        tree[n++] = x;
    }
    
    sol(0, n-1);
    
    return 0;
}
