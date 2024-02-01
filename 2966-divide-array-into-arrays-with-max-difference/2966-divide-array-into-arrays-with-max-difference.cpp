class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        // why sorting is required
        // [1,3,4,8,7,9,3,5,1] and k=2, if we directly use this array then 5-1=4 > k
        // [1,1,3,3,4,5,7,8,9] and k=2, 8-9=1<k, also the difference between ant 2 adj ele is as //         // less as spossible
        for(int i=0;i<n;i+=3)
        {
            if(nums[i+2]-nums[i]>k) // if diff bt 1st and last elemnt of the grp <= k,
                                      // then the diff of other pair of elements is also < k
                return {};
            
            else
                ans.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        return ans;
    }
};