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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        deque<TreeNode*> dq;
        
        if(!root)return {};
        dq.push_back(root);
        
        while(dq.size()){
            int size = dq.size();
            res.push_back(dq.back()->val);
            for(int i=0;i<size;i++){
                TreeNode* node = dq.front();
                dq.pop_front();
                
                if(node->left) dq.push_back(node->left);
                if(node->right) dq.push_back(node->right);
            }
        }
    
      return res;
  }

};