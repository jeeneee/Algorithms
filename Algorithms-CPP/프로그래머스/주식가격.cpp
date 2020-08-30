//
//  주식가격.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/08/30.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
   vector<int> answer(prices.size());
   stack<int> s;
   for (int i = 0; i < prices.size(); ++i) {
      while (!s.empty() && prices[s.top()] > prices[i]) {
         answer[s.top()] = i - s.top();
         s.pop();
      }
      s.push(i);
   }
   while (!s.empty()) {
      answer[s.top()] = prices.size() - s.top() - 1;
      s.pop();
   }
   return answer;
}

int main() {
   vector<int> prices = { 1,2,3,2,3 };
   for (auto a : solution(prices))
      cout << a << ' ';
   cout << endl;
   return 0;
}
