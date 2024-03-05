class Solution {
public:
    int minimumLength(string s) {
        int i=0, j=s.size()-1;
//         while(i<j)
//         {
//             char c=s[i];
//             if(s[j]==c)
//             {
//                                 // cout<<"i="<<i <<" j="<<j<<"     j-i+1="<<j-i+1<<endl;

//                 while(s[j]==c && i<j)
//                     j--;
//                 while(s[i]==c && i<j)
//                     i++; 
                
//             }
//             else 
//             { 
//                 // cout<<"return i="<<i <<" j="<<j<<endl;
//                 return j-i+1;
//             }
                
        while(i<j and s[i]==s[j])
        {
            char c=s[i];
            while(i<j and s[i]==c)
                i++;
            while(i<=j and s[j]==c)
                j--;
        }
        return j-i+1;
    }
};