class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        long long ans=0;
        int count=0;
        sort(happiness.begin(), happiness.end());
        {
            int n=happiness.size()-1;
            while(k) {
                    ans += max(happiness[n--]-count, 0);
                    count++;
                    k--;
                    // cout<<"ans = "<<ans<<", count = "<<count<<", k = "<<k<<endl;
                
                }
            }
        
        return ans;
    }
};