class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int time=0;
        int ptime=0;
        
        for(int i=0;i<n;i++){
            if(i>0 && colors[i]!=colors[i-1])
                ptime=0;
            int cur=neededTime[i];
            time += min(ptime,cur);
            ptime=max(ptime,cur);
        }
        return time;
    }
};