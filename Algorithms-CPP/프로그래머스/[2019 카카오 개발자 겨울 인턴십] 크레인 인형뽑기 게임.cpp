//
//  [2019 카카오 개발자 겨울 인턴십] 크레인 인형뽑기 게임.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/28.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> v;
    for (int& j: moves) {
        for (int i = 0; i < board.size(); ++i) {
            if (board[i][j-1]) {
                if (v.empty() || v.back() != board[i][j-1])
                    v.push_back(board[i][j-1]);
                else {
                    v.pop_back();
                    answer += 2;
                }
                board[i][j-1] = 0;
                break;
            }
        }
    }
    return answer;
}
