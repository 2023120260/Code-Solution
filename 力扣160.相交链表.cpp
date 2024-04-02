/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//最开始思路是创建一个数组，把链表A的值存进去，然后遍历链表B—遍历数组找重复值。
//超出时间限制了。看了看时间复杂性是O(n^2)了，
//具体对错我没再尝试。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL||headB == NULL)
        {
            return NULL;
        }
        ListNode* l = headA;
        int length = 0;
        while(l!=NULL){
            l = l->next;
            length++;
        }
        int Arr[length];
        for(int i = 0; i < length; i++){
            Arr[i] = headA->val;
            headA = headA->next;
        }
        while(headB!=NULL)
        {
            for(int i = 0; i < length; i++){
                if(headB->val == Arr[i]){
                    return headB;
                }
            }
        }
        return NULL;
    }
};
//看了看题解，有个思路和我最开始一样，但是他用了哈希集合，我不太了解什么是哈希集合，先学一下。
//解法出了问题，判例1链表交点是8，但该程序在扫描链表B时第一个5就出现在了哈希表中，直接返回5的位置了。
//搞懂了，原来哈希集合可以直接把指针地址存进去，题解里用的就是指针。改一下。
//另外题目中提到不可以改变链表原始结构，虽然判例通过了，但是还是不要改变headA和headB的地址了。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<int> hashset;
        ListNode* l = headA;
        while(l!=NULL)
        {
            hashset.insert(l->val);
            l = l->next;
        }
        while(headB!=NULL)
        {
            if(hashset.count(headB->val)>0)
            {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};
//终于搞对了
//解法一：哈希集合法 39ms 20.39MB 时间O(2n) 空间O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> hashset;
        ListNode* l = headA;
        while(l!=NULL)
        {
            hashset.insert(l);
            l = l->next;
        }
        l = headB;
        while(l!=NULL)
        {
            if(hashset.count(l))
            {
                return l;
            }
            l = l->next;
        }
        return NULL;
    }
};


