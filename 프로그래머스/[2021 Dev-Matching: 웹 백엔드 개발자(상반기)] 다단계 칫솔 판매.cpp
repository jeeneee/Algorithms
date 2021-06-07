#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, pair<string, int>> map;

void calc(string seller, int amount) {
    if (amount == 0) return;
    int fee = amount / 10;
    map[seller].second += amount - fee;
    calc(map[seller].first, fee);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for (int i = 0; i < enroll.size(); i++)
        map[enroll[i]] = {referral[i], 0};
    for (int i = 0; i < seller.size(); i++)
        calc(seller[i], amount[i] * 100);
    for (int i = 0; i < enroll.size(); i++)
        answer.push_back(map[enroll[i]].second);
    return answer;
}