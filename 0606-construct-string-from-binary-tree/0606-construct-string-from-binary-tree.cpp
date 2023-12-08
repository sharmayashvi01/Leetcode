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
    string ans="";
    void construct(TreeNode* root)
    {
        if(root==0)
            return;
        ans += to_string(root->val);
        if(root->left==0 && root->right==0)
            return;
        ans += "(";
        construct(root->left);
        ans += ")";
        
        if(root->right==0)
            return ;
        ans += "(";
        construct(root->right);
        ans += ")";
    }
    string tree2str(TreeNode* root) 
    {
        construct(root);
        return ans;
    }
};