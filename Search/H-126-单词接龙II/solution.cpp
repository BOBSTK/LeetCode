struct Qitem{
    string node;    //搜索节点
    int parent_pos; //前驱节点在队列中的位置
    int step;       //到达当前节点的步数
    Qitem(string _node,int _parent_pos, int _step): node(_node),parent_pos(_parent_pos),step(_step){}
};

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        if(wordList.size() == 0)
          return result;
        vector<Qitem> Q; //vector 实现的队列，保存所有信息
        map<string,vector<string>> graph;
        construct_graph(beginWord,wordList,graph);
        vector<int> end_word_pos;
        BFS_graph(beginWord,endWord,graph,Q,end_word_pos);
        for(int i=0;i<end_word_pos.size();i++){
            int pos = end_word_pos[i];
            vector<string> path;
            while(pos != -1){
                path.push_back(Q[pos].node);
                pos = Q[pos].parent_pos;
            }
            result.push_back(vector<string>());
            //将result中的结果逆序
            for(int j=path.size()-1;j>=0;j--){
               result[i].push_back(path[j]); 
            }
        }
        return result;
    }
private :
  //广搜 记录路径
  void BFS_graph(string &beginWord,string &endWord, map<string,vector<string>> &graph,
                 vector<Qitem> &Q, vector<int> &end_word_pos //终点endWord所在队列的位置下标
   ){
       map<string,int> visit; //<单词，步数>
       int min_step = 0; //到达endWord的最小步数
       Q.push_back(Qitem(beginWord,-1,1)); //将beginWord入队，前驱位置为-1
       visit[beginWord] = 1; //标记起始单词步数为1
       int front = 0; //队头指针
       while(front < Q.size()){
           //取队头元素
           const string &node = Q[front].node;
           int step = Q[front].step;
           if(min_step != 0 && step > min_step)  //代表所有到达终点的最短路径已经搜完了
             break;
           if(node == endWord){ //找到最后一个节点而且步数是当前最小
             min_step = step; //更新最小步数
             end_word_pos.push_back(front); //记录当前节点位置
           }
           const vector<string> &neighbors = graph[node]; //获取当前节点的所有邻居节点
           for(int i=0;i<neighbors.size();i++){
               if(visit.find(neighbors[i]) == visit.end() || visit[neighbors[i]] == step+1){ //如果当前邻居节点没有被访问或者是另一条最短路径
                  visit[neighbors[i]] = step + 1; //标记到达邻居节点的最小步数
                  Q.push_back(Qitem(neighbors[i],front,step+1));
               }
           }
           ++front;

       } 
   }

    //构建图
    void construct_graph(string beginWord, vector<string> &wordList, 
                        map<string,vector<string>> &graph
    ){
        //判断wordList中是否包含beginWord
        int has_begin_word = 0;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i] == beginWord){
                has_begin_word = 1;
            }
            graph[wordList[i]] = vector<string>();
        }

       // wordList.push_back(beginWord);  //将beginWord push 人 vector

        for(int i=0;i<wordList.size(); i++){
            for(int j=i+1; j<wordList.size();j++){
                if(isConnect(wordList[i],wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
            if(has_begin_word == 0 && isConnect(beginWord,wordList[i])){
                graph[beginWord].push_back(wordList[i]);
            }
        }
    }

       //判断word1和word2能否相连
    bool isConnect(const string &word1, const string &word2){
        int cnt = 0; //记录不相等的字符个数
        for(int i=0;i<word1.length();i++){
            if(word1[i] != word2[i])
             ++cnt;
        }
        return cnt == 1;
    }

};