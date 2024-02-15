class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long sum=nums[0]+nums[1];
        long long ans=-1;
        
        for(int i=2;i<n;i++){
            if(nums[i]<sum)
                ans=sum+nums[i];
            sum+= nums[i];
        }     
        return ans;
    }  
    // testcase to try
    // [1,2,3,4,5,100,120,130,150,170]
    // [5,5,5]
    // [1,12,1,2,5,50,3]
    // [5,5,50]
    // [1,5,1,5]
    // [1,5,1,6]
};