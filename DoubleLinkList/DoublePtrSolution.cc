#include <iostream>

//单链表倒数第K个节点
//只遍历一次链表
class Solution {
public:
    //Definition for singly-linked list.
    struct ListNode {
            int val;
            ListNode *next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *findFromEnd(ListNode *head, int k) {
        ListNode *p1 = head, *p2 = head;
        for (int i = 0; i < k; i++) {
            p1 = p1->next;
        }//p1移到k节点位置

        //p1和p2同时走了n-k步
        while (p1 != NULL)
        {
            p2 = p2->next;
            p1 = p1->next;
        }
        // p2 现在指向第 n - k + 1 个节点，即倒数第 k 个节点
        return p2;
    }
        
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *tmp = findFromEnd(dummy, n+1);
        tmp->next = tmp->next->next;
        return dummy->next;
    }
};