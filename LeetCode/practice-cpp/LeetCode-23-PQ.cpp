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

// 合并K个升序链表, 普通方法遍历时间复杂度高，需要使用优先队列
class Solution {
private:
    struct Compare { // 函数对象
        bool operator()(ListNode* l1, ListNode* l2) {
            if (l1 != nullptr && l2 != nullptr) {
                return l1->val > l2->val; // 最小堆
            } else {
                return l1 != nullptr;
            }
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;\
        for (auto list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        ListNode dummyHead(0, nullptr);
        ListNode* currNode = &dummyHead;

        while (!pq.empty()) {
            currNode->next = pq.top();
            pq.pop();
            currNode = currNode->next;
            if (currNode->next != nullptr) {
                pq.push(currNode->next);
            }
        }
        return dummyHead.next;
    }
};
