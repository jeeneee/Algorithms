#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int n = a.size();
    vector<int> prefix(n), suffix(n);
    prefix[0] = a[0];
    suffix[n - 1] = a[n - 1];
    for (int i = 1; i < n; ++i) {
        prefix[i] = min(a[i], prefix[i - 1]);
        suffix[n - i - 1] = min(a[n - i - 1], suffix[n - i]);
    }

    for (int i = 0; i < n; ++i)
        if (a[i] <= prefix[i] || a[i] <= suffix[i])
            answer++;

    return answer;
}

int main() {
    vector<int> a = { -16,27,65,-2,58,-92,-71,-68,-61,-33 };
    cout << solution(a) << endl;
    return 0;
}