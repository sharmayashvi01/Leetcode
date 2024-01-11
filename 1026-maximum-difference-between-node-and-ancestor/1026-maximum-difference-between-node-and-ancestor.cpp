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
    
    // start from maxAncestorDiff() 
    // firstly we'll check abs(rootnode-all child)
    // |     therefore maxAncestorDiff()
    // |               findMaxDiff(root);
    // |     this findMaxDiff will transfer control to FindMax to calculate abs(root-all child)
    // thenafter, abs(each child of rootnode - its children)
    //      therefore findMaxDiff()
    //                 findMax(root, root->left);
    //                 findMax(root, root->right);
    int maxDiff=INT_MIN;
    
    void findMax(TreeNode* root, TreeNode* child)
    {
        if(!root || !child)
            return;
        maxDiff=max(maxDiff, abs(root->val-child->val));
        
        findMax(root, child->left);
        findMax(root, child->right);
    }
    
    void findMaxDiff(TreeNode* root)
    {
        if(!root)
            return;
        
        findMax(root, root->left);
        findMax(root, root->right);
        
        findMaxDiff(root->left);
        findMaxDiff(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        findMaxDiff(root);        
        return maxDiff;
    }
};