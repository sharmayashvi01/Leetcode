class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        
        queue<int> q ;
        for(int i=12;i<=89;i+=11)
        {
            q.push(i);
        }
        
        while(!q.empty()){
            int num=q.front();
            q.pop();
            
            if(num>=low && num<=high)
                ans.push_back(num);
            
            int rem=num%10;
            if(rem<9){
                
                int newNum=(num*10 + (rem+1));
                    q.push(newNum);
            }
            
        }
        return ans;
    }
};