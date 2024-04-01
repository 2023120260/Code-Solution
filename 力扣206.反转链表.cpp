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
//解法一：头插法-暴力 9ms 11.6MB
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
            R = new ListNode;//新建了一个链表，感觉可以优化一下，节省点空间
            R->next = P;
        }
        return R->next;
    }
};
//解法二：头插法-优化 4ms 11.4MB
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* R = new ListNode;
        R->next = NULL;
        ListNode* P;
        while(head)
        {
            P = head;
            R->val = head->val;
            head = head->next;
            P->next = R;
            R = P;
        }
        return R->next;
    }
};
//研究了一下题解，原来上面写的解法就是迭代解法。下面研究下递归解法。
