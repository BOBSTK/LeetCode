/**
 * dp[i][j]  s1[0,...,i] --> s2[0,...,j] 的最小编辑距离
 * 状态转移
 * if(s1[i] == s2[j]){
 *   dp[i][j] = dp[i-1][j-1] // 跳过
 * }
 * else{
 *   dp[i][j] = min(
 *        dp[i][j-1] + 1, //在s1[i]后插入s2[j],此时j应该左移
 *        dp[i-1][j-1] +1, //将s1[i] 替换成 s2[j], 此时 i,j 都要左移
 *        dp[i-1][j] + 1   //将s1[i]删除，i左移
 *    )
 * }
 * dp table
 * **/
class Solution {
public:

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n==0) return m;
        if(m==0) return n;
        vector< vector<int>> dp  = vector< vector<int>> (n+1, vector<int>(m+1,0));
        // base case
        for(int i=1;i<=n;++i)
            dp[i][0] = i;
        for(int j=1;j<=m;++j)
            dp[0][j] = j;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(
                        min( dp[i][j-1]+1, dp[i-1][j-1]+1),
                        dp[i-1][j]+1
                    );
                }
            }
        }
        return dp[n][m];
    }
};