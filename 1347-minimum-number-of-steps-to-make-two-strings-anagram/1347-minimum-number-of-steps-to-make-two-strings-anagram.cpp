class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        int ans=0;
        
        for(int i=0;i<s.size();i++)
        {
            smap[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            tmap[t[i]]++;
        }
        
        for(auto &it:tmap)
        {
            char ch=it.first;
            int cnt=it.second;
            

            
            if(cnt != smap[ch]){
                if(smap[ch] > cnt) continue;
                // cout<<"comparing "<<ch<<" with "<<cnt<<" and "<<smap[ch]<<" ";
                // cout<<"ans +="<<abs(cnt-smap[ch])<<endl;
                ans += abs(cnt-smap[ch]);
            }
        }
        return ans;
    }
};