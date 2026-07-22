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

// 反转链表
// null    1 -> 2 -> 3
// null <- 1    2 -> 3
// null <- 1 <- 2    3
// null <- 1 <- 2 <- 3
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* p0 = nullptr;
        ListNode* p1 = head;

        while (p1 != nullptr) { // 修改 p0 和 p1 之间的指向 
            ListNode* pt = p1->next;
            p1->next = p0;
            p0 = p1;
            p1 = pt;
        }
        return p0;
    }
};