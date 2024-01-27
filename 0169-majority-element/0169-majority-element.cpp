class Solution {
public:
    int majorityElement(vector<int>& nums) {
    // sort(nums.begin(),nums.end());   this is accepted
    // return nums[nums.size()/2];
    // }
    // MOORE VOTING ALGORITHM
        
        int count=0,candidate;
        
        for(int num:nums){
            if(count==0)
                candidate=num;
            
            if(num==candidate)
                count++;
            else
                count--;
        }
        return candidate;
    }
};