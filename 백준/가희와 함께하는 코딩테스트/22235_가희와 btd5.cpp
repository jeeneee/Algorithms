#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Fraction {
    int num, deno;
    Fraction(int _num, int _deno) : num(_num), deno(_deno) {}
    bool operator==(const Fraction& rhs) const {
        return num == rhs.num && deno == rhs.deno;
    }
    struct Hash {
        size_t operator()(const Fraction& rhs) const {
            size_t num_hash = hash<int>()(rhs.num);
            size_t deno_hash = hash<int>()(rhs.deno) << 1;
            return num_hash ^ deno_hash;
        }
    };
};

inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<Fraction, vector<int>, Fraction::Hash> balloons;
    unordered_map<Fraction, long long, Fraction::Hash> damage;
    unordered_map<Fraction, int, Fraction::Hash> nums;

    int n, m, x, y, z, h, d;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> h;
        z = gcd(abs(x), abs(y));
        balloons[Fraction(x / z, y / z)].push_back(h);
    }

    for (auto& b : balloons) {
        sort(b.second.begin(), b.second.end());
    }

    int cnt = n;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> d;
        z = gcd(abs(x), abs(y));
        Fraction f = Fraction(x / z, y / z);
        auto& v = balloons[f];
        if (!v.empty()) {
            damage[f] += d;
            auto popped = upper_bound(v.begin(), v.end(), damage[f]) - v.begin();
            cnt -= popped - nums[f];
            nums[f] = (int)popped;
        }
        cout << cnt << '\n';
    }

    return 0;
}
