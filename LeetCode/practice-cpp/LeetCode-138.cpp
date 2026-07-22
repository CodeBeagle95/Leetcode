/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// 随机链表的复制
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> nodeSrcDstMap;
        stack<Node*> openLinkNodes;

        Node* dstHead = new Node(head->val);
        nodeSrcDstMap[head] = dstHead;
        openLinkNodes.push(head);

        while (!openLinkNodes.empty()) {
            Node* srcNode = openLinkNodes.top();
            openLinkNodes.pop();
            Node* dstNode = nodeSrcDstMap[srcNode];

            if (srcNode->next != NULL) {
                auto found = nodeSrcDstMap.find(srcNode->next);
                if (found == nodeSrcDstMap.end()) {
                    Node* copyNode = new Node(srcNode->next->val);
                    openLinkNodes.push(srcNode->next);
                    nodeSrcDstMap[srcNode->next] = copyNode;
                    found = nodeSrcDstMap.find(srcNode->next);
                }
                dstNode->next = found->second;
            }
            if (srcNode->random != NULL) {
                auto found = nodeSrcDstMap.find(srcNode->random);
                if (found == nodeSrcDstMap.end()) {
                    Node* copyNode = new Node(srcNode->random->val);
                    openLinkNodes.push(srcNode->random);
                    nodeSrcDstMap[srcNode->random] = copyNode;
                    found = nodeSrcDstMap.find(srcNode->random);
                }
                dstNode->random = found->second;
            }
        }
        return dstHead;
    }
};