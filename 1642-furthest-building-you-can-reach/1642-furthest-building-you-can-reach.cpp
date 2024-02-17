class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        int max_brick=0;
        int n=heights.size();
        // cout<<"n="<<n<<endl;
        priority_queue<int> pq;
        int i=0;
        for(;i<n-1;i++)
        {
            
            if(heights[i+1]<=heights[i]){
                // cout<<"i="<<i<<"   if_running"<<endl;
                continue;                
            }
            int diff=heights[i+1]-heights[i];
            if(bricks>=diff){                
                bricks-=diff;
                pq.push(diff);
            }
            else if(ladders>0)
            {    
                if(!pq.empty())
                {
                    max_brick=pq.top();
                    if(diff < max_brick)
                    {
                        pq.pop();
                        bricks += max_brick;
                        bricks -= diff;
                        pq.push(diff);
                    }                   
                }
                ladders--;
            }
            else
                break;
            // cout<<"i="<<i<<" else_running bricks="<<bricks<<" ladders="<<ladders<<endl;
            
        }
        return i;
    }
};