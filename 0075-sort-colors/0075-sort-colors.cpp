class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z_ind=0, t_ind=nums.size()-1;
        
        for(int i=0;i<nums.size();i++)
        {   
            // if(nums[i]==1)
                // continue;
            if(nums[i]==0 && i!=z_ind )
                swap(nums[i--],nums[z_ind++]);
            
            if(nums[i]==2 && i<t_ind )
                swap(nums[i--],nums[t_ind--]);
            
            // cout<<"i="<<i+1<<" z_ind="<<z_ind <<" t_ind="<<t_ind<<"  ";
            // for(int j=0;j<nums.size();j++)
                // cout<<nums[j]<<"  ";
            // cout<<endl;
        }
    }
};