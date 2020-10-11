class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
       if(strs.size()<1)
         return 0;
       int size = strs.size(); //背包容量
       vector<vector<int>> cost; //存储字符串的消耗
       for(int i=0;i<size;i++){
           cost.push_back(countZeroAndOne(strs[i]));
       }
       //dp[i][j][k]表示字符串在子区间 [0,i]能使用 j个0 和 k个1 的 字符串的最大数量 
       //第0行为空串，初始化为0  
       //int *dp = new int[size+1][m+1][n+1]{0};    
       vector<vector<vector<int>>> dp(size+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
       for(int i=1;i<=size;i++){
          for(int j=0;j<=m;j++){
              for(int k=0;k<=n;k++){
                 //复制上一行
                 dp[i][j][k] = dp[i-1][j][k];
                 //第i个字符串的消耗
                 int zero = cost[i-1][0];
                 int one = cost[i-1][1];
                 if(j>=zero && k>=one){
                     dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j-zero][k-one]+1); //选择最优解
                 }
              }
          }
       } 
       return dp[size][m][n]; 
    }


private:
    //计算字符串中0和1得个数
    vector<int> countZeroAndOne(string &str){
        int cnt = 0;
        for(int i=0;i<str.length();i++){
            if(str[i] == '0')
              ++cnt;
        }
        return vector<int> { cnt, (int)str.length()-cnt};
    }
    
};