struct GraphNode {
	int label; //顶点值
	std::vector<GraphNode*> neighbors; //相邻节点
	GraphNode(int x) : label(x) {};  
};

bool DFS_graph(GraphNode* node, std::vector<int> &visit) {
	visit[node->label] = 0; //正在访问
    for(int i=0;i<node->neighbors.size();i++){
        if(visit[node->neighbors[i]->label] == -1){
            if(!DFS_graph(node->neighbors[i],visit)){
                return false;  //有环
            }
        }
        else if(visit[node->neighbors[i]->label] == 0){
            return false; //有环
        }
    }
    visit[node->label] = 1; //访问结束
    return true; 
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      std::vector<GraphNode *>graph; //邻接表
      std::vector<int> visit; //访问状态 -1没有访问 0正在访问 1已完成访问
      //创建图节点
      for(int i=0;i<numCourses;i++){
         graph.push_back(new GraphNode(i));
         visit.push_back(-1);
      }
      //连接顶点
      for(int i=0; i<prerequisites.size();i++){
          GraphNode *begin = graph[prerequisites[i][1]];
          GraphNode *end = graph[prerequisites[i][0]];
          begin->neighbors.push_back(end); //课程2指向课程1
      }
      for(int i=0;i<graph.size();i++){
          //如果当前节点没访问且遇到环
          if(visit[i] == -1 && !DFS_graph(graph[i],visit)){
             return false;
          }
      }
      for(int i=0; i<numCourses;i++){
          delete graph[i];
      }
      return true;
    }
};