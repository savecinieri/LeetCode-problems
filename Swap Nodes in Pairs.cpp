/*
Given a linked list, swap every two adjacent nodes and return its head.
*/


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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
        
        ListNode* n = head->next;
        for (ListNode* p = head; ; )
        {
            
            //std::cout << "Prima --> " << p->val << "  " << n->val << " p: " << p << "\n";
            int tmpVal = p->val;
            int tmpVal_ = n->val;
            
            p->val = tmpVal_;
            n->val = tmpVal;
            //std::cout << "Dopo --> " << p->val << "  " << n->val << " p: " << p << "\n";
            
            p = n->next;
            if (p == nullptr)
                break;
            if (p != nullptr && p->next == nullptr)
                break;
            if (p != nullptr && p->next != nullptr)
                n = p->next;
            
        }
        std::cout << head << "\n";
        return head;
    }
};
