class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int n=arr.size();
        int req=n/4;
        cout<<"req = "<<req;
        int count=1;
        
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1])
                count++;
            //cout<<arr[i]<<" = "<<arr[i-1]<<" count = "<<count<<endl;
            if(count>req)
                return arr[i];
            else if(arr[i]!=arr[i-1])
                count=1;
        }
        return 1;
    }
};