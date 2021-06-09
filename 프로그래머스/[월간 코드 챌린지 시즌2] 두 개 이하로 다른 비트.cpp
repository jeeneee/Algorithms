#include <string>
#include <vector>

using namespace std;

/*
 비트 연산
 */
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (auto number : numbers) {
        long long bit = 1;
        while (number & bit) bit <<= 1;
        answer.push_back(number + bit - (bit >> 1));
    }
    return answer;
}

/*
 이진수로 변환
 */
string toBinary(long long x) {
    string ret;
    while (x) {
        ret = to_string(x % 2) + ret;
        x >>= 1;
    }
    return ret;
}

long long toLong(string x) {
    long long ret = 0;
    long long power = 1;
    for (int i = x.size() - 1; i >= 0; i--) {
        if (x[i] == '1') ret += power;
        power <<= 1;
    }
    return ret;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (auto number : numbers) {
        if (number % 2 == 0)
            answer.push_back(number + 1);
        else {
            string bin = '0' + toBinary(number);
            int i = bin.size();
            while (i > 0)
                if (bin[--i] == '0') break;
            bin[i] = '1';
            while (i < bin.size() - 1)
                if (bin[++i] == '1') break;
            bin[i] = '0';
            answer.push_back(toLong(bin));
        }
    }
    return answer;
}
