// 二分查找 + 前缀和
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        if(n <= 1) return weights[0];
        // 确定二分查找左右边界
        int left = *max_element(weights.begin(), weights.end()); // 左边界（至少要比最大的单件物品大）
        int right = accumulate(weights.begin(),weights.end(),0); // 右边界 最多不超过所有物体的重量之和
        while(left < right){
            int mid = left + (right - left) / 2 ;
            int need = 1, cur = 0; // need 需要的天数 cur 当天运送的物体重量
            for(int weight : weights){
                if(cur + weight > mid){
                    ++need;
                    cur = 0;
                }
                cur += weight;
            }
            if(need <= D){
                right =  mid; // 保留当前mid值
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};