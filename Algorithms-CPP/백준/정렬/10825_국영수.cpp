//
//  10825_국영수.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/11.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct student {
    string name;
    int korean;
    int english;
    int math;
} Student;

bool compare(const Student &a, const student &b) {
    if (a.korean != b.korean)
        return a.korean > b.korean;
    else if (a.english != b.english)
        return a.english < b.english;
    else if (a.math != b.math)
        return a.math > b.math;
    return a.name < b.name;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    Student *students = new Student[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> students[i].name >> students[i].korean >>
        students[i].english >> students[i].math;
    }
    
    sort(students, students + n, compare);
    
    for (int i = 0; i < n; ++i)
        cout << students[i].name << '\n';
    
    delete []students;
    return 0;
}
