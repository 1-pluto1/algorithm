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
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 第一次做的，错的有点多
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         vector<int> num1, num2;
//         ListNode* cur1 = l1;
//         ListNode* cur2 = l2;
//         while(cur1 != nullptr){
//             num1.push_back(cur1->val);
//         }
//         while (cur2 != nullptr)
//         {
//             num2.push_back(cur2->val);
//         }
//         reverse(num1.begin(), num1.end());
//         reverse(num2.begin(), num2.end());
//         int sum1 = 0, sum2 = 0;
//         for (int i = 0; i < num1.size(); i++){
//             sum1 *= 10;
//             sum1 += num1[i];
//         }

//         for (int i = 0; i < num2.size(); i++){
//             sum1 *= 10;
//             sum1 += num2[i];
//         }

//         int sum = 0;
//         sum = sum1 + sum2;
//         vector<int> digits;
        
//         while (sum > 0) {
//             digits.push_back(sum % 10);
//             sum /= 10;
//         }

        
//     }
// };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 1;
        int len2 = 1;
        ListNode* p = l1;
        ListNode* q = l2;
        while (p -> next != NULL)
        {
            len1 ++;
            p = p -> next;
        }
        while (q -> next != NULL)
        {
            len2 ++; 
            q = q -> next;
        }

        if (len1 > len2){
            for (int i = 1; i < len1 - len2; i++){
                q -> next = new ListNode(0);
                q = q -> next;
            }
        }else{
             for (int i = 1; i < len2 - len1; i++){
                p -> next = new ListNode(0);
                p = p -> next;
            }
        }

        p = l1;
        q = l2;

        bool count = false;
        ListNode* l3 = new ListNode(-1);
        ListNode* w = l3;
        int i = 0;
        while (p != NULL && q != NULL)
        {
            i = count + p -> val + q -> val;
            w -> next = new ListNode(i % 10);
            count = i >= 10 ? true : false;
            w = w -> next;
            p = p -> next;
            q = q -> next;
        }
        if(count){
            w -> next = new ListNode(1);
            w = w -> next;
        }
        return l3 -> next;
        
        
    }
};