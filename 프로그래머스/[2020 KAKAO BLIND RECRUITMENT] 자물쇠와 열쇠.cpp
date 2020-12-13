//
//  [2020 KAKAO BLIND RECRUITMENT] 자물쇠와 열쇠.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/11.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int keySize, lockSize, boardSize;

void rotateKey(vector<vector<int>>& key) {
	vector<vector<int>> temp(keySize, vector<int>(keySize));
	for (int j = keySize-1; j >= 0; --j)
        for (int i = 0; i < keySize; ++i)
            temp[i][j] = key[keySize-j-1][i];
	key = temp;
}

bool putKey(int row, int col,
			vector<vector<int>> key, vector<vector<int>> board) {
	for (int i = row; i < row+keySize; ++i)
		for (int j = col; j < col+keySize; ++j)
			board[i][j] += key[i-row][j-col];
	for (int i = keySize-1; i <= boardSize-keySize; i++)
		for (int j = keySize-1; j <= boardSize-keySize; j++)
			if (board[i][j] != 1) return 0;
	return 1;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	keySize = key.size();
	lockSize = lock.size();
	boardSize = lockSize + (keySize-1) * 2;
	
	vector<vector<int>> board(boardSize, vector<int>(boardSize, 0));
	for (int i = keySize-1; i <= boardSize-keySize; i++)
		for (int j = keySize-1; j <= boardSize-keySize; j++)
			board[i][j] = lock[i-keySize+1][j-keySize+1];
	
	for (int k = 0; k < 4; ++k) {
		for (int i = 0; i <= boardSize-keySize; ++i) {
			for (int j = 0; j <= boardSize-keySize; ++j) {
				if (putKey(i, j, key, board)) return 1;
			}
		}
		rotateKey(key);
	}
	return 0;
}

int main() {
	vector<vector<int>> key = {
		{0, 0, 0},
		{1, 0, 0},
		{0, 1, 1}
	};
	vector<vector<int>> lock = {
		{1, 1, 1},
		{1, 1, 0},
		{1, 0, 1}
	};
	cout << solution(key, lock) << endl;
	return 0;
}
