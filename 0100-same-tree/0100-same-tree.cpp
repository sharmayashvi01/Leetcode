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
    void check(TreeNode* p,TreeNode* q, bool &ans)
    {
        if(!ans)
            return;
        if((!p) && (!q))
            return;
        if((!p && q) || (p && !q) || ((p->val)!=(q->val)))
        {
            ans=0;
            return;
        }
        
        if((p->val)==(q->val)){
            check(p->left,q->left,ans);
            check(p->right,q->right,ans);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans= true;
        check(p,q,ans);
        return ans;
    }
};