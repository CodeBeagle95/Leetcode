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

// 回文链表 1-> 2 -> 3 -> 3 -> 2-> 1 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* p0 = nullptr;
        ListNode* p1 = head;

        while(p1 != nullptr) {
            ListNode* temp = p1->next;
            p1->next = p0;
            p0 = p1;
            p1 = temp;
        }
        return p0;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* p0 = head; // 快指针
        ListNode* p1 = head; // 慢指针
        ListNode* pm = head; // 记录中间节点
        while (p0 != nullptr) {
            pm = p1;
            p1 = p1->next;
            p0 = (p0->next == nullptr) ? nullptr : p0->next->next;
        }

        // 此时 p0 为 nullptr, p1 为后半段链表头, 翻转后半段链表
        p0 = head;
        p1 = reverseList(p1);
        bool isPalindrome = true;
        while (p1 != nullptr) {
            if (p0->val != p1->val) {
                isPalindrome = false;
                break;
            }
            p0 = p0->next; // 记得步进节点
            p1 = p1->next; // 记得步进节点
        }

        // 恢复后半段链表
        p1 = reverseList(pm->next);
        pm->next = p1;

        return isPalindrome;
    }
};