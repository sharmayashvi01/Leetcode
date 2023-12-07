class Solution {
public:
    string largestOddNumber(string num) 
    {
        int i, n=num.size()-1;
        for(i=n;i>=0;i--)
        {
            int ch=num[i]-'0';
            //cout<<"ch = "<<ch<<"\n";
            if(ch%2!=0)
            {
                break;
            }
        }
        return num.substr(0,i+1);
    }
};