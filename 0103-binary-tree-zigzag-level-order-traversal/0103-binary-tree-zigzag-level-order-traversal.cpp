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
    vector<vector<int>> res;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root == NULL)return {};
        queue<TreeNode*> q;
        q.push(root);
        
        int left_to_right = true;
        
        while(!q.empty()){

            int size = q.size();
            vector<int> temp(size, 0);
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
            
                if(left_to_right) temp[i] = node->val;  
                else temp[size-i-1] = node->val;
                
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            res.push_back(temp);
            left_to_right = !left_to_right;
        }
        return res;
    }
};