//
//  1406_에디터.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2019/11/12.
//  Copyright © 2019 장우진. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    char data;
    Node *prev;
    Node *next;
};

struct Node *head;
struct Node *tail;
struct Node *cur;

void init() {
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
    tail->next = nullptr;
    cur = tail;
}

void moveLeft() {
    if (cur->prev != head)
        cur = cur->prev;
}

void moveRight() {
    if (cur->next != nullptr)
        cur = cur->next;
}

void deleteElement() {
    if (cur->prev != head) {
        struct Node *toDel = cur->prev;
        cur->prev = toDel->prev;
        toDel->prev->next = cur;
        delete toDel;
    }
}

void insertElement(const char new_data) {
    struct Node *newNode = new Node;
    newNode->prev = cur->prev;
    newNode->next = cur;
    newNode->data = new_data;
    cur->prev->next = newNode;
    cur->prev = newNode;
}

const void displayList() {
    head = head->next;
    while (head->next != nullptr) {
        cout << head->data;
        head = head->next;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    char s[100001], cmd, letter;
    cin >> s;
    // Initialize
    init();
    for (int i = 0; s[i] != 0; ++i) {
        insertElement(s[i]);
    }
    cin >> n;
    while (n--) {
        cin >> cmd;
        switch (cmd) {
            case 'L':
                moveLeft();
                break;
            case 'D':
                moveRight();
                break;
            case 'B':
                deleteElement();
                break;
            case 'P':
                cin >> letter;
                insertElement(letter);
                break;
        }
    }

    displayList();
    return 0;
}
