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

// 两两交换链表中的相邻节点
// 1.递归: 时间复杂度 O(n), 空间复杂度 O(n)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* p0 = head;
        ListNode* p1 = head->next;
        ListNode* p2 = swapPairs(p1->next);

        p1->next = p0;
        p0->next = p2;
        return p1;
    }
};

// 2. 迭代: 时间复杂度 O(n), 空间复杂度 O(1)
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

// 两两交换链表中的节点
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* p0 = head;
        ListNode* p1 = head->next;
        ListNode* p2 = p1->next;
        head = p1; // 指定新的链表头
        
        while (p0 != nullptr && p1 != nullptr) {
            p1->next = p0;
            p0->next = p2;
            p0 = p2;
            p1 = (p0 == nullptr) ? nullptr : p0->next;
            p2 = (p1 == nullptr) ? nullptr : p1->next;
        }

        return head;
    }
};