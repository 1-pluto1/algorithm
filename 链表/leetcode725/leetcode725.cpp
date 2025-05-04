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
        vector<ListNode*> splitListToParts(ListNode* head, int k) {
            int n = 0;
            ListNode* temp = head;
            while (temp != nullptr)
            {
                n ++;
                temp = temp->next;
            }
            int quotient = n / k, remainder = n % k;
            vector<ListNode*> parts(k, nullptr);
            ListNode* cur = head;
            for (int i = 0;i < k && cur != nullptr; i++){
                parts[i] = cur;
                int partSize = quotient + (i < remainder ? 1 : 0);
                for (int j = 1; j < partSize; j++) {
                    cur = cur->next;
                }
                ListNode *next = cur->next;
                cur->next = nullptr;
                cur = next;
            }
            return parts;
        }
    };