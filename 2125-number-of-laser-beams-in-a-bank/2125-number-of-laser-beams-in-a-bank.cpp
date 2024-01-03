class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        int prev=0;
        int n= bank.size();
        int m= bank[0].size();
        for(int i=0;i<n;i++)
        {
            int cur=0;
            for(int j=0;j<m;j++)
            {
                if(bank[i][j]=='1')
                    cur++;
            }
            ans+=cur*prev;
            if(cur!=0)
            {
                prev=cur;
            }
        }
        return ans;        
    }
};