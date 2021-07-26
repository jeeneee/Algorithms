#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Customer {
    int id;
    int t;
    int c;

    bool operator<(const Customer& rhs) const {
        return c > rhs.c;
    }
};

int N, M, T, W;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> T >> W;
    queue<Customer> q;
    for (int i = 0; i < N; i++) {
        int id, t;
        cin >> id >> t;
        q.push({id, t, 0});
    }

    priority_queue<Customer> waiting;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int id, t, c;
        cin >> id >> t >> c;
        waiting.push({id, t, c});
    }

    int time = 0;
    while (!q.empty() && time < W) {
        Customer customer = q.front();
        q.pop();

        int cnt = min(W - time, min(T, customer.t));
        for (int i = 0; i < cnt; i++) {
            cout << customer.id << '\n';
        }

        customer.t -= cnt;
        time += cnt;

        while (!waiting.empty() && waiting.top().c <= time) {
            q.push(waiting.top());
            waiting.pop();
        }

        if (customer.t > 0) {
            q.push(customer);
        }
    }

    return 0;
}
