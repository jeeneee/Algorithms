#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10001][2];

void init(int n) {
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
        dp[i][1] = 0;
    }
    dp[10000][0] = 1;
    dp[10000][1] = 0;
}

void dfs(int root, int L, vector<int>& num, vector<vector<int>>& links) {
    if (root == -1) return;

    int l = links[root][0];
    int r = links[root][1];

    dfs(l, L, num, links);
    dfs(r, L, num, links);

    l = l == -1 ? 10000 : l;
    r = r == -1 ? 10000 : r;

    if (num[root] + dp[l][1] + dp[r][1] <= L) {
        dp[root][0] = dp[l][0] + dp[r][0] - 1;
        dp[root][1] = num[root] + dp[l][1] + dp[r][1];
    } else if (num[root] + dp[l][1] <= L || num[root] + dp[r][1] <= L) {
        dp[root][0] = dp[l][0] + dp[r][0];
        dp[root][1] = num[root] + min(dp[l][1], dp[r][1]);
    } else if (num[root] <= L) {
        dp[root][0] = dp[l][0] + dp[r][0] + 1;
        dp[root][1] = num[root];
    }
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
    int n = (int)links.size();
    int sum = 0;
    int root = n * (n - 1) / 2;
    for (int i = 0; i < n; i++) {
        sum += num[i];
        root -= max(links[i][0], 0) + max(links[i][1], 0);
    }

    int lo = *max_element(num.begin(), num.end());
    int hi = sum;
    int answer = hi;

    while (lo <= hi) {
        init(n);
        int mid = (lo + hi) >> 1;
        dfs(root, mid, num, links);
        if (dp[root][0] <= k) {
            answer = min(answer, mid);
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return answer;
}

int main() {
    vector<int> num = {6, 9, 7, 5};
    vector<vector<int>> links = {{-1, -1}, {-1, -1}, {-1, 0}, {2, 1}};
    cout << solution(2, num, links) << endl;
    return 0;
}