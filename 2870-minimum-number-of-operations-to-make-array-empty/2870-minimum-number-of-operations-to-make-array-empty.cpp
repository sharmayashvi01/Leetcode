class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int minOp=0;
        
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        
        for(auto n:mp)
        {
            int freq=n.second;
            
            if(freq==1) 
                return -1;            
            minOp += freq/3;
            if(freq%3)
                minOp++;                
        }        
        return minOp;
    }
};