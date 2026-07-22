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

// 排序链表 归并排序，要求 O(nlogn)时间复杂度 和 常数级空间复杂度
class Solution {
public:
    ListNode* cutList(ListNode* head, int groupSize) {
        if (head == nullptr || groupSize <= 0) return head;

        ListNode* curNode = head;
        while (--groupSize && curNode != nullptr) {
            curNode = curNode->next;
        }

        if (curNode == nullptr) return nullptr;

        ListNode* nextHead = curNode->next;
        curNode->next = nullptr;
        return nextHead;
    }

    ListNode* mergeSortList(ListNode* prevNode, ListNode* l1, ListNode* l2) {
        ListNode* tailNode = prevNode;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                tailNode->next = l2;
                l2 = l2->next;
            } else if (l2 == nullptr || l1->val <= l2->val) {
                tailNode->next = l1;
                l1 = l1->next;
            } else {
                tailNode->next = l2;
                l2 = l2->next;
            }
            tailNode = tailNode->next;
        }
        return tailNode;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode dummyHead(0, head);
        for (int groupSize = 1; ; groupSize <<= 1) {
            int mergeCount = 0;
            ListNode* prevNode = &dummyHead;
            ListNode* currHead = prevNode->next;
            while (currHead != nullptr) {
                ListNode* nextHead = cutList(currHead, groupSize);
                ListNode* restHead = cutList(nextHead, groupSize);
                prevNode = mergeSortList(prevNode, currHead, nextHead);
                currHead = restHead;
                ++mergeCount;
            }
            if (mergeCount <= 1) break;
        }
        return dummyHead.next;
    }
};