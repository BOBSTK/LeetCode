//按照Xstart升序排序
bool compare(const vector<int> &A, const vector<int> &B) {
    return A[0] < B[0];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
          if(points.size() <= 0)
             return 0;
          sort(points.begin(),points.end(),compare);
       
          int x = 1;
          int start = points[0][0], end = points[0][1]; //射击区间
          for(int i=1;i<points.size();++i){
              if(points[i][0] > end){   //如果气球开始位置大于区间结束位置,需要多射一只箭
                 ++x;
                 //更新射击区间
                 start = points[i][0];
                 end = points[i][1];

              }else {
                 //可以在当前射击区间内找到一个点同时击穿区间内所有气球
                 start = points[i][0]; 
                 if(end > points[i][1])
                   end = points[i][1];
              }
          }
          return x;
    }
};