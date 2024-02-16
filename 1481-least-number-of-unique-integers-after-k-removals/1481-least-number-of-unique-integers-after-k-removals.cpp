class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int>&b){
        return a.second>b.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int num:arr)
        {
            mp[num]++;
        }
        
        vector<int>v;
        for(auto x:mp)
        {
            v.push_back(x.second);
        }
        sort(v.begin(),v.end());
        // cout<<"sorted array : ";
        // for(auto x:v)
        //     cout<<"\nfirst : "<<x;
        
        int ans=v.size();
        int i=0;
        
        while(k)
        {
            k--;
            v[i]--;
            if(v[i]==0)
            {
                i++;
                ans--;
            }
        }
        return ans;
    }
};