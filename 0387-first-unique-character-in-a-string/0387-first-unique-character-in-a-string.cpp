class Solution {
public:
    int firstUniqChar(string s) {
        int alpha[26]={0};
        
        for(int i=0;i<s.size();i++)
        {
            int id=s[i]-'a';
            alpha[id]++;
        }
        // for(int i=0;i<26;i++)
            // cout<<alpha[i];
        
        for(int i=0;i<s.size();i++)
            if(alpha[s[i]-'a']==1)
                return i;
        return -1;
    }
};