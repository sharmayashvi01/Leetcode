class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2 || n==3)
            return n;
        
        int f=1;
        int s=2;
        int t;
        for(int i=3;i<=n;i++)
        {
            t=f+s;
            f=s;
            s=t;
        }
        return t;
    }
};