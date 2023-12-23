class Solution {
public:
    bool isPathCrossing(string path) {
        // vector to store visited points
        vector<pair<int,int>>v;
        v.push_back(make_pair(0,0));
        
        unordered_map<char,pair<int,int>> ump;
        ump['N'] = {0 ,1};
        ump['E'] = {1 ,0};
        ump['W'] = {-1,0};
        ump['S'] = {0 ,-1};
        
        for(int i=0;i<path.length();i++)
        {
            // (x,y) to store last visited pt
            int x=v[i].first;
            int y=v[i].second;
            // cout<<x<<" "<<y<<"   ";
            
            // pair p = direction k point
            pair<int,int> p = ump[path[i]];
            // cout<<p.first;
            // cout<<" "<<p.second<<" ";
            
            // pair new_pt = new visiting pointing
            pair<int,int> new_pt = make_pair((x + p.first) , (y + p.second));
            // cout<<new_pt.first;
            // cout<<" "<<new_pt.second<<" ";
            
            if ( find(v.begin(),v.end(),new_pt) != v.end() )
                return 1;
            
            else
                v.push_back(new_pt);            
            
        }
        return 0;
        
    }
};