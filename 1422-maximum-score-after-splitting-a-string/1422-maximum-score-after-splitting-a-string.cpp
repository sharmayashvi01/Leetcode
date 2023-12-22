class Solution {
public:
    int ans=INT_MIN;
    
    int countZero(string s,int end)
    {
        int count0=0;
        for(int i=0;i<=end;i++)
            if(s[i]=='0')
                count0++;
        return count0;
    }
    
    int countOne(string s, int start, int end)
    {
        int count1=0;
        for(int i=start;i<=end;i++)
            if(s[i]=='1')
                count1++;
        return count1;
    }
    
    int maxScore(string s) {
        
        int n=s.size();
        
        for(int i=0;i<n-1;i++)
            ans=max(ans,(countZero(s,i)+countOne(s,i+1,n)));
        
        return ans;
    }
};