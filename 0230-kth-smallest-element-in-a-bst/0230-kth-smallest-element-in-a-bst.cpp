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
    stack<int> st;
    int dfs(TreeNode* root, int k){
        if(root == NULL)return 0;
        
        dfs(root->left,k);
        if(st.size() < k){
            st.push(root->val);
        }
        
        dfs(root->right,k);
        return st.top();
    }
    
    int kthSmallest(TreeNode* root, int k) {   
        return dfs(root, k);
    }
};