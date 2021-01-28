#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2e9;
const int MAX = 300000;
vector<int> tree[MAX];
int sum[MAX];
int dp[MAX][2];

void go(int root, vector<int>& sales) {
    for (auto child : tree[root]) go(child, sales);

    if (tree[root].empty()) {
        dp[root][0] = 0;
        dp[root][1] = sales[root];
        return;
    }

    int sum = 0;
    bool flag = false;
    for (auto child : tree[root]) {
        sum += min(dp[child][0], dp[child][1]);
        if (dp[child][0] >= dp[child][1]) flag = true;
    }

    dp[root][1] = sum + sales[root];

    if (flag) {
        dp[root][0] = sum;
    } else {
        int diff = INF;
        for (auto child : tree[root])
            diff = min(diff, dp[child][1] - dp[child][0]);
        dp[root][0] = sum + diff;
    }
}

int solution(vector<int> sales, vector<vector<int>> links) {
    for (auto& link : links) tree[link[0] - 1].push_back(link[1] - 1);
    go(0, sales);
    return min(dp[0][0], dp[0][1]);
}

int main() {
    vector<int> sales = {14, 17, 15, 18, 19, 14, 13, 16, 28, 17};
    vector<vector<int>> links = {{10, 8}, {1, 9},  {9, 7}, {5, 4}, {1, 5},
                                 {5, 10}, {10, 6}, {1, 3}, {10, 2}};
    cout << solution(sales, links) << endl;
    return 0;
}