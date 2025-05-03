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
class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* tmp = nullptr;
        while (cur)
        {
            tmp = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = head;
        while(fast && fast -> next){
            fast = fast -> next -> next;
            pre = slow;
            slow = slow -> next;
        }

        pre -> next = nullptr;

        ListNode* head1 = head;
        ListNode* head2 = reverseList(slow);
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;
        while(cur1 && cur2){
            if (cur1 -> val != cur2 -> val) return false;
            cur1 = cur1 -> next;
            cur2 = cur2 -> next;
        }
        return true;
    }
};