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
//把C++捡回来写的第一道题，用的头插法暴力解了，可以优化很多，但是先交了。
//后面再想进阶
//进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* R = new ListNode;
        R->next = NULL;
        while(head)
        {
            ListNode* P = R;
            R->val = head->val;
            head = head->next;
            R = new ListNode;
            R->next = P;
        }
        return R->next;
    }
};
