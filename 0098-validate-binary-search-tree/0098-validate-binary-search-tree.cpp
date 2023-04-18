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
// class Solution {
// public:
// //     vector<int> vect;
    
// //     void recursion(TreeNode* root) {
// //         if(root->left) 
// //             recursion(root->left);
// //         vect.push_back(root->val);
// //         if(root->right)
// //             recursion(root->right);
        
//     }
//     bool isValidBST(TreeNode* root) {
//        recursion(root);
        
// //         if(unordered_set<int> (vect.begin(), vect.end()))
// //         return is_sorted(vect.begin(),vect.end());
        
//     }
// };
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};