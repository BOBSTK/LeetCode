// @lc code=start
#define I  1000000007
class Solution {
public:
    /**
     * dp[i][j] 移动i步后，指针停留在j的方案数量
     * dp[i][j] = dp[i-1][j] + dp[i-1][j+1] + dp[i-1][j-1] (如果j+1和j-1没有超出范围)
     * **/
    int numWays(int steps, int arrLen) {
        // 最多向右移动 min(steps/2 , arrLen-1)步
        if(steps == 1) return 1;
        int right_bound = min(steps/2, arrLen-1);
        vector<int> dp = vector<int>(right_bound+1,0);
        dp[0] = 1; // 初始值 如果不移动，位于位置0
        for(int i=1;i<=steps;++i){
            vector<int> dpPre = dp;
            for(int j=0;j<=right_bound;++j){
                if(j+1 <= right_bound) dp[j] = (dp[j]+dpPre[j+1])%I;
                if(j-1>=0) dp[j] = (dp[j]+dpPre[j-1])%I;
            }
        }
        return dp[0];
    }
};