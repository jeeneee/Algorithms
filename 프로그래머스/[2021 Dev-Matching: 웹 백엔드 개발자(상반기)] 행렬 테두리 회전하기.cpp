#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 100 + 1;
int map[MAX][MAX];

void init(int rows, int columns) {
    int num = 1;
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
            map[i][j] = num++;
}

int rotate(int x1, int y1, int x2, int y2) {
    queue<int> q;
    int ret = 1e4;
    int x = x1;
    int y = y1;

    while (y < y2) q.push(map[x][y++]);
    while (x < x2) q.push(map[x++][y]);
    while (y > y1) q.push(map[x][y--]);
    while (x > x1) q.push(map[x--][y]);

    while (y < y2) {
        ret = min(ret, q.front());
        map[x][++y] = q.front();
        q.pop();
    }
    while (x < x2) {
        ret = min(ret, q.front());
        map[++x][y] = q.front();
        q.pop();
    }
    while (y > y1) {
        ret = min(ret, q.front());
        map[x][--y] = q.front();
        q.pop();
    }
    while (x > x1) {
        ret = min(ret, q.front());
        map[--x][y] = q.front();
        q.pop();
    }
    return ret;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    init(rows, columns);
    for (auto query : queries)
        answer.push_back(rotate(query[0], query[1], query[2], query[3]));
    return answer;
}