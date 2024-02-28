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
    int lastnode;
    int maxDepth=0;
    void solve(TreeNode* root,int depth)
    {
        if(!root)
            return;
        if(maxDepth<depth)
        {
            maxDepth=depth;
            lastnode=root->val;
        }
        solve(root->left,depth+1);
        solve(root->right,depth+1);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        
        solve(root,maxDepth+1);
        return lastnode;        
    }
};