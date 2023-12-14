class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        int m=grid.size();      // no of rows
        int n=grid[0].size();   // no of cols
        
        vector <int> row(m,0);  // to store no of 1's in ith row
        vector <int> col(n,0);
                
        vector<vector<int>> diff(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1){
                    row[i]++;
                    col[j]++;
                }                
            }
        }
            
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                diff[i][j]=row[i] + col[j] - (n-row[i]) - (m-col[j]);
            }
        }
        return diff;
    }
};