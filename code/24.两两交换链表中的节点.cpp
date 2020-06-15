/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <bits/stdc++.h>

#ifndef LISTNODE_H
#define LISTNODE_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
#endif // !LISTNODE_H

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *h = new ListNode(-1);
        h->next = head;
        ListNode *h1 = h;
        while(h->next) {
            if (h->next->next == nullptr)
                break;
            ListNode *t1 = h->next;
            ListNode *t2 = h->next->next;
            h->next = t1->next;
            t1->next = t2->next;
            t2->next = t1;
            h = t1;
        }
        return h1->next;
    }
};
// @lc code=end

