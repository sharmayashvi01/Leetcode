class Solution {
public:
    bool is_palin(string str){
        int n=str.size();
        int i=n/2,j=i;
        if(n%2==0)
            i--;
        // cout<<"i="<<i<<" and j="<<j<<endl;
        while(i>=0 && j<=n)
        {
            if(str[i]!=str[j])
                return 0;
            i--;
            j++;
        }
        return 1;
    }
    void string_conversion(string s,string &str)
    {
        for(char ch:s)
        {
            if(ch>=97  && ch<=122)
                str+=ch;
            else if(ch>=65  && ch<=90)
                str+=ch+32;
            else if(ch>=48 && ch<=57)
                str+=ch;
        }
    }
    bool isPalindrome(string s) {
        string str="";
        string_conversion(s,str);
        // cout<<"str = "<<str<<endl;
        return is_palin(str);
    }
};