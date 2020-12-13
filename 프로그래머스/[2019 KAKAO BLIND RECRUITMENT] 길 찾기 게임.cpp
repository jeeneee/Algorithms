//
//  [2019 KAKAO BLIND RECRUITMENT] 길 찾기 게임.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/09/06.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y, num;
    bool operator<(const Point& t) const {
        if (y == t.y) return x > t.x;
        return y < t.y;
    }
};

struct Node {
    int x, num;
    Node* left;
    Node* right;
    Node(int _x, int _num) : x(_x), num(_num) {
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> answer;

void preorder(Node* parent) {
    answer[0].push_back(parent->num);
    if (parent->left) preorder(parent->left);
    if (parent->right) preorder(parent->right);
}

void postorder(Node* parent) {
    if (parent->left) postorder(parent->left);
    if (parent->right) postorder(parent->right);
    answer[1].push_back(parent->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    answer.resize(2);

    priority_queue<Point> pq;
    for (int i = 0; i < nodeinfo.size(); ++i)
        pq.push({ nodeinfo[i][0], nodeinfo[i][1], i+1 });

    Node* root = new Node(pq.top().x, pq.top().num);

    while (!pq.empty()) {
        Point child = pq.top(); pq.pop();
        Node* parent = root;
        while (1) {
            if (child.x < parent->x) {
                if (parent->left == NULL) {
                    parent->left = new Node(child.x, child.num);
                    break;
                }
                else parent = parent->left;
            }
            else if (child.x > parent->x) {
                if (parent->right == NULL) {
                    parent->right = new Node(child.x, child.num);
                    break;
                }
                else parent = parent->right;
            }
            else break;
        }
    }

    preorder(root);
    postorder(root);

    return answer;
}

int main() {
    vector<vector<int>> nodeinfo = {
		{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}
	};
    vector<vector<int>> res = solution(nodeinfo);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
