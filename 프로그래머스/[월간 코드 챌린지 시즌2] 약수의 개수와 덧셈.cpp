#include <string>
#include <vector>

using namespace std;

int calc(int x) {
    int sum = 0;
    for (int i = 1; i * i <= x; i++) {
        if (i * i == x)
            sum++;
        else if (x % i == 0)
            sum += 2;
    }
    return sum;
}

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++)
        answer += calc(i) % 2 == 0 ? i : -i;
    return answer;
}