//
//  [2019 KAKAO BLIND RECRUITMENT] 블록게임.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/11.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canFill(int row, int col, vector<vector<int>>& board) {
	for (int i = 0; i < row; ++i)
		if (board[i][col]) return false;
	return true;
}

bool findArea(int row, int col, int h, int w, vector<vector<int>>& board) {
	int zeros = 0;
	int value = -1;
	for (int i = row; i < row+h; ++i) {
		for (int j = col; j < col+w; ++j) {
			if (board[i][j] == 0) {
				if (!canFill(i, j, board)) return 0;
				if (++zeros > 2) return 0;
			} else {
				if (value != -1 && value != board[i][j]) return 0;
				value = board[i][j];
			}
		}
	}
	for (int i = row; i < row+h; ++i)
		for (int j = col; j < col+w; ++j)
			board[i][j] = 0;
	return 1;
	
}

int solution(vector<vector<int>> board) {
	int n = board.size();
    int answer = 0;
	int cnt;
	do {
		cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i+2<=n && j+3<=n && findArea(i, j, 2, 3, board)) ++cnt;
				else if (i+3<=n && j+2<=n && findArea(i, j, 3, 2, board)) ++cnt;
			}
		}
		answer += cnt;
	} while(cnt);
    return answer;
}

int main() {
	vector<vector<int>> board = {
		{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,4,0,0,0},{0,0,0,0,0,4,4,0,0,0},{0,0,0,0,3,0,4,0,0,0},{0,0,0,2,3,0,0,0,5,5},{1,2,2,2,3,3,0,0,0,5},{1,1,1,0,0,0,0,0,0,5}
	};
	cout << solution(board) << endl;
	return 0;
}
