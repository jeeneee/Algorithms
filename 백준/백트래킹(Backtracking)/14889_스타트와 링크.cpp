//
//  14889_스타트와 링크.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/10/27.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 21
using namespace std;

int n;
int stats[MAX][MAX];
int is_used[MAX];
int ans = 1234567890;

void makeTeam(int cur_player, int cnt) {
    if (cnt == n / 2) {
        vector<int> team_start, team_link;
        for (int i = 0; i < n; ++i) {
            if (is_used[i]) team_start.push_back(i);
            else team_link.push_back(i);
        }
        int stat_start = 0, stat_link = 0;
        for (int i = 0; i < team_start.size(); ++i) {
            for (int j = i + 1; j < team_start.size(); ++j) {
                int start_x = team_start[i], start_y = team_start[j];
                int link_x = team_link[i], link_y = team_link[j];
                stat_start += stats[start_x][start_y] + stats[start_y][start_x];
                stat_link += stats[link_x][link_y] + stats[link_y][link_x];
            }
        }
        ans = min(ans, abs(stat_start - stat_link));
        return;
    }
    
    for (int i = cur_player; i < n; ++i) {
        if (!is_used[i]) {
            is_used[i] = true;
            makeTeam(i + 1, cnt + 1);
            // 백트래킹
            is_used[i] = false;
        }
        
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> stats[i][j];
    
    makeTeam(0, 0);
    
    cout << ans << endl;
    
    return 0;
}

