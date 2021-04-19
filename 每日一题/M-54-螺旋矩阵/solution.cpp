class Solution {
public:
    const enum Direction{UP=0,DOWN,LEFT,RIGHT};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int row = matrix.size(); // 行  
        int col = matrix[0].size(); //列
        vector<vector<int>> visit(row,vector<int>(col));
        int state = RIGHT; //初始状态向右
        int i =0; int j=0;  // 初始位置(0,0)
        visit[i][j] = 1;
        ret.push_back(matrix[i][j]);
        bool isEnd = false;
        while(!isEnd){
            switch(state){
              // RIGHT --> DOWN --> LEFT --> UP --> RIGHT
              case RIGHT:
                if((j+1)<col && visit[i][j+1] == 0){ 
                   j += 1;
                   ret.push_back(matrix[i][j]);
                   visit[i][j] = 1;
                }else if(j+1 >= col || visit[i][j+1] == 1){   //无法继续向右
                   if(i+1>=row || visit[i+1][j] == 1){ 
                       isEnd = true;
                   }else{
                       //方向向下
                       state = DOWN;
                       i += 1;
                       ret.push_back(matrix[i][j]);
                       visit[i][j] = 1;
                   }
                }
              break;
              case DOWN:
                if(i+1<row && visit[i+1][j] == 0){
                    i += 1;
                    ret.push_back(matrix[i][j]);
                    visit[i][j] = 1;
                }else if(i+1 >= row || visit[i+1][j] == 1){ // 无法继续向下
                    if(j-1<0 || visit[i][j-1] == 1){
                        isEnd = true;
                    }else{
                        // 方向向左
                        state = LEFT;
                        j -= 1;
                        ret.push_back(matrix[i][j]);
                        visit[i][j] = 1;
                    }
                }
              break;
              case LEFT:
                if(j-1>=0 && visit[i][j-1] == 0){
                    j -= 1;
                    ret.push_back(matrix[i][j]);
                    visit[i][j] = 1;
                }else if(j-1 <0 || visit[i][j-1] == 1){ // 无法继续向左
                    if(i-1 < 0 || visit[i-1][j] == 1){
                        isEnd = true;
                    }else{
                        //方向向上
                        state = UP;
                        i -= 1;
                        ret.push_back(matrix[i][j]);
                        visit[i][j] = 1;
                    }
                }
              break;
              case UP:
                if(i-1 >=0 && visit[i-1][j] == 0){
                    i -= 1;
                    ret.push_back(matrix[i][j]);
                    visit[i][j] = 1;
                }else if(i-1 < 0 || visit[i-1][j] == 1){  // 无法继续向上
                    if(j+1>=col || visit[i][j+1] == 1){
                        isEnd = true;
                    }else{
                        // 方向向右
                        state = RIGHT;
                        j += 1;
                        ret.push_back(matrix[i][j]);
                        visit[i][j] = 1;
                    }
                }
              break;
              default:
              break;
            }
        }
        
        return ret;
    }
};