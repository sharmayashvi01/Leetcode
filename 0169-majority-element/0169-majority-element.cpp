class Solution {
public:
    int majorityElement(vector<int>& nums) {
    // sort(nums.begin(),nums.end());   this is accepted
    // return nums[nums.size()/2];
    // }
    // MOORE VOTING ALGORITHM
        
        int count=0,candidate=nums[0];
        
        for(int i=0;i<nums.size();i++)
        {
            if(count==0){
                candidate=nums[i];
            }
            if(nums[i]==candidate)
                count++;
            else
                count--;
        }
        return candidate;
    }
};