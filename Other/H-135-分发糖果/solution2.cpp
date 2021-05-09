// 常数空间
class Solution {
public:
    int candy(vector<int>& ratings) {
       int n = ratings.size();
       int inc = 1, dec = 0, pre = 1;
       int ret = 1;
       for(int i=1;i<n;++i){
           if(ratings[i]>=ratings[i-1]){
               // 非递减
               dec = 0;
               pre = ratings[i] == ratings[i-1] ? 1 : pre+1;
               ret += pre;
               inc = pre;
           }else{
               //递减
               pre = 1;
               ++dec;
               if(dec == inc){
                   ++dec;
               }
               ret += dec;
           }
       }
       return ret;
    }
};