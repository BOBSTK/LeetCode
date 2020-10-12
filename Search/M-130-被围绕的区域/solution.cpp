static int dx[] = {-1,1,0,0};
static int dy[] = {0,0,-1,1};
class Solution {
public:
   
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)
          return;
        int m = board.size(),n=board[0].size();  //m行n列
        vector<vector<int>> visited(m,vector<int>(n,0)); //初始化visit数组
        //把与边界相邻的O换成#
        for(int i=0;i<m;i++){
           if(i==0 || i==m-1){  //第一行和最后一行
             for(int j=0;j<n;j++){
                 if(visited[i][j]==0 && board[i][j] == 'O'){ //找到一个新的边界上的'O'
                     //dfs(i,j,visited,board);
                     bfs(i,j,visited,board);
                 }
             }   
           }else{
               for(int j=0;j<n;j+=n-1){
                   if(visited[i][j]==0 && board[i][j] == 'O'){ //找到一个新的边界上的'O'
                     //dfs(i,j,visited,board);
                     bfs(i,j,visited,board);
                 }
               }
           }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(int x,int y,vector<vector<int>>& visited,vector<vector<char>>& board){
        board[x][y] = '#'; //标记为边界'O'
        visited[x][y] = 1; //标记访问
        for(int i=0;i<4;i++){ //上下左右寻找
           int newX = x + dx[i];
           int newY = y + dy[i];
           //剔除边界值
           if(newX < 0 || newX >= board.size() || newY < 0 || newY >=board[0].size())
             continue;
           //如果是相邻的'O'且未被访问
           if(visited[newX][newY]==0 && board[newX][newY] == 'O')
             dfs(newX,newY,visited,board);//递归搜索
        }
    }

    void bfs(int x,int y,vector<vector<int>>& visited,vector<vector<char>>& board){
        queue<pair<int,int>> q; //优先队列
        visited[x][y] = 1; //标记入队
        q.push(make_pair(x,y));
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            board[x][y] = '#'; //更换记号
            q.pop();
            for(int i =0;i<4;i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                //剔除边界值
                if(newX < 0 || newX >= board.size() || newY < 0 || newY >=board[0].size())
                  continue;
                if(visited[newX][newY]==0 && board[newX][newY] == 'O'){
                    q.push(make_pair(newX,newY)); //入队
                    visited[newX][newY] = 1; //标记
                }
            }
        }

    }
};