class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
       
        // 对于任意的右端点 right，希望找到最小的左端点left，使得[left,right] 包含不超过 K个 0
         int n = A.size();
        int left = 0, lsum = 0, rsum = 0;
        int ans = 0;
        for (int right = 0; right < n; ++right) {
            rsum += 1 - A[right]; // 更新 rsum
            while (lsum < rsum - K) {
                lsum += 1 - A[left];
                ++left; // 右移left
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};