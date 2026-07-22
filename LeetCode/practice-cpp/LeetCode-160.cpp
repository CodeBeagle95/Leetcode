/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 相交链表 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode *p1 = headA, *p2 = headB;
        while (p1 != p2) { // 不相交链表最终会同时变为 nullptr
            p1 = (p1 == nullptr)? headB : p1->next;
            p2 = (p2 == nullptr)? headA : p2->next;
        }
        return p1;
    }
};