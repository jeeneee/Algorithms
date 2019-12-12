//
//  11279_최대 힙(Class Ver.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/12/09.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
using namespace std;

class Heap {
private:
    int *arr;
    int capacity;
    int current_size;
    
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
public:
    Heap(int capacity) : capacity(capacity), current_size(0) {
        arr = new int[capacity];
    }
    bool empty() { return current_size == 0; }
    void insert(int x) {
        if (current_size >= capacity) return;
        
        int child_pos = current_size;
        arr[current_size++] = x;
        int parent_pos = (child_pos - 1) / 2;
        
        while (arr[parent_pos] < arr[child_pos]) {
            swap(arr[parent_pos], arr[child_pos]);
            child_pos = parent_pos;
            parent_pos = (child_pos - 1) / 2;
        }
    }
    void maxHeap(int pos, bool is_sub) {
        if (pos == -1) return;
        
        int big_pos = 0;
        int left_pos = 2 * pos + 1;
        int right_pos = 2 * pos + 2;
        // 왼쪽 자식이 있다면
        if (left_pos <= current_size) {
            // 오른쪽 자식도 있다면
            if (right_pos <= current_size) {
                if (arr[left_pos] >= arr[right_pos])
                    big_pos = left_pos;
                else
                    big_pos = right_pos;
            } else
                big_pos = left_pos;
            // 자식이 부모보다 크다면
            if (arr[pos] < arr[big_pos]) {
                swap(arr[pos], arr[big_pos]);
                maxHeap(big_pos, true);
            }
        }
        // 자식이 없다면
        else return;
        if (is_sub == false)
            maxHeap(pos-1, false);
    }
    int pop() {
        // 비었으면 0 반환.
        if (empty()) return 0;
        // 최대값은 맨 앞에 있다.
        int max_value = arr[0];
        // 맨 끝의 값을 맨 앞으로 가져온다.
        arr[0] = arr[current_size-1];
        current_size--;
        // 첫 번째 원소에 대한 정렬
        maxHeap(0, false);
        return max_value;
    }
    ~Heap() {
        delete []arr;
    }
};

int main() {
    int n, x;
    scanf("%d", &n);
    Heap h(n);
    while (n--) {
        scanf("%d", &x);
        if (x == 0)
            printf("%d\n", h.pop());
        else
            h.insert(x);
    }
    return 0;
}
