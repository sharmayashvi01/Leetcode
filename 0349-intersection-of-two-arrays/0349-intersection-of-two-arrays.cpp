class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int n1=nums1.size(), n2=nums2.size();
        int p1=0,p2=0;
        set<int>st;
        vector<int> v;
        
        while(p1<n1 && p2<n2)
        {
            if(nums1[p1]==nums2[p2])
            {    
                st.insert(nums1[p1]);
                p1++;
                p2++;
            }
            else if(nums1[p1]>nums2[p2])
                p2++;
            else 
                p1++;
        }
        for(auto x:st)
            v.push_back(x);
        return v;
    }
};