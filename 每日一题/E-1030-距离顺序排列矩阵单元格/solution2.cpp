class Solution {
public:
    int getDistance(int r, int c,int r0, int c0){
        return abs(r-r0) + abs(c-c0);
    }
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
      int maxtDist = max(r0,R-1-r0) + max(c0,C-1-c0);  //最大距离
      vector<vector<vector<int>>> bucket(maxtDist+1);  //桶
      for(int i=0;i<R;++i)
        for(int j=0;j<C;++j){
            int dist = getDistance(i,j,r0,c0); //计算距离
            vector<int> tmp = {i,j};
            bucket[dist].push_back(move(tmp)); //放入桶中
        }
      //将结果按照桶中顺序放入结果集
      vector<vector<int>> ret;
      for(int i=0;i<=maxtDist;++i)
        for(int j=0;j<bucket[i].size();++j){
            ret.push_back(bucket[i][j]);
        }   
      return ret;
    }
};

复杂度分析

时间复杂度：O(RC)
  存储所有点时间复杂度 O(RC)
  桶排序时间复杂度 O(RC)

空间复杂度：O(RC)
  需要存储矩阵内所有点。
