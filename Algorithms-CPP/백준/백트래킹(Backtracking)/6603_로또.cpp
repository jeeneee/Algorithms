//
//  6603_로또.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/27.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 13;
bool visited[MAX];
int arr[MAX];
vector<int> picked;
int k;

void pick(int toPick, int idx) {
    if (toPick == 0) {
        for (auto &c: picked)
            cout << c << ' ';
        cout << '\n';
    }
    
    for (int i = idx; i < k; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            picked.push_back(arr[i]);
            pick(toPick - 1, i);
            visited[i] = false;
            picked.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (true) {
        fill(visited, visited + MAX, false);
        cin >> k;
        if (k == 0)
            break;
        for (int i = 0; i < k; ++i) {
            cin >> arr[i];
        }
        pick(6, 0);
        cout << '\n';
    }
    
    return 0;
}
