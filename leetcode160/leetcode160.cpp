/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while(curA != nullptr){
            lenA ++;
            curA = curA->next;
        }
        while (curB != nullpter)
        {
            lenB ++;
            curB = curB -> next;
        }

        curA = headA;
        curB = headB;

        if(lenA < lenB){
            swap(lenA, lenB);
            swap(curA, curB);
        }

        int gap = lenA - lenB;
        while (gap --)
        {
            curA = curA -> next;
        }
        while (curA != nullptr)
        {
            if(curA == curB) return curA;
            curA = curA -> next;
            curB = curB -> next;
        }
        return nullptr;
    }
};