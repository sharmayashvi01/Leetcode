class Solution {
public:
    // int calcDiv(vector<vector<int>> paddedImg,int row,int col,int m,int n)
    // {
//         // cout<<"col = "<<col<<" = " <<paddedImg[row][col];
//         // cout<<"n = "<<n<<endl;
//         // in case , if mat has 1 row
//         if((m==1 && (col==0 || col+1 == n)) || (n==1 && (row==0 || row+1 == m)))
//             return 2;
//         else if((m==1 && ( col>0 && col<=n)) || (n==1 && ( row>0 && row<=m)))
//             return 3;
            
//         // for 3*3 matrix
//          //if((1st row  && (  1st col  || last col)) || last row&& ( 1st col   || last col)))
//         if((row == 0 && (col == 0 || col+1 == n)) || (row+1==m && (col == 0 || col+1 == n)))
//             return 4;
//         // else if(( 1st row|| last row||    1st col   || last col)
//         else if((row == 0 || row+1==m) || ( col == 0 || col+1==n))
//             return 6;
//         return 9;
//     }
    
//     int avg(vector<vector<int>> paddedImg,int row,int col,int m,int n)
//     {
//         //cout<<"row = "<<row<<" col = "<<col;
//         int avgPx=0;
       
//         for(int i=row-1;i<row+2;i++)
//         {
//             for(int j=col-1;j<col+2;j++){
//                 avgPx += paddedImg[i][j];
//             }
//         }
        
//         int div=calcDiv(paddedImg,row-1,col-1,m,n);
//         // cout<<avgPx<<"/"<<div<<endl;
//         return avgPx/div;
//     }
//     vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
//         int m=img.size();
//         int n=img[0].size();
        
//         // 0-padding of img
//         int row = m + 2;
//         int col = n + 2;        
//         vector<vector<int>> paddedImg( row , vector<int> (col, 0));
//         // vec (of size=row) of vec (of size = col, with each col initialised with 0) 
        
//         for(int i=1;i<row-1;i++){
//             for(int j=1;j<col-1;j++)
//             {
//                 paddedImg[i][j] = img[i-1][j-1];
//             }
//         }
        
//         //---------------------------------------------
//         // avg
        
// //         // 1*1 matrix
//         if(m==1 &&  n==1)
//            return {{1}};
        
//         for(int i=1;i<row-1;i++)
//         {
//             for(int j=1;j<col-1;j++)
//             {
//                 // cout<<paddedImg[i][j]<<" ";
//                 img[i-1][j-1] = avg(paddedImg,i,j,m,n);
//             }//cout<<endl;
//         }
//         return img;
        int get_avg(int i, int j, const vector<vector<int>> &img) {
        int sum = 0;
        int count = 0;

        for (int x = -1; x <= 1; ++x) {
            for (int y = -1; y <= 1; ++y) {
                int r_new = i + x;
                int c_new = j + y;
                if (r_new < 0 || r_new >= img.size() || c_new < 0 || c_new >= img[0].size()) {
                    continue;
                }
                sum += img[r_new][c_new];
                count++;
            }
            
        }
        return floor(sum / count);
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();
        vector<vector<int>> result(rows, vector<int>(cols));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = get_avg(i, j, img);
            }
        }

        return result;
        
    }
};