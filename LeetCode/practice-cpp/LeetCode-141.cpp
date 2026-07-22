/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// 环形链表
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head-> next) return false;

        // 一起从头结点出发，循环中先步进再判断
        ListNode* p0 = head;
        ListNode* p1 = head;
        while (p1 != nullptr) {
            p0 = p0->next;
            p1 = p1->next ? p1->next->next : nullptr;
            if (p0 == p1) {
                return true;
            }
        }
        return false;
    }
};