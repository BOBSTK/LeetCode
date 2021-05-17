/**
 * 差分数组
 * **/
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ret(n);
        vector<int> diff(n);  // 差分数组，初始化为0
        int length = bookings.size();
        // 更新差分数组
        for(int i=0;i<length;++i){
            UpdateDiff(diff,bookings[i][0]-1,bookings[i][1]-1,bookings[i][2]);
        }
        // 根据差分数组得到结果
        ret[0] = diff[0]; 
        for(int i=1;i<n;++i){
            ret[i] = diff[i] + ret[i-1];
        }
        return ret;
    }
    
    // 修改差分数组，change可以为负数
    // diff[i] += change  diff[j+1] -= change
    void UpdateDiff(vector<int>& diff, int i,int j,int change){
        diff[i] += change;
        if(j+1<diff.size()){   // 如果j为数组右边界，不需要任何操作
            diff[j+1] -= change;
        }
    }
};