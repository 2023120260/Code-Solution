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
