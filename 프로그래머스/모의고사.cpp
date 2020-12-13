//
//  모의고사.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/01/09.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<vector<int>> students({
        vector<int>({1, 2, 3, 4, 5}),
        vector<int>({2, 1, 2, 3, 2, 4, 2, 5}),
        vector<int>({3, 3, 1, 1, 2, 2, 4, 4, 5, 5})
    });
    
    vector<int> res(3, 0);
    int max_res = 0;
    for (int i = 0; i < 3; ++i) {
        int len = (int)students[i].size();
        for (int j = 0; j < answers.size(); ++j) {
            if (students[i][j % len] == answers[j])
                ++res[i];
        }
        max_res = max(max_res, res[i]);
    }
    
    vector<int> ret;
    for (int i = 0; i < 3; ++i) {
        if (res[i] == max_res)
            ret.push_back(i+1);
    }
    return ret;
}

int main() {
    vector<vector<int>> answers({
        vector<int>({1, 2, 3, 4, 5}),
        vector<int>({1, 3, 2, 4, 2})
    });
    
    vector<int> ans;
    
    for (int i = 0; i < answers.size(); ++i) {
        ans = solution(answers[i]);
        cout << '[';
        for (int j = 0; j < ans.size(); ++j) {
            cout << ans[j];
            if (j+1 != ans.size())
                cout << ',';
        }
        cout << ']' << endl;
    }
    return 0;
}
