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
    void makeGraph(unordered_map<int,vector<int>> &adj, int parent, TreeNode* cur)
    {
        if(cur==0)
            return;
        
        if(parent != -1)
            adj[cur->val].push_back(parent);
        
        if(cur->left)
            adj[cur->val].push_back(cur->left->val);
        if(cur->right)
            adj[cur->val].push_back(cur->right->val);
        makeGraph(adj, cur->val, cur->left);
        makeGraph(adj, cur->val, cur->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        // create a adjacency list
        // convert tree into unordered graph so that it could point to its parent 
        
        
        // adj={1,{5,3}}
        unordered_map<int,vector<int>> adj;
        makeGraph(adj,-1,root);
        // adj:name of the graph , -1:parent name{root has no parent so, its -1} , root of tree   
        
        // at this point, graph is ready to traverse, use bfs, cz we are required to traverse 
        // adjcent nodes, and then these adj node will infect their adj nodes and it goes on...
        
        // bfs -> queue to store curr nodes and its adj nodes to traverse and  
        //  pop when adj are visited
        
        queue<int> q;
        unordered_set<int> v;
        int min=0;
        
        q.push(start);
        v.insert(start);
        while(!q.empty())
        {
            int n=q.size();
            
            while(n--)
            {
                int cur=q.front();
                q.pop();
                
                for(int &nbd:adj[cur]){
                    if(v.find(nbd)==v.end())
                    {
                        q.push(nbd);
                        v.insert(nbd);
                    }
                }
            }
            min++;
        }
        return min-1;
    }
};