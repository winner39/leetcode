#pragma once
#include "dependencies.h"
class LRUCache {//16:34-17:52
public:
    class Node {
    public:
        int key;
        int value;
        Node* pre;
        Node* next;
        Node() {}
        Node(int a, int b, Node* pre_) :key(a), value(b), pre(pre_) {}
    };
    unordered_map<int, Node*> loginfo;
    Node* front, * back;
    int maxCapacity, curSize = 0;
    LRUCache(int capacity) {
        maxCapacity = capacity;
        front = new Node();
        back = front;
    }

    int get(int key) {
        if (loginfo.find(key) != loginfo.end()) {
            MoveToBack(loginfo[key]);
            return back->value;
        }
        else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (loginfo.find(key) == loginfo.end()) {
            back->next = new Node(key, value, back);
            back = back->next;
            loginfo[key] = back;
            curSize++;
        }
        else {
            MoveToBack(loginfo[key]);
            back->value = value;
        }
        if (curSize > maxCapacity) {
            MoveFront();
            curSize--;
        }
    }

    void MoveToBack(Node* cur) {
        if (cur == back) {
            return;
        }
        else {
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
            back->next = cur;
            cur->pre = back;
            cur->next = nullptr;
            back = back->next;
        }
    }

    void MoveFront() {
        Node* temp = front->next;
        front->next = front->next->next;
        front->next->pre = front;
        loginfo.erase(temp->key);
    }
};

void test() {
    LRUCache lruCache(2);
    lruCache.put(2, 1);
    lruCache.put(2, 2);
    lruCache.get(2);

    lruCache.put(1, 1);
    lruCache.put(4, 1);
    cout <<lruCache.get(2);
    /*["LRUCache", "put", "put", "get", "put", "put", "get"]
    [[2], [2, 1], [2, 2], [2], [1, 1], [4, 1], [2]]*/
}