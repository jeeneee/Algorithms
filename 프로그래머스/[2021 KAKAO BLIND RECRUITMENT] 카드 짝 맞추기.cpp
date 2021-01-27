#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct Pos {
    int r, c;

    Pos() {}

    Pos(int _r, int _c) {
        r = _r;
        c = _c;
    }
} cards[7][2];

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};
const int MAX = 4;
const int INF = 2e9;
int answer;

bool inRange(int r, int c) {
    return (0 <= r && r < MAX) && (0 <= c && c < MAX);
}

int getCost(Pos src, Pos dst, vector<vector<int>>& board) {
    bool visited[MAX][MAX];
    for (int i = 0; i < MAX; i++) memset(visited[i], 0, sizeof(visited[i]));

    int ret = INF;
    queue<pair<Pos, int>> q;
    q.push({{src.r, src.c}, 0});

    while (!q.empty()) {
        int r = q.front().first.r;
        int c = q.front().first.c;
        int cnt = q.front().second;
        q.pop();

        if (visited[r][c]) continue;
        visited[r][c] = 1;

        if (r == dst.r && c == dst.c) {
            ret = min(ret, cnt);
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (!inRange(nr, nc)) continue;
            q.push({{nr, nc}, cnt + 1});

            if (board[nr][nc] != 0) continue;

            while (1) {
                nr += dr[i];
                nc += dc[i];
                if (inRange(nr, nc) && board[nr][nc] != 0) {
                    q.push({{nr, nc}, cnt + 1});
                    break;
                } else if (!inRange(nr, nc)) {
                    q.push({{nr - dr[i], nc - dc[i]}, cnt + 1});
                    break;
                }
            }
        }
    }
    return ret;
}

void go(int idx, Pos src, int total, vector<int>& route,
        vector<vector<int>>& board) {
    if (idx == route.size()) {
        answer = min(answer, total);
        return;
    }

    for (int i = 0; i < 2; i++) {
        Pos dst1(cards[route[idx]][i]);
        Pos dst2(cards[route[idx]][1 - i]);
        int cost = getCost(src, dst1, board) + getCost(dst1, dst2, board) + 2;
        board[dst1.r][dst1.c] = board[dst2.r][dst2.c] = 0;
        go(idx + 1, dst2, total + cost, route, board);
        board[dst1.r][dst1.c] = board[dst2.r][dst2.c] = route[idx];
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    answer = INF;
    set<int> s;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            int num = board[i][j];
            if (num == 0) continue;
            if (!s.count(num))
                cards[num][0] = {i, j};
            else
                cards[num][1] = {i, j};
            s.insert(num);
        }
    }

    vector<int> route(s.begin(), s.end());

    do {
        go(0, Pos(r, c), 0, route, board);
    } while (next_permutation(route.begin(), route.end()));

    return answer;
}

int main() {
    vector<vector<int>> board = {
        {1, 0, 0, 3}, {2, 0, 0, 0}, {0, 0, 0, 2}, {3, 0, 1, 0}};
    cout << solution(board, 1, 0) << endl;

    // vector<vector<int>> board = {
    //     {3, 0, 0, 2}, {0, 0, 1, 0}, {0, 1, 0, 0}, {2, 0, 0, 3}};
    // cout << solution(board, 0, 1) << endl;

    return 0;
}