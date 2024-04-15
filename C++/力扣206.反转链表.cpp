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
//解法一：头插法-暴力 9ms 11.6MB 时间O(n) 空间O(n)
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
//解法二：头插法-优化 4ms 11.4MB 时间O(n) 空间O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* R = new ListNode;
        R->next = NULL;
        ListNode* P;
        while(head)
        {
            P = head;//新建一个指针，指向当前链表头结点。
            R->val = head->val;
            head = head->next;//交换head、R的值，head向后移动
            P->next = R;//将P所指向的空结点利用起来，作为下一轮头插法的起点。
            R = P;//R向前移动。
        }
        return R->next;
    }
};
//解法三：递归法 4ms 11.5MB 时间O(n) 空间O(n)
//研究了一下题解，原来上面写的解法就是迭代解法。下面研究下递归解法。  
//根据递归题解尝试写出来了，刚开始不理解的地方在于为什么传回指针是R而不是head。
//尝试了一下理解了，经过递归翻转之后，head指向的1会成为当前链表的最后一个结点，也就是说如果是1、2、3、4、5的话，head只会返回1。
//其他内容见注释。
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL||head->next == NULL)
        {
            return head;//如果当前指针是空指针或者当前结点的下一个结点为空（即为最后一个结点），就返回当前结点的指针。
        }
        ListNode* R = reverseList(head -> next);//经过递归最终R指针会指向最后一个结点。
        head->next->next = head;
        head -> next = NULL;//通过头指针进行当前结点和已完成翻转结点的翻转。
        //即1->2->3->4->5变为1->2->3->4<->5再变为1->2->3->4<-5。
        return R;//接上一行，返回的R指针指向的即为结点5。
    }
};
