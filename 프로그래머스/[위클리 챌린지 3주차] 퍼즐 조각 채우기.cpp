#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct Pos {
    int x, y;
    Pos(int x, int y) : x(x), y(y) {}
    bool operator<(const Pos& rhs) const {
        if (x == rhs.x) {
            return y < rhs.y;
        }
        return x < rhs.x;
    }
    bool operator==(const Pos& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
};

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
map<int, vector<set<Pos>>> shapes;
int n, m;

bool inRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void marking(int x, int y, int mark, vector<vector<int>>& table) {
    queue<Pos> q;
    q.push(Pos(x, y));
    table[x][y] = mark;
    while (!q.empty()) {
        Pos p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if (inRange(nx, ny) && table[nx][ny] == 1) {
                q.push(Pos(nx, ny));
                table[nx][ny] = mark;
            }
        }
    }
}

void store(int x, int y, int k, vector<vector<int>>& table, vector<vector<bool>>& visited) {
    int mark = table[x][y];
    queue<Pos> q;
    q.push(Pos(x, y));
    visited[x][y] = true;
    while (!q.empty()) {
        Pos p = q.front();
        q.pop();
        shapes[mark][k].insert(Pos(p.x - x, p.y - y));
        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if (inRange(nx, ny) && !visited[nx][ny] && table[nx][ny] == mark) {
                q.push(Pos(nx, ny));
                visited[p.x][p.y] = true;
            }
        }
    }
}

void rotate(vector<vector<int>>& table) {
    vector<vector<int>> temp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = table[n - j - 1][i];
        }
    }
    table = temp;
}

void bfs(int x, int y, vector<vector<int>>& game_board, set<Pos>& s, vector<vector<bool>>& visited) {
    queue<Pos> q;
    q.push(Pos(x, y));
    visited[x][y] = true;
    while (!q.empty()) {
        Pos p = q.front();
        q.pop();
        s.insert(Pos(p.x - x, p.y - y));
        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if (inRange(nx, ny) && !visited[nx][ny] && game_board[nx][ny] == 0) {
                q.push(Pos(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}

bool check(set<Pos>& s, vector<set<Pos>>& shape) {
    for (int i = 0; i < shape.size(); i++) {
        if (s == shape[i]) {
            return true;
        }
    }
    return false;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    n = (int)table.size();
    m = (int)table[0].size();

    int mark = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (table[i][j] == 1) {
                shapes[mark].resize(4);
                marking(i, j, mark++, table);
            }
        }
    }

    for (int k = 0; k < 4; k++) {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (table[i][j] > 0 && !visited[i][j]) {
                    store(i, j, k, table, visited);
                }
            }
        }
        rotate(table);
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && game_board[i][j] == 0) {
                set<Pos> s;
                bfs(i, j, game_board, s, visited);
                int size = (int)s.size();
                for (auto& shape : shapes) {
                    int mark = shape.first;
                    int shape_size = (int)shape.second[0].size();
                    if (size == shape_size && check(s, shape.second)) {
                        shapes.erase(mark);
                        answer += size;
                        break;
                    }
                }
            }
        }
    }
    return answer;
}