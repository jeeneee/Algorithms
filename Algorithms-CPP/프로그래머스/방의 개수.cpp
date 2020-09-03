//
//  방의 개수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/26.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 X자를 확인해줘야 하므로 모든 좌표를 2배로 늘린다.
 edge 오름차 순으로 저장한다면 굳이 중복되는 두 선을 저장할 필요는 없다.
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
    bool operator<(const Point& a) const {
        if (x == a.x) return y < a.y;
        return x < a.x;
    }
};
const int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int solution(vector<int> arrows) {
    int answer = 0;
    map<Point, int> vertex;
    map<pair<Point, Point>, int> edge;
    int x = 0, y = 0;
    vertex[{ x, y }] = 1;
    for (auto arrow : arrows) {
        for (int i = 0; i < 2; ++i) {
            int nx = x + dx[arrow];
            int ny = y + dy[arrow];
            Point cur(x, y), next(nx, ny);
            if (vertex[next] && !edge[{ cur, next }] && !edge[{ next, cur }])
                answer++;
            vertex[next] = 1;
            edge[{ cur, next }] = 1;
            edge[{ next, cur }] = 1;
            x = nx; y = ny;
        }
    }
    return answer;
}

int main() {
	vector<int> arrows = {6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0};
	cout << solution(arrows) << endl;
	return 0;
}
