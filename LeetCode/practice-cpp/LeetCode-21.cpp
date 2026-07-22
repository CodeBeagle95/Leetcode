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

// 合并两个有序链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummyHead(0, nullptr);
        ListNode* node = &dummyHead;

        while (list1 || list2) {
            if (list1 && !list2) {
                node->next = list1;
                list1 = list1->next;
            } else if (!list1 && list2) {
                node->next = list2;
                list2 = list2->next;
            } else if (list1->val <= list2->val) {
                node->next = list1;
                list1 = list1->next;
            } else {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }
        return dummyHead.next;
    }
};