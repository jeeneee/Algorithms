#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    map<int, int> mp;
    priority_queue<int, vector<int>, greater<int>> pq;
    priority_queue<int> pq2;
    char a[10];
    int num;
    for (string op: operations) {
        sscanf(op.c_str(), "%s %d", a, &num);
        if (a[0] == 'I') {
            mp[num]++;
            pq.push(num);
            pq2.push(num);
        } else {
            if (num == -1) {
                while (!pq.empty()) {
                    int mn = pq.top();
                    pq.pop();
                    if (mp[mn]) {
                        mp[mn]--;
                        break;
                    }
                }
            } else {
                while (!pq2.empty()) {
                    int mx = pq2.top();
                    pq2.pop();
                    if (mp[mx]) {
                        mp[mx]--;
                        break;
                    }
                }
            }
        }
    }
    int mn = 987654321, mx = 0;
    while (!pq.empty()) {
        int num = pq.top();
        pq.pop();
        if (mp[num]) {
            mn = min(mn, num);
            mx = max(mx, num);
        }
    }
    while (!pq2.empty()) {
        int num = pq2.top();
        pq2.pop();
        if (mp[num]) {
            mn = min(mn, num);
            mx = max(mx, num);
        }
    }
    if (mn == 987654321) mn = 0;
    answer = { mx, mn };
    return answer;
}

int main() {
	vector<string> operations = {
		"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"
	};
	vector<int> ans = solution(operations);
	cout << ans[0] << ' ' << ans[1] << endl;
	return 0;
}
