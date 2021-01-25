/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* result = nullptr;
        int element;
        for (int i = 0; i < lists.size(); i++)
        {
            for (ListNode* node = lists[i];  node != nullptr; node = node->next)
            {
                element = node->val;
                if (result == nullptr)
                {
                    result = new ListNode(element, nullptr);
                }
                else
                {
                    ListNode* previous = nullptr;
                    bool flag = false;
                    for (ListNode* n = result; n != nullptr; previous = n, n = n->next)
                    {
                        if (element < n->val)
                        {
                            flag = true;
                            if (previous == nullptr)
                            {
                                result = new ListNode(element, result);
                            }
                            else if (previous != nullptr)
                            {
                                previous->next = new ListNode(element, previous->next);
                            }
                            break;
                        }
                    }
                    //in ultima posizione
                    if (flag == false)
                    {
                        previous->next = new ListNode(element, nullptr);
                    }
                }  
            }
            
        } // end for on the vector
        
        return result;
    }

};
