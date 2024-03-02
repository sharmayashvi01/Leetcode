class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++)
            nums[i]=nums[i]*nums[i];
        int i=end;
        while(i>-1)
        {
            if(nums[start]<=nums[end])
                ans[i--]=nums[end--];
            
            else if(nums[start]>nums[end])
                ans[i--]=nums[start++];
        }
        return ans;
    }
};