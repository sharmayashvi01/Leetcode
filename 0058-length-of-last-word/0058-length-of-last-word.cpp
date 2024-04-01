class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int n = s.size();
        int i = n-1;
        while(i>=0)
        {
            if(s[i] != ' ') {
                // cout<<" if running";
                count++;
            }
            else if(s[i] == ' ' and count != 0) {
                // cout<<" else if running";
                return count;
            }
            i--;
        }
        // cout << "returning n";
        return count;
    }
};