class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
         return 0;
        vector <vector<int>> dp; //存储结果
        int row = grid.size();
        int colum = grid[0].size();
        for(int i=0;i<row;i++){
           dp.push_back(vector<int>(colum,0));
        }
        
        dp[0][0] = grid[0][0];
        for(int i=1;i<colum;i++){
            dp[0][i] = dp[0][i-1] + grid[0][i]; //第一列赋初值
        }
        for(int i = 1;i<row;i++){
              dp[i][0] = dp[i-1][0] + grid[i][0];
              for(int j =1 ;j<colum;j++){
                  dp[i][j] = min(dp[i-1][j] + grid[i][j],dp[i][j-1] + grid[i][j]);
              }
        } 
        return dp[row-1][colum-1];
       
    }
};