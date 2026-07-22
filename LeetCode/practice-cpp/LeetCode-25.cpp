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

// K个一组翻转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* tail) {
        if (!head || !head->next) return head;

        ListNode* p0 = (tail == nullptr) ? nullptr : tail->next; // 修正原来的链表头指向尾后节点
        ListNode* p1 = head;
        while (p1 != nullptr) {
            ListNode* temp = p1->next;
            p1->next = p0;
            p0 = p1;
            p1 = temp;
            if (p0 == tail) break;
        }
        return p0;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k <= 1) return head;

        ListNode dummyHead(0, head);
        ListNode* prevNode = &dummyHead;
        ListNode* tailNode = &dummyHead;
        int counter = 0;
        while (tailNode != nullptr) {
            counter = (counter + 1) % k;
            tailNode = tailNode->next;
            if (counter == 0 && tailNode != nullptr) { // tailNode 不能是 nullptr
                ListNode* groupHead = reverseList(prevNode->next, tailNode); // 反转后头尾已经互换了
                ListNode* temp = prevNode->next;
                prevNode->next = groupHead;
                prevNode = temp;     // 更新为原先指向的节点
                tailNode = prevNode; // 反转后位置已发生变化
            }
        }
        return dummyHead.next;
    }
};