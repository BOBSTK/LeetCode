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
 * 使用备忘录
 * **/
class Solution {
public:
    int dp(string& word1, string word2, int i, int j){
        if(i==-1) return j+1; //需要将s2[0 - j]中的字符插入 s1
        if(j==-1) return i+1; //需要将s1[0 - i]中的字符删除
        if(memo.find(i*1000+j) == memo.end()){
            if(word1[i] == word2[j]){
            return dp(word1,word2,i-1,j-1);
            }else{
                memo[i*1000+j] =  min(
                    min(dp(word1,word2,i,j-1)+1,
                    dp(word1,word2,i-1,j-1) + 1),
                    dp(word1, word2,i-1,j)+1
                );
            
            }
        }
        return memo[i*1000+j];
        
    }

    int minDistance(string word1, string word2) {
        int i = word1.size();
        int j = word2.size();
        if(i==0) return j;
        if(j==0) return i;
        return dp(word1,word2,i-1,j-1);
    }
private:
    unordered_map<int,int> memo;
};