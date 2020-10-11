class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
       if(strs.size()<1)
         return 0;
       int size = strs.size(); //背包容量
       vector<vector<int>> dp (m+1,vector<int>(n+1,0));
  
       for(int i=1;i<=size;i++){
           vector<int> cost = countZeroAndOne(strs[i-1]);
           int zero = cost[0];
           int one = cost[1]; 
           for(int j=m;j>=zero;j--){
               for(int k=n;k>=one;k--){
                   dp[j][k] = max(dp[j-zero][k-one]+1,dp[j][k]);
               }
           }
       }
       return dp[m][n]; 
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