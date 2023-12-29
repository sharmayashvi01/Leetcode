class Solution {
public:
    int t[301][11];
    int solve(vector<int>& jd, int n, int idx, int d){
        // if there is only 1 day left, then all jobs to be done in that one day 
        // and maxD of that day
        if(d ==1 )
        {
            int maxD=jd[idx];
            for(int i=idx;i<n;i++)
                maxD=max(maxD,jd[i]);
            return maxD;
        }
        
        if(t[idx][d] != -1)
            return t[idx][d];
        int maxD=jd[idx];
        int finalR =INT_MAX;
        // try one by one all possilbility
        // take index = [idx] job in 1st day
        // take index = [idx,idx+1] job in 1st day
        // take index = [idx,idx+1, idx+2] job in 1st day
        // ...................
        // ...................
        // so on
        
        // then find the optimal one among all the results
        
        for(int i=idx;i<=n-d;i++)
        {
            maxD=max(maxD,jd[i]);
            int result= maxD + solve(jd, n, i+1, d-1);
            
            finalR=min(finalR, result);
        }
        return t[idx][d]=finalR;
        
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n=jd.size();
        
        if(n < d)
            return -1;
        memset(t,-1,sizeof(t));
        return solve(jd, n, 0, d);
        
    }
};