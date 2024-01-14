class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        
        if(word1.size() != word2.size())
            return 0;
        
        for(int i=0;i<word1.size();i++)
        {
            int a=word1[i]-'a';
            int b=word2[i]-'a';
            
            v1[a]++;
            v2[b]++;
        }
        
        for(int i=0;i<26;i++)
        {
            if((!v1[i] && v2[i]) || (!v2[i] && v1[i]))
                return 0; 
            else continue;
        }
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        return v1==v2;  
    }
};