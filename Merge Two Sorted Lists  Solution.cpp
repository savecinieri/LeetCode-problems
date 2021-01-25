/*
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 ==  nullptr && l2 == nullptr)
        {
            return nullptr;
        }
        
        if (l1 ==  nullptr && l2 != nullptr)
        {
            return l2;
        }
        
        if (l1 !=  nullptr && l2 == nullptr)
        {
            return l1;
        }
        
        ListNode* first = l1->val <= l2->val ? l1 : l2;
        ListNode* second = first == l1 ? l2 : l1;
        ListNode* first_ = first->next;
        ListNode* result = first;

        
        /*
        std::cout << "Val in first " << first->val << " - " << first << "\n";
        std::cout << "Next first " << first->next->val << "\n";
        std::cout << "Val in second " << second->val << " - " << second << "\n";
        std::cout << "Next second " << second->next->val << "\n";
        */
        
        if (first->next == nullptr)
        {   
            first->next = second;
            return result;
        }
        
        while (second != nullptr)
        {
            if (second->val >= first->val && second->val <= first_->val)
            {
                ListNode* newFirst = second;
                ListNode* newSecond = second->next;
                
                second->next = first->next;
                first->next = second;
                
                first = newFirst;
                second = newSecond;
            }
            
            else if (second->val >= first->val && second->val > first_->val)
            {
                first = first_;
                first_ = first_->next;
                
                if (first_ == nullptr)
                {
                    first->next = second;
                    break;
                }
            }
        }
        
        return result;
    }
};
