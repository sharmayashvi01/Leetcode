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
    void traverse(TreeNode* root, vector<int> &v)
    {
        if(root==NULL)
            return;
        traverse(root->left,v);
        traverse(root->right,v);
        if(root->left==NULL && root->right==NULL)
            v.push_back(root->val);
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        traverse(root1,v1);
        traverse(root2,v2);
        return v1==v2;
    }
};