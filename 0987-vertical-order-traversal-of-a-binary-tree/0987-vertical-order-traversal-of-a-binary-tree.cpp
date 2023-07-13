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
    map<int,map<int, multiset<int>>> map;
//     map<verticle level, map<horizontal level, elements>> 
//     we are using horizontal level to deal with those nodes which are on same verticle level and same horizontal level, so their order of insertion will help 
    vector<vector<int>> res;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        recursion(root, 0,0);   
       for (auto p : map) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(),q.second.begin(), q.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
    
    void recursion(TreeNode* root, int x, int y) {
    if (root == nullptr) return;

    map[x][y].insert(root->val);
    recursion(root->left, x - 1, y + 1);
    recursion(root->right, x + 1, y + 1);
    }

    
};