// 只有 s[i+1:j-1] 是回文串，并且 s 的第 i 和 j 个字母相同时，s[i:j] 才会是回文串
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2) return s;
        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i,j]是否为回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for(int i=0;i<n;++i){
            dp[i][i] = 1;
        }
        // 递推开始
        // 枚举子串长度
        for(int L=2;L<=n;++L){
            for(int i=0;i<n;++i){
                // 由 i 和 L 可以确定右边界 j
                int j = L + i - 1;
                if(j>=n) break;  // 超出右边界
                if(s[i] != s[j]){
                    dp[i][j] = false;
                }else{
                    if(j-i < 3){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                // 更新答案
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }   
            }
        }
        return s.substr(begin, maxLen);
    }
};