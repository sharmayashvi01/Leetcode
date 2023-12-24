class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int o=0,z=0;
        
        for(int i=0;i<n;i++)
        {
            // for string beginning with zero
            if((i%2==0 && s[i]=='0') || (i%2!=0 && s[i]=='1'))
                z++;
            if((i%2==0 && s[i]=='1') || (i%2!=0 && s[i]=='0'))
                o++;
        }
        return min(o,z);
    }
};