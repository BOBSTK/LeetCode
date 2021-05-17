/**
 * 找到满足 f(x)显然是单调递增函数
 * 找到满足f(x) = k 的最大和最小值 左右边界
 * 确定搜索区间 [0,LONG_MAX]
 * **/
class Solution {
public:
    // 返回n！后0的个数
    long trailingZeroes(long n) {
        if(n==0) return 0; // 0! = 1
        long divisor = 5;
        long ret = 0;
        while(n/divisor>0){
             n /= divisor;
             ret += n;
        }
        return ret;
    }
    int preimageSizeFZF(int k) {
        // 寻找右边界和左边界
        long left = 0, right=LONG_MAX;
        // 寻找左边界
        while(left<right){
            long mid = left + (right-left)/2;
            long temp = trailingZeroes(mid);
            if(temp >= k){
                right = mid; // 锁定左边界
            }else if(temp < k){
                left = mid+1;
            }
        }
        long left_bound = left;

        // 寻找右边界
        left = 0,right = LONG_MAX;
        while(left<right){
            long mid = left + (right-left)/2;
            long temp = trailingZeroes(mid);
            if(temp > k){
                right = mid; // 锁定左边界
            }else if(temp <= k){
                left = mid+1;
            }
        }
        return (int)(right - left_bound );
    }
};