class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int n = grid.size(), m = grid[0].size();
        
        for(int row=0; row<n ;row++) {
            for(int col=0 ; col<m ;col++) {
                if(grid[row][col] == 1)
                {
                    perimeter += 4;
                    if(row>0 && grid[row-1][col] == 1) 
                        perimeter -= 2;
                    if(col>0 && grid[row][col-1] == 1)
                        perimeter -= 2;
                }
            }
        }
        return perimeter;
    }
};