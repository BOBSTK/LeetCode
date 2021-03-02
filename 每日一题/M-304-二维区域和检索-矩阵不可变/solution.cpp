class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {

        int length = customers.size();
        int max = 0;
        int cur = 0;
        int ret = 0;
        for(int i=0;i<length;++i){
            ret += (1-grumpy[i])*customers[i];
        }
        for(int i=0;i<X;++i){
            cur += grumpy[i] * customers[i];
        }
        max = cur;
        // 滑动窗口
        // 老板在 [i,i+x]期间控制情绪
        for(int i=X;i<length;++i){
            //每滑动一格，只需要处理边界值
            cur -= grumpy[i-X]*customers[i-X];  // 左边减少
            cur += grumpy[i]*customers[i];  // 右边增加
            if(cur > max){
                max = cur;  // 更新
            }
        }
        return ret + max;
    }
};