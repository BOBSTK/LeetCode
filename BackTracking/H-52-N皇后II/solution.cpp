class Solution {
public:
 vector<vector<string>> res; //存储结果
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
       backtrack(board,0);
       return res.size();
    }

    // 路径：board 中小于 row 的那些行都已经成功放置了皇后
    // 选择列表：第 row 行的所有列都是放置皇后的选择
    // 结束条件：row 超过 board 的最后一行
    void backtrack( vector<string> &board, int row){
       //结束条件
       if(row >= board.size())
         {
             res.push_back(board);
             return;
         }
        int n = board[row].size();//一行有n列
        //尝试在每个位置放置皇后
        for(int col =0;col<n;col++){
          if(!isValid(board,row,col))//不能在当前位置放置皇后
             continue;
          board[row][col] = 'Q'; //放置皇后
          backtrack(board,row+1); //进入下一决策
          board[row][col] = '.'; //撤销选择尝试在其他位置放置皇后       
        }
    }

    // //判断在第row行col列放置皇后是否合法(皇后尚未放置)
    bool isValid(vector<string> &board,int row,int col){
       //判断该列有没有其他皇后
       int n = board.size();
       for(int i = 0;i<n;i++){
           if(board[i][col] == 'Q')
            return false;
       }
       //判断左上没有其他皇后
       for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
             if(board[i][j] == 'Q')
             return false;
       }
       //判断右上没有其他皇后
       for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
             if(board[i][j] == 'Q')
             return false;
       }
       return true;
    }
};