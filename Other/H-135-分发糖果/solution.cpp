// 两次遍历
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n==1) return 1;
        vector<int> left(n,0);
        left[0] = 1; //第一个小孩分配1颗糖果 left[i]表示考虑左边孩子后该孩子至少应该分到的糖果数
        for(int i=1;i<n;++i){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1; // 评分更高的孩子
            }else{
                left[i] = 1; 
            }
        }
        // 考虑右侧 right表示考虑右边孩子后该孩子至少应该分到的糖果数
        int right = 0,ret = 0;

        for(int i=n-1;i>=0;--i){
            if(i < n-1 && ratings[i] > ratings[i+1]){ // 最右边一个数不用考虑右边的数
                ++right;
            }else{
                right = 1;
            }
            ret += max(left[i],right);
        }
        return ret;
    }
};