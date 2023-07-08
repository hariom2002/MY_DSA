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
class Solution
{
public:
    unordered_map<TreeNode *, int> mp;
    int rob(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        auto ans = dfs(root);
        return max(ans.first, ans.second);
    }
    pair<int, int> dfs(TreeNode *root)
    {
        if (root == NULL)
            return {0, 0};
        auto [leftnotrob, leftrob] = dfs(root->left);
        auto [rightnotrob, rightrob] = dfs(root->right);
        int notrob = max(leftnotrob, leftrob) + max(rightnotrob, rightrob);
        int rob = root->val + leftnotrob + rightnotrob;
        return {notrob, rob};
    }
};