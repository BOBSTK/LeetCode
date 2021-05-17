/**
 * n & (n-1) 可以消除n最后一个1
 * n-1一定可以消除n最后一个1，并且将1后的0都变成1
 * **/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        if(n==0) return 0;
        while(n>0){
            n = n&(n-1);
            ++count;
        }
        return count;
    }
};