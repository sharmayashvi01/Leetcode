class Solution {
public:
    int t[50001];
    int n;

    // find the first job jiska point >= curJob ka endPoint
    int getNextIndex(vector<vector<int>> & array, int l,int currentJobEnd)
    {
        int r=n-1;
        int res=n+1;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(array[mid][0]>=currentJobEnd){
                res=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return res;
    }
        
    int solve(vector<vector<int>> &array, int i)
    {
        if(i >= n)
            return 0;
        if(t[i] != -1)
            return t[i];
        
        int next = getNextIndex(array, i+1, array[i][1]);
        int taken = array[i][2] + solve(array, next);
        int notTaken = solve(array, i+1);
        return t[i]=max(taken,notTaken);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        
        memset(t,-1,sizeof(t));
        
        vector<vector<int>> array(n,vector<int>(3,0)); // s,e,p
        
        for(int i=0;i<n;i++)
        {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }
        
        auto comp=[&](auto &vec1, auto& vec2){
            return vec1[0]<=vec2[0];
        };
        sort(array.begin(),array.end(),comp);
        
        return solve(array, 0);
    }
};