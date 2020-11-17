class Solution {
public:
    int getDistance(int r, int c,int r0, int c0){
        return abs(r-r0) + abs(c-c0);
    }
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
         vector<vector<int>> ret;
      for(int i=0;i<R;++i)
          for(int j=0;j<C;++j){
             ret.push_back(vector<int>{i,j});
          }
	   //按照曼哈顿距离排序
       sort(ret.begin(),ret.end(),[=](vector<int>& a,vector<int>& b){
           return abs(a[0]-r0) + abs(a[1]-c0) <abs(b[0]-r0) + abs(b[1]-c0);
       });
      
      return ret;
    }
};
/*
   复杂度分析
   时间复杂度
     O(RC log(RC))
     存储所有点时间复杂度 O(RC)，
	 排序时间复杂度  O(RClog(RC))
   空间复杂度
     O(log(RC))排序需要使用的栈空间
*/