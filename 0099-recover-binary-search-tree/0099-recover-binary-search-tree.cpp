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
    // map<int, TreeNode*> map;
    TreeNode* first=NULL, *second = NULL, *pre = NULL;
    
    void inorder(TreeNode* root){
        if(root->left)
            inorder(root->left);
       if(pre!=NULL && root->val < pre->val ){
           if(first==NULL)
               first=pre;
           second = root;
           
       }
        pre = root;
        if(root->right)
            inorder(root->right);
        
    }
    void recoverTree(TreeNode* root) {
        
        inorder(root);
        
        int temp = first->val;
        first->val=second->val;
        second->val=temp;
        
    }
};