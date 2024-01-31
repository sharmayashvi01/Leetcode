// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) 
//     {
//         vector<int> ans(temperatures.size(),0);
//         for(int i=0;i<temperatures.size();i++)
//         {
//             int a=temperatures[i];
//             int count=1;
//             for(int j=i+1;j<temperatures.size();j++)
//             {
//                 if(a<temperatures[j])
//                 {
//                     ans[i]=count;
//                     break;
//                 }
//                 count++;
//             }
//         }
//         return ans;   
//     }
// };
// The above approach is right, but the only problem is it is exceeding the time limit And it is not suitable for the following test case.
// temperatures =
// [30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,...Pata nhi kitni baar 30 tha,31]
// Its runtime is about 2442 ms Otherwise, this approach is also right.

// the above was submitted on 9-sep-23

// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temp) 
//     {
//         int n=temp.size();
        
//         if(n==1)
//             return {0};

//         vector<int> ans;
//         stack <int> st;
//         for(int i=n-1;i>=0;i--)
//         {
//             if(st.empty()){
//                 st.push(i);
//                 continue;
//             }
//             if(temp[st.top()]>temp[i]){
//                 cout<<"running if";
//                 ans.push_back(st.top()-i);
//                 st.push(i);
//                 continue;
//             }
//             // else if(temp[st.top()]<=temp[i])
//             // {
//             //     st.pop();
//             //     st.push(i);
//             // }
//             // int count=1;
//             while(temp[st.top()]<temp[i])
//             {
//                 st.pop();
//             }
            
//             ans.push_back(st.top()-i);
//         }
//         reverse(ans.begin(),ans.end());
//         ans.push_back(0);
//         return ans;
//     }
// };

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temp)
        {
            int n=temp.size();
            stack<int> st;
            
            vector<int> ans(n);
            
            for(int i=n-1;i>=0;i--)
            {
                while(!st.empty() && temp[i]>=temp[st.top()]){
                    st.pop();
                }
                
                if(st.empty())
                {
                    ans[i]=0;
                }
                else{
                    ans[i]=st.top()-i;
                }
                st.push(i);
            }
            return ans;
        }
};