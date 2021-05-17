/**
 * 0 ^ x = x
 * x ^ x = 0
 * 异或符合交换律和结合律
 * **/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        int n = nums.size();
        for(int x: nums){
            ret = ret ^ x;
        }
        return ret;
    }
};