#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int bfs(vector<string>& place) {
    int n = (int)place.size();
    int m = (int)place[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (place[i][j] == 'P') {
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                queue<pair<pair<int, int>, int>> q;
                q.push({{i, j}, 0});
                visited[i][j] = true;

                while (!q.empty()) {
                    int x = q.front().first.first;
                    int y = q.front().first.second;
                    int cnt = q.front().second;
                    q.pop();

                    if (place[x][y] == 'P' && 0 < cnt && cnt <= 2) return 0;

                    if (cnt == 2) continue;

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (place[nx][ny] != 'X' && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({{nx, ny}, cnt + 1});
                        }
                    }
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto& place : places) {
        answer.push_back(bfs(place));
    }
    return answer;
}

int main() {
    vector<vector<string>> places = {
        {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};

    for (auto a : solution(places)) {
        cout << a << ' ';
    }
    cout << endl;

    return 0;
}
