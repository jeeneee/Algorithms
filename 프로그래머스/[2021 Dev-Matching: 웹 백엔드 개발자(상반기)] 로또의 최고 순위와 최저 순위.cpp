#include <string>
#include <vector>

using namespace std;

const int score[7] = {6, 6, 5, 4, 3, 2, 1};

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zeros = 0, same = 0;
    for (auto lotto : lottos) {
        if (lotto == 0) zeros++;
        for (auto win_num : win_nums)
            if (lotto == win_num) same++;
    }

    answer.push_back(score[same + zeros]);
    answer.push_back(score[same]);
    return answer;
}