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

// 两数相加
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummyHead = ListNode(0, nullptr);
        ListNode* curNode = &dummyHead;
        bool flag = flag; // 处理好进位

        while (l1 != nullptr || l2 != nullptr || flag) {
            ListNode* newNode = new ListNode(0);
            if (l1 != nullptr) {
                newNode->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                newNode->val += l2->val;
                l2 = l2->next;
            }
            if (flag) {
                newNode->val += flag;
                flag = false;
            }
            
            if (newNode->val >= 10) {
                newNode->val -= 10;
                flag = true;
            }
            curNode->next = newNode;
            curNode = newNode;
        }
        return dummyHead.next;
    }
};