/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        for (auto i = 0; i < k; ++ i) {
            if (temp == nullptr) {
                return head;
            }
            temp = temp->next;
        }
        ListNode* h = head;
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        for (auto i = 0; i < k; ++ i) {
            next = h->next;
            h->next = pre;
            pre = h;
            h = next;
        }
        head->next = reverseKGroup(h, k);
        return pre;
    }
};
// @lc code=end

