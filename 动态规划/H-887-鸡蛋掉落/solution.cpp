/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start

class Solution {
    unordered_map<int, int> memo;
  
        int dp(int k, int n){
        if(memo.find(n*100+k) == memo.end()){
            int ans;
            if(n==0){
                ans = 0;
            }else if(k == 1){
                ans = n;
            }else{
                int left = 1, right = n;
                while(left+1<right){
                    int mid = (left + right) / 2;
                    int broken = dp(k - 1, mid - 1);
                    int not_broken = dp(k, n - mid);
                    if(broken<not_broken){
                        left = mid;
                    }else if(broken > not_broken){
                         right = mid;
                    }else{
                         left = right = mid;
                    }
                   
                }
                 ans = 1 + min(max(dp(k - 1, left - 1), dp(k, n - left)),
                                   max(dp(k - 1, right - 1), dp(k, n - right)));
            }
            memo[n*100+k] = ans; 
        }
        
        return memo[n*100+k];
    }
public:
    int superEggDrop(int k, int n) {
        return dp(k, n);
    }
};
// @lc code=end





