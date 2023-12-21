class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        //        |                     |||
        // vertica| distance and vertica||| area
        //        |                     |||
        // (when pts are on the x-axis) v.d. b/w 7&7 = 0, 7&8 = 1 
        // (when pts are on the y-axis) v.d. b/t 7&7 = 0, 7&8 = 0 (dono ek hi line pr h, tyr4 vd=0, 
        //                                                         but they have a space of 1 y-unit)
        
        // toh bs kul-mila k do pts k beech ka vertical distance = x-axis ka distance

        // ques: find max x-axis diff

        vector<int> vx;
        int n=points.size();

        for(int i=0;i<n;i++)
            vx.push_back(points[i][0]);
        sort(vx.begin(),vx.end());
        int ans=0;
        for(int i=0;i<n-1;i++)
            ans=max(ans,abs(vx[i]-vx[i+1]));
        return ans;        
    }
};