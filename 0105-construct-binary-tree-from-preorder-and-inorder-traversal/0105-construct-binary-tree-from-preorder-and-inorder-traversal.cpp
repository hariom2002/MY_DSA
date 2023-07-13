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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
           
        unordered_map<int, int> inOrderMap;
        int size= inorder.size();
        
        for(int i=0;i<size;i++)
            inOrderMap[inorder[i]] = i;
        
       TreeNode* root =  buildTree(preorder, 0,size -1, inorder, 0, size-1, inOrderMap);
        return root;
        
    }
    
    TreeNode* buildTree(vector<int> &preorder, int preStart, int preEnd, 
                       vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &map){
        
        if(inStart > inEnd || preStart > preEnd)return NULL;
        
        TreeNode* node = new TreeNode(preorder[preStart]);
        
        int inRoot = map[node->val];
        int nodeLeft = inRoot - inStart;
        
        node->left = buildTree(preorder, preStart+1, preStart+nodeLeft, inorder,
                              inStart, inRoot -1, map);
        node->right = buildTree(preorder, preStart+nodeLeft +1, preEnd, inorder,
                              inRoot+1, inEnd, map);
        
        return node;
    }
};