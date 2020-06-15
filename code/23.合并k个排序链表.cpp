/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = nullptr;
        for (auto vec : lists) {
            res = mergeTwoLists(res, vec);
        }
        return res;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* h = new ListNode(0);
        ListNode* head = h;
        while(l1 && l2) {
            h->next = new ListNode(0);
            h = h->next;
            if (l1->val < l2->val) {
                h->val = l1->val;
                l1 = l1->next;
            }
            else {
                h->val = l2->val;
                l2 = l2->next;
            }
        }
        if (l1) {
            while(l1) {
                h->next = new ListNode(0);
                h = h->next;
                h->val = l1->val;
                l1 = l1->next;
            }
        }
        if (l2) {
            while(l2) {
                h->next = new ListNode(0);
                h = h->next;
                h->val = l2->val;
                l2 = l2->next;
            }
        }
        return head->next;        
    }
};
// @lc code=end

