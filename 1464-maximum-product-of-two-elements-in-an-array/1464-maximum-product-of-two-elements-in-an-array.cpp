class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        // priority_queue<int> pq;
        // {
        //     for (auto x:nums)
        //     {
        //         pq.push(x);
        //     }
        //     int a=pq.top();
        //     pq.pop();
        //     int b=pq.top();
        //     pq.pop();
        //     int res=((a-1)*(b-1));
        //     return res;
        // } 
        
        // the code above is successfully submitted 
        
        int largest = 0, largest2 = 0 ;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > largest)
            {
                largest2 = largest;
                largest = nums[i];
            }
            else
                largest2 = max(largest2,nums[i]);
        }
        
        cout<<"largest = "<<largest<<"   ";
        cout<<"largest2= "<<largest2<<endl;
        return ((largest-1) * (largest2-1));
    }
};