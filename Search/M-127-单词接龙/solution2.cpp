struct word {
		string val;
		vector<word*> neighbor;
		word(string v) :val(v) {}
	};

class Solution {
public:
	//判断两个单词是否能够转换(默认两个字符不相等)
	bool CanTrans(const string& str1, const string& str2) {
		if (str1.length() != str2.length())
			return false; //长度不同一定不能转换
		int length = str1.length();
		int cnt = 0; //记录两个string中不相同的字符数
		for (int i = 0; i < length; ++i) {
			if (str1[i] != str2[i])
				++cnt;
			if (cnt > 1)
				return false;
		}
		return true;
	}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      	vector<word*> nodes; //点
		nodes.push_back(new word(beginWord)); //将beginWord放入

		//将wordList中的节点连成图
		for (int i = 0; i < wordList.size(); ++i) {
			//cout << "current node: " << wordList[i] << endl;
			if (wordList[i] != beginWord) {
				nodes.push_back(new word(wordList[i])); //放入点集
				for (int j = 0; j < nodes.size()-1; ++j) {
					if (CanTrans(wordList[i], nodes[j]->val)) {
						//连线
						nodes[nodes.size() - 1]->neighbor.push_back(nodes[j]);
						nodes[j]->neighbor.push_back(nodes[nodes.size() - 1]);
						//cout << "连接 " << nodes[nodes.size() - 1]->val << "和 "<< nodes[j]->val<<endl;
					}
				}
			}
		}

		//从nodes[0]开始，找一条通往end的最短路径,BFS
		queue <word*> q;  //队列
		set<word*> visit;
		
		q.push(nodes[0]);
		visit.insert(nodes[0]);
		int step = 0;
		while (!q.empty()) {
			++step;
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				word* cur = q.front();
				q.pop();
				cout << cur->val << endl;
				if (cur->val == endWord)
					return step;
				for (word* x : cur->neighbor) {
					if (!visit.count(x)) {
						q.push(x);
						visit.insert(x);
					}
				}
				
			}
		}

		return 0;
    }
};