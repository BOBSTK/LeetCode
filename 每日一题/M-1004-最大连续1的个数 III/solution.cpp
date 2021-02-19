class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
       
        // 对于任意的右端点 right，希望找到最小的左端点left，使得[left,right] 包含不超过 K个 0
        int n = A.size();
        vector<int> p(n+1);  // 前缀和数组
        for(int i=1;i<=n;++i){
            p[i] = p[i-1] + (1 - A[i-1]);  // 前缀和整体右移1位 此时下标 = 
        }
        int ans = 0;
        for(int right =0; right<n; ++right){
             int left = lower_bound(p.begin(), p.end(), p[right + 1] - K) - p.begin(); //找到最小的满足要求的left 二分法
             ans = max(ans, right - left + 1);
        }
        return ans;
    }
};