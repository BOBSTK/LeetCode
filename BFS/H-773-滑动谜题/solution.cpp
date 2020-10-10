class Solution {
public:
    

    int slidingPuzzle(vector<vector<int>>& board) {
      int m = 2,n = 3;
      string start = "";
      string target = "123450";
      //将2X3的数组转换为字符串
      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              start += (to_string(board[i][j]));
          }
      }

      //记录一维字符串的相邻索引
     vector<vector<int>> neighbor = {
        { 1, 3 },
        { 0, 4, 2 },
        { 1, 5 },
        { 0, 4 },
        { 3, 1, 5 },
        { 4, 2 }
    };

      //BFS
      
      deque<string> deq;
      unordered_set<string> visited; 
      deq.push_back(start);
      visited.insert(start);

      int step = 0; //存储结果
      while(!deq.empty()){
          int size = deq.size(); 
          for(int i=0;i<size;i++){
              //取出队列中的元素
              string cur = deq.front();
              deq.pop_front();
              //判断是否达到目标
              if(target == cur){
                  return step;
              }
              //找到当前局面中'0'的位置
              int index = 0; 
              for(;cur[index]!='0';index++);
              // 将数字 0 和相邻的数字交换位置
              for(int adj : neighbor[index]){
                  string new_board = cur;
                  //swap(new_board[adj], new_board[index]); //todo 
                  char temp = new_board[adj];
                  new_board[adj] = new_board[index];
                  new_board[index] = temp;
                  if(!visited.count(new_board)){ //防止走回头路
                      deq.push_back(new_board);
                      visited.insert(new_board);
                  }
              }
          }
          ++step;
      }


      return -1; //无法到达
    } 


};