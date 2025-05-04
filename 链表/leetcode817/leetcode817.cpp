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
        int numComponents(ListNode* head, vector<int>& nums) {
           
// 这是 unordered_set 的一个成员函数，用于向集合中 插入 一个新元素。
// emplace 的特点是它会 就地构造 (constructs in-place) 元素，对于复杂类型可能比 insert 更高效（但对于 int 这样的基本类型，差异通常可以忽略）。

// 集合行为: 因为 numsSet 是一个集合，它只存储唯一的元素。如果 num 的值 已经存在 于 numsSet 中，emplace 操作将 不会 插入任何新的元素，集合保持不变。
// 如果 num 不在集合中，它就会被添加进去。

            unordered_set<int> numsSet;
            for (int num : nums) {
                numsSet.emplace(num);
            }
            bool inSet = false;
            int res = 0;
            while (head != nullptr) {
                if (numsSet.count(head->val)) {
                    if (!inSet) {
                        inSet = true;
                        res++;
                    }
                } else {
                    inSet = false;
                }
                head = head->next;
            }
            return res;
    

        }
    };