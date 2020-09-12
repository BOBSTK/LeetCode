struct GraphNode {
	int label; //顶点值
	std::vector<GraphNode*> neighbors; //相邻节点
	GraphNode(int x) : label(x) {};  
};

//广度优先遍历
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         std::vector<GraphNode *>graph; //邻接表
         std::vector<int> degree; //入度数组
         for(int i=0;i<numCourses;i++){
             degree.push_back(0); //初始化入度
             graph.push_back(new GraphNode(i));
         }
          for(int i=0; i<prerequisites.size();i++){
          GraphNode *begin = graph[prerequisites[i][1]];
          GraphNode *end = graph[prerequisites[i][0]];
          begin->neighbors.push_back(end); //课程2指向课程1
          ++degree[end->label]; //课程1入度++
      }
      std::queue<GraphNode*>Q;
      //将入度为0的结点放入队列
      for(int i=0;i<numCourses;i++){
          if(degree[i] == 0){
             Q.push(graph[i]); 
          }
      }
      while(!Q.empty()){
          //取出队首结点
          GraphNode *node = Q.front();
          Q.pop();
          for(int i=0;i<node->neighbors.size();i++){
              --degree[node->neighbors[i]->label]; //将结点连接的结点入度-1
              if(degree[node->neighbors[i]->label] == 0)
                  Q.push(node->neighbors[i]);{//如果出现度为0的结点，放入队列
              }
          }
      }
      for(int i=0; i<numCourses;i++){
          delete graph[i];
      }
      //如果有入度不为0的结点说明有环
      for(int i=0;i<numCourses;i++){
          if(degree[i]!=0){
              return false;
          }
      }
      return true;
    }
};