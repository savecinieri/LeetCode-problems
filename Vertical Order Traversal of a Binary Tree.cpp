/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. 
There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    std::map<int, list<std::pair<int, int>>> x__val_y;
    int keyNumb = 0;
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        f(root, 0, 0);
        
        map<int, list<std::pair<int, int>>>::iterator it;
        int i = 0;
        vector<vector<int>> result = vector<vector<int>>(keyNumb);
        for (it = x__val_y.begin(); it != x__val_y.end(); it++)
        {
            for (std::pair<int, int> p : it->second)
            {
                result[i].push_back(std::get<0>(p));
            }
            i++;
        }
        return result;
    }
    
        
        
    void f(TreeNode* root, int x, int y)
    {
        if (root == nullptr)
            return;
        
        //cout << "Current node " << root->val << "  x y: " << x << "  " << y  << "\n";
        if (x__val_y.count(x) <= 0)
        {   // dictionary doesn't contain the key x
            
            x__val_y.insert({x, list<std::pair<int, int>>()});
            keyNumb++;
            x__val_y[x].push_back(std::make_pair(root->val, y));//add the new element
        }
        else
        {
            //
            bool inserted = false;
            std::list<std::pair<int, int>>::iterator it = x__val_y[x].begin();
            int I = 1;
            for (std::pair<int, int> p : x__val_y[x])
            {
                if (y > std::get<1>(p))
                {
                    inserted = true;
                    x__val_y[x].insert(it, std::make_pair(root->val, y));
                    break;
                }
                else if (y == std::get<1>(p))
                {
                
                    std::list<std::pair<int, int>>::iterator ite = it; 
                    ++ite;
                    if (ite!= x__val_y[x].end() && std::get<1>(*(ite)) == get<1>(p) && root->val >= std::get<0>(*(ite)))
                    { it++; continue;}
                    
                    else
                    {
                        if (root->val <= std::get<0>(p))
                        {
                            x__val_y[x].insert(it, std::make_pair(root->val, y));
                        }
                        else
                        {
                            x__val_y[x].insert(++it, std::make_pair(root->val, y));
                        }
                        inserted = true;
                        break;
                    }

                }
                it++;
            }
            
            if (inserted == false)
            {
                x__val_y[x].push_back(std::make_pair(root->val, y));
            }
        }
        
        
        f(root->left, x-1, y-1);
        
        f(root->right, x+1, y-1);
        
        return;
    }
};
