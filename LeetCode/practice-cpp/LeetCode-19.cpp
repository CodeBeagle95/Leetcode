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

// 删除链表的倒数第N个节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0) return head;

        ListNode* probeNode = head; // // 创建双指针，后面的指针先走n步
        while (n-- && probeNode != nullptr) {
            probeNode = probeNode->next;
        }
        if (n >= 0) return head;

        ListNode dummyHead = ListNode(0, head);
        ListNode* currentNode = &dummyHead;
        while (probeNode != nullptr) {
            currentNode = currentNode->next;
            probeNode = probeNode->next;
        }
        currentNode->next = currentNode->next->next;

        return dummyHead.next;
    }
};