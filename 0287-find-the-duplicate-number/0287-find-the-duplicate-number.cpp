class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        vector<int> count(nums.size(),0);
        // if nums.size()=5
        // then count={0,0,0,0,0}
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }
        // is loop ne nums k ek-ek element ko read kiya h aur jo bhi nums 
        // ki us i-th index value hogi, count k usi index ki value ko +1 
        // kiya h 
        // For example  Input: nums = [1,3,4,2,2]
        // Output: 2
        // count={0,0,0,0,0}
        // i=0 -> count[nums[0]]++ = count[1]++
        //          count={0,1,0,0,0}
        // i=1 -> count[nums[1]]++ = count[3]++
        //          count={0,1,0,1,0}
        // i=2 -> count[nums[2]]++ = count[4]++
        //          count={0,1,0,1,1}
        // i=3 -> count[nums[3]]++ = count[2]++
        //          count={0,1,1,1,1}
        // i=4 -> count[nums[4]]++ = count[2]++
        //          count={0,1,2,1,1}
        // now our task is to read count and wherever we get count[i]>1
        // we have to return i
        for(int i=0;i<count.size();i++)
        {
            if(count[i]>1)
                return i;
        }
        return 0;
    }
};