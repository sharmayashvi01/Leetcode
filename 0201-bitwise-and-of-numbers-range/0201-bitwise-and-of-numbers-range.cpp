class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // int ans=INT_MAX; // INT_MAX will be reprsented as 1111....32-times '1-bit'
        // for(int i=left;i<=right;i++){
        //     ans = ans&i;
        //     cout<<"ans="<<ans<<"  ";
        // }
        // return ans;
        
        // the code above is correct but issue lies lies with "left=1 and right=2147483647"
        // this testcase is giving tle
        
        int shift=0;
        
        while(left!=right)
        {
            left=left>>1;
            right=right>>1;
            shift++;
        }
        // cout<<shift;
        return (left<<shift);
    }
};