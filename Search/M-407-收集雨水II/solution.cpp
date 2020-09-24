//方向数组 上下左右
static const int dx[] = {-1,1,0,0};
static const int dy[] = {0,0,-1,1};
class Solution {

public:
    int numIslands(vector<vector<char>>& grid) {  
       if(grid.size() == 0){
           return 0;
       }
       int isIand_num = 0;  //记录岛屿数量

       vector<vector<int>> visit; //记录访问过的地址
       for(int i=0;i<grid.size();i++){
           visit.push_back(vector<int>());
           for(int j=0;j<grid[i].size();j++){
               visit[i].push_back(0);
           }
       }

       for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[i].size();j++){
               if(visit[i][j] == 0 && grid[i][j] == '1'){
                   ++isIand_num;  //找到新岛屿
                   //DFS(grid,visit,i,j); //遍历该岛屿的所有地址
                   BFS(grid,visit,i,j);
               }
           }
       }
       
       return isIand_num;
    }

    void DFS(vector<vector<char>> &grid,
             vector<vector<int>> &visit,
             int x, int y
    ){
        visit[x][y] = 1;  //标记搜索地址
        //按照上下左右的顺序搜索
        for(int i=0;i<4;i++){
            int newx = dx[i] + x;
            int newy = dy[i] + y;
            
            //除去不和法的位置
            if(newx <0 || newx >= grid.size() || newy < 0 || newy >= grid[newx].size()){
               continue;
            }
            //如果地址是陆地且未访问过
            if(grid[newx][newy] == '1' && visit[newx][newy] == 0){ 
                DFS(grid,visit,newx,newy);
            }
        }
        
    }

    void BFS(vector<vector<char>> &grid,
             vector<vector<int>> &visit,
             int x, int y){
                 queue<pair<int,int>>Q; //BFS队列
                 //将(x,y)入队并标记
                 Q.push(make_pair(x,y)); 
                 visit[x][y] = 1;

                 while(!Q.empty()){
                     x = Q.front().first;
                     y = Q.front().second;
                     Q.pop();
                     for(int i=0;i<4;i++){
                         int newx = dx[i] + x;
                         int newy = dy[i] + y;
                         //除去不和法的位置
                       if(newx <0 || newx >= grid.size() || newy < 0 || newy >= grid[newx].size()){
                           continue;
                         }
                        //如果地址是陆地且未访问过
                       if(grid[newx][newy] == '1' && visit[newx][newy] == 0){
                          Q.push(make_pair(newx,newy));
                          visit[newx][newy] = 1;
                       }
                     }
                 }
             }
};