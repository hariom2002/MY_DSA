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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        recursion(root, res, to_string(root->val));
        return res;
    }
    void recursion(TreeNode* root, vector<string> &res, string temp){
        if(root->left ==  NULL && root->right == NULL){
          res.push_back(temp);
            temp = "";
            return;
        } 
        
       if(root->left) recursion(root->left, res, temp+ "->" + to_string(root->left->val));
       if(root->right) recursion(root->right, res, temp+ "->" + to_string(root->right->val));
    }
};