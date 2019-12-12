//
//  1991_트리 순회.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/18.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _node {
    char left;
    char right;
} node;

node tree[100];

void preorder(char r) {
    if (r == '.')
        return;
    cout << r;
    preorder(tree[r].left);
    preorder(tree[r].right);
}

void inorder(char r) {
    if (r == '.')
        return;
    inorder(tree[r].left);
    cout << r;
    inorder(tree[r].right);
}

void postorder(char r) {
    if (r == '.')
        return;
    postorder(tree[r].left);
    postorder(tree[r].right);
    cout << r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    char root, le, ri;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> root >> le >> ri;
        tree[root].left = le;
        tree[root].right = ri;
    }
    
    preorder('A');
    cout << endl;
    inorder('A');
    cout << endl;
    postorder('A');
    cout << endl;
    
    return 0;
}
