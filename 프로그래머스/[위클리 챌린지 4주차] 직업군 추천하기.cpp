#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(vector<string> table, vector<string> languages,
                vector<int> preference) {
    string answer = "";
    map<string, int> scores;

    for (int i = 0; i < languages.size(); i++) {
        scores[languages[i]] = preference[i];
    }

    int mx = 0;
    for (auto& t : table) {
        istringstream iss(t);
        string job, language;
        int sum = 0;
        iss >> job;
        for (int score = 5; score > 0; score--) {
            iss >> language;
            sum += scores[language] * score;
        }
        if (sum > mx) {
            mx = sum;
            answer = job;
        } else if (sum == mx && job < answer) {
            answer = job;
        }
    }
    return answer;
}