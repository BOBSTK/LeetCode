// 直接计算
// 令 x = x & (x-1) 将 x 的二进制表示的最后一个1变成0
class Solution {
public:
    int countOnes(int x){
        int count = 0;
        while(x > 0){
            x = x & (x-1);
            ++count;
        }
        return count;
    }
    vector<int> countBits(int num) {
        vector<int> ret = vector<int>(num+1);
        for(int i=0;i<=num;++i){
            ret[i] = countOnes(i);
            cout<<ret[i]<<endl;
        }
        return ret;
    }
};