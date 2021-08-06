#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int data) : data(data), prev(NULL), next(NULL) {}
};

struct LinkedList {
    Node* head;
    Node* tail;

    LinkedList(int n) : head(NULL), tail(NULL) { init(n); }

    void init(int n) {
        head = tail = new Node(0);
        for (int i = 1; i < n; i++) {
            Node* node = new Node(i);
            node->prev = tail;
            tail->next = node;
            tail = tail->next;
        }
    }

    Node* erase(Node* node) {
        if (node == head) {
            head = node->next;
            head->prev = NULL;
            return head;
        } else if (node == tail) {
            tail = node->prev;
            tail->next = NULL;
            return tail;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            return node->next;
        }
    }

    void insert(Node* node) {
        if (node->prev == NULL) {
            head = node;
            node->next->prev = head;
        } else if (node->next == NULL) {
            tail = node;
            node->prev->next = tail;
        } else {
            node->prev->next = node;
            node->next->prev = node;
        }
    }
};

string solution(int n, int k, vector<string> cmd) {
    string answer;
    vector<Node*> deleted;
    LinkedList* list = new LinkedList(n);
    Node* cur = list->head;
    for (int i = 0; i < k; i++) {
        cur = cur->next;
    }

    for (int i = 0; i < cmd.size(); i++) {
        switch (cmd[i][0]) {
            case 'U': {
                int cnt = stoi(cmd[i].substr(2));
                while (cnt--) {
                    cur = cur->prev;
                }
                break;
            }
            case 'D': {
                int cnt = stoi(cmd[i].substr(2));
                while (cnt--) {
                    cur = cur->next;
                }
                break;
            }
            case 'C': {
                deleted.push_back(cur);
                cur = list->erase(cur);
                break;
            }
            case 'Z': {
                if (!deleted.empty()) {
                    Node* node = deleted.back();
                    deleted.pop_back();
                    list->insert(node);
                }
                break;
            }
            default:
                break;
        }
    }

    for (int i = 0; i < n; i++) answer += 'X';
    Node* head = list->head;
    while (head != NULL) {
        answer[head->data] = 'O';
        head = head->next;
    }

    return answer;
}

int main() {
    vector<string> cmd = {"D 2", "C", "U 3", "C",   "D 4", "C",
                          "U 2", "Z", "Z",   "U 1", "C"};
    cout << solution(8, 2, cmd) << endl;
    return 0;
}