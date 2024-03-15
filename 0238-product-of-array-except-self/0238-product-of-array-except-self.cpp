// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n=nums.size(),pro;
//         vector<int>ans;
//         for(int i=0;i<n;i++)
//         {
//             pro=1;
//             for(int j=0;j<n;j++)
//             {
//                 if(i==j)
//                     continue;
//                 pro*=nums[j];
//             }
//             ans.push_back(pro);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> output;
        // for(int i=0; i<n; i++){
        //     int product = 1;
        //     for(int j=0; j<n; j++){
        //         if(i == j) continue;
        //         product *= nums[j];
        //     }
        //     output.push_back(product);
        // }
        // return output;
        // ye upar ke dono code same h
        
        // to approach yeh h hm do vector lenge,
        // ek vector jo ki input vector k elemnts le left ka product stroe karega
        // aur dusra right ka 
        
        int n=nums.size();
        vector<int> left(n,1),right(n,1);
        
        // left.push_back(1);

        for(int i=1;i<n;i++){
            left[i] = left[i-1]*nums[i-1];
            right[n-i-1]=right[n-i]*nums[n-i];
        }
        vector<int> result(n);
        for(int i=0;i<n;i++)
            result[i]=left[i]*right[i];
        
        return result;
        
    }
};