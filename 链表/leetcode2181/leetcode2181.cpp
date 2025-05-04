/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        ListNode* mergeNodes(ListNode* head) {
            ListNode* tail = head;
            for (auto cur = head->next; cur->next; cur = cur->next){
                if (cur->val){
                    tail->val += cur->val;
                }else{
                    tail = tail->next;
                    tail->val = 0;
                }
            }
            tail->next = nullptr;
            return head;
            
        }
};