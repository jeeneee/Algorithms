#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int arr[1000][1000];
    int x = 0, y = 0, num = 1, dir = 0;
    for (int i = 0; i < n; ++i) {
        switch (dir) {
        case 0:
            for (int j = i; j < n; ++j)
                arr[x++][y] = num++;
            x--;
            y++;
            dir = 1;
            break;
        case 1:
            for (int j = i; j < n; ++j)
                arr[x][y++] = num++;
            y -= 2;
            x--;
            dir = 2;
            break;
        case 2:
            for (int j = i; j < n; ++j)
                arr[x--][y--] = num++;
            x += 2;
            y++;
            dir = 0;
            break;
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            answer.push_back(arr[i][j]);
    return answer;
}