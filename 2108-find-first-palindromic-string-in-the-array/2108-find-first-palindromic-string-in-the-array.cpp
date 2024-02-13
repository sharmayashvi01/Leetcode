class Solution {
public:
    bool is_palin(string str, int length)
    {
        int i=(length-1)/2,j=i;
        if(length%2==0)
            j=i+1;
        // cout<<"string ="<<str<<" i="<<i<<" and j="<<j<<endl;
        while(i>=0 && j<length)
        {
            if(str[i]!=str[j])
                return 0;
            i--;
            j++;
        }
        return 1;
    }
    string firstPalindrome(vector<string>& words) {
                
        for(string st:words){
            int len=st.size();
            if(is_palin(st,len))
                return st;
        }
        return "";
    }
};