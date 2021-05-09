// @lc code=start
// 二分查找
class Solution {
public:
    // 第day天能否制作足够的花朵
    bool canMakeFlower(vector<int>& bloomDay,int m,int k, int day){
        int flower=0, sum=0;
        for(int i=0;i<bloomDay.size();++i){
            if(bloomDay[i]<=day){
                ++sum;  //相邻花朵加1
                if(sum == k){
                    ++flower; //制作花束
                    if(flower >= m){
                        return true;
                    }
                    sum = 0;  // 清空计数
                }
            }else{
                sum = 0; //清空计数
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long total = m*k;
        if(n < total) return -1;
        // 找到最大天数

        int left = 1,right = 0; //最多n天可以制作好足够的花束
        for(int i=0; i<n;++i){
            right = max(right,bloomDay[i]);
        }
        while(left<right){
            int mid = left + (right - left)/2;
            if(canMakeFlower(bloomDay,m,k,mid)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;

    }
};