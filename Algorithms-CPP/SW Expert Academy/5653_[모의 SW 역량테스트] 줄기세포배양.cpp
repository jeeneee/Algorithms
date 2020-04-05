//
//  5653_[모의 SW 역량테스트] 줄기세포배양.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/03.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: 세포가 비활성 상태로 주어지고 생명력 x시간이 지나면 활성 상태가 되어 사방으로 퍼진다. 이 과정에서
	  같은 위치로 퍼질 경우 생명력 크기에 우선 순위를 갖는다. 그런 후 다시 x시간이 흐르면 세포는 죽게 된다.
 해설: 세포가 언제 죽을지 계산하기 쉬우므로 구조체에 따로 선언하지 않았다. 활성화되고 퍼지면 그 세포는 더이상
	  볼 필요가 없게 되므로 temp벡터로 다시 복사하였다. 생명력 크기를 우선적으로 배치하기 때문에 초기 상태에서
	  미리 정렬해준다. 그 후엔 어차피 벡터이기 때문에 더이상 정렬할 필요가 없다. 그리고 이 문제에서 맵의 크기가
	  주어지지 않았는데, 최대 시간이 300시간이고 생명력 최소 수치가 1이므로 비활성->활성->죽음까지의 시간이 최소
	  2시간이 걸린다. 그러므로 map[150+50+150][150+50+150]이 필요하다.
 알고리즘: 시뮬레이션
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Cell {
	int x, y; // 위치
	int life; // 생명력
	int active; // 활성화까지 남은 시간
};
bool cmp(const Cell& a, const Cell& b) {
	return a.life > b.life;
}

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int MAX = 350; // 150 + 50 + 150
int map[MAX][MAX];
int n, m, k, ans;
vector<Cell> cell;

void spread(int t) {
	vector<Cell> temp;
	for (auto& c : cell) {
		if (c.active > 0) // 아직 비활성 상태라면 1시간을 빼고 다시 넣어준다.
			temp.push_back( {c.x, c.y, c.life, c.active-1} );
 		else if (c.active == 0) { // 활성화
			for (int i = 0; i < 4; ++i) {
				int nx = c.x + dx[i];
				int ny = c.y + dy[i];
				if (map[nx][ny] == 0) { // 더 크거나 같은 세포가 도착하기 전에
					map[nx][ny] = c.life;
					temp.push_back( {nx, ny, c.life, c.life} );
					if (t + c.life * 2 > k) ans++; // 죽음까지 2*생명력 만큼의 시간이 필요하다.
				}
			}
		}
	}
	cell = temp; // 기존 벡터로 복사
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		memset(map, 0, sizeof(map));
		cell.clear();
		ans = 0;
		scanf("%d %d %d", &n, &m, &k);
		// 초기 상태 저장
		for (int i = 150; i < n+150; ++i)
			for (int j = 150; j < m+150; ++j) {
				scanf("%d", &map[i][j]);
				int life = map[i][j];
				if (life) {
					cell.push_back( {i, j, life, life} );
					if (life * 2 > k) ans++;
				}
			}
		sort(cell.begin(), cell.end(), cmp); // 내림차 정렬
		// 1초 후부터 t초 후까지
		for (int t = 1; t <= k; ++t)
			spread(t);
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
