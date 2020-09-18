class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.size() == 0)
          return 0;
        
        map<string,vector<string>> graph;
        construct_graph(beginWord,wordList,graph);
        return BFS(beginWord,endWord,graph);
        
    }

private:
    //判断word1和word2能否相连
    bool isConnect(const string &word1, const string &word2){
        int cnt = 0; //记录不相等的字符个数
        for(int i=0;i<word1.length();i++){
            if(word1[i] != word2[i])
             ++cnt;
        }
        return cnt == 1;
    }
    
    //构建图
    void construct_graph(string beginWord, vector<string> &wordList, 
                        map<string,vector<string>> &graph
    ){
        wordList.push_back(beginWord);  //将beginWord push 人 vector
        for(int i=0; i<wordList.size();i++){
            graph[wordList[i]] = vector<string>(); 
        }
        for(int i=0;i<wordList.size(); i++){
            for(int j=i+1; j<wordList.size();j++){
                if(isConnect(wordList[i],wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
    }

    int BFS(string &beginWord,string &endWord,map<string,vector<string>> &graph){
        queue<pair<string,int>> Q; //宽搜队列
        Q.push(make_pair(beginWord,1)); //添加起始点，起始步数为1
        set<string> visit;  //记录已访问的顶点
        visit.insert(beginWord); //标记起点
        while(!Q.empty()){
            string node = Q.front().first; //取对头节点与步数
            int step = Q.front().second;
            Q.pop();
            if(node == endWord)
              return step;
            vector<string> &neighbors = graph[node]; //取node全部邻居节点
            for(int i=0;i<neighbors.size();i++){
                if(visit.find(neighbors[i]) == visit.end()){
                    Q.push(make_pair(neighbors[i],step+1));
                    visit.insert(neighbors[i]); //标记访问节点
                }
            }
        }
        return 0;

    }


};