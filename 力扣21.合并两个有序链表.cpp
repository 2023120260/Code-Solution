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
//一开始想用迭代法写，写了一半发现思路错了，建出来的链表有问题，看了下题解，发现递归法思路好代码又简单，先过一个递归法的，
//解法一：递归法 6ms 18MB 时间O(m+n) 空间O(m+n)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
        {
            return list2;
        }
        else if(list2 == NULL)
        {
            return list1;
        }
        else if(list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        
    }
};
