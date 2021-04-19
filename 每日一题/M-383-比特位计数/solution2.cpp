// 动态规划
// 最高比特位(2的整数幂)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret = vector<int>(num+1);
        int highBit = 0;
        ret[0] = 0;
        for(int i=1;i<=num;++i){
            if((i&(i-1)) == 0){
                // 更新最高比特位
                highBit = i;
            }
            ret[i] = ret[i-highBit]+1;
        }
        return ret;
    }
};