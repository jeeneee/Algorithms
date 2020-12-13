//
//  [2018 KAKAO BLIND RECRUITMENT] 셔틀버스.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/04/29.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> time;
    int ans = 540;
    for (auto& t : timetable) {
        int temp = 0;
        temp += 600 * (t[0] - '0') + 60 * (t[1] - '0');
        temp += 10 * (t[3] - '0') + t[4] - '0';
        time.push_back(temp);
    }
    sort(time.begin(), time.end());
    
    int crew = 0, now = 540;
    for (int bus = 0; bus < n; ++bus) {
        int num = 0;
        for (int i = crew; i < time.size(); ++i) {
            if (time[i] <= now) {
                ++crew;
                ++num;
            }
            if (num == m) break;
        }
        if (bus == n-1) {
            if (num == m) ans = time[crew-1]-1;
            else ans = now;
        }
        now += t;
    }
    int hrs = ans / 60, mins = ans % 60;
    cout << hrs << ' ' << mins << endl;
    if (hrs < 10) answer += "0";
    answer += to_string(hrs);
    answer += ':';
    if (mins < 10) answer += "0";
    answer += to_string(mins);
    return answer;
}
