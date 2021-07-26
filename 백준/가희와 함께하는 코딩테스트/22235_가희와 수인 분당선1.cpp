#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Train {
    int from, to, st;
};

Train trains[400];
int t[273];
int cur_time, n;

void init() {
    for (int i = 211; i < 273; i++) {
        t[i] = 2;
    }
    t[211] = t[223] = t[226] = t[239] = t[251] = t[257] = t[267] = 3;
    t[221] = t[222] = t[246] = t[250] = 4;
    t[248] = 5;

    for (int i = 211; i < 273; i++) {
        t[i] = t[i - 1] + t[i] * 60 + 20;
    }
}

int to_sec(char* s) {
    int hh, mm, ss;
    sscanf(s, "%d:%d:%d", &hh, &mm, &ss);
    return hh * 60 * 60 + mm * 60 + ss;
}

int main() {
    char from[10], to[10], str[10];
    init();
    scanf("%s", str);
    cur_time = to_sec(str);

    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%s %s %s", from, to, str);
        strcat(str, ":00");
        trains[i].from = atoi(from + 1);
        trains[i].to = atoi(to + 1);
        trains[i].st = to_sec(str);
    }

    int start[] = {225, 233, 246, 258, 272};
    for (int s = 0; s < 4; s++) {  // 정차역
        int min_t = 2e9;
        for (int i = 0; i < n; i++) {  // 각 열차 정보
            if (start[s] < trains[i].from || start[s] >= trains[i].to) continue;

            int leave_time = trains[i].st + t[start[s]] - t[trains[i].from];

            if (leave_time < cur_time) continue;

            min_t = min(min_t, leave_time);
        }
        cur_time = min_t + t[start[s + 1]] - t[start[s]] - 20;
    }

    if (cur_time >= 60 * 60 * 24) {
        printf("-1\n");
    } else {
        printf("%02d:%02d:%02d\n", cur_time / 3600, (cur_time % 3600) / 60, cur_time % 60);
    }
}
