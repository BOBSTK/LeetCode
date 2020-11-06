class Solution {
public:
    int get(int x){
        int res = 0;
        while (x) {
            res += (x % 2);
            x /= 2;
        }
        return res;
    }
    vector<int> sortByBits(vector<int>& arr) {
        //计算arr中每个数1的个数
        vector<int> bit(10001, 0);
        for (auto x: arr) {
            bit[x] = get(x); 
        }
        sort(arr.begin(),arr.end(),[&](int x,int y){
            //先根据1的位数排序
            if (bit[x] < bit[y]) {
                return true;
            }
            if (bit[x] > bit[y]) {
                return false;
            }
            //相同时按大小排序
            return x < y;
        });
        return arr;
    }
};

