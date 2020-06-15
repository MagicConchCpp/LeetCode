/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* l1 = new ListNode(-1);
        l1->next = head;
        ListNode* l2 = l1;
        ListNode* h = l2;
        for (auto i = 0; i < n; ++ i) {
            l1 = l1->next;
        }
        while (l1->next) {
            l1 = l1->next;
            l2 = l2->next;
        }
        l2->next = l2->next->next;
        return h->next;
    }
};
// @lc code=end

