class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
       if(dungeon.size() == 0){
           return 0;
       }
       int row = dungeon.size();
       int colum = dungeon[0].size();
       vector<vector<int>> dp(row,vector<int>(colum,0));
       dp[row-1][colum-1] = max(1,1-dungeon[row-1][colum-1]); //初始化公主位置需要的最低健康点
       //初始化最后一列的dp值
       for(int i = colum-2;i>=0;i--){
           dp[row-1][i] = max(1,dp[row-1][i+1]-dungeon[row-1][i]);
       }
       //初始化最后一行对dp值
       for(int i=row-2;i>=0;i--){
           dp[i][colum-1] = max(1,dp[i+1][colum-1]-dungeon[i][colum-1]);
       }
       
       for(int i = row-2;i>=0;i--){
           for(int j = colum-2;j>=0;j--){
               int dp_min = min(dp[i+1][j],dp[i][j+1]); //计算右和下最小的dp值
               dp[i][j] = max(1,dp_min - dungeon[i][j]); //更新这一点的dp值
           }
       }
       return dp[0][0];
    }
};