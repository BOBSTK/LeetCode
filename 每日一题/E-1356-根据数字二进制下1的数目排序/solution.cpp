class Solution {
public:
     
    int count_1(int x) {
		int cnt = 0;
		while (x > 0) {
			if (x % 2 == 1)
				++cnt;
			x /= 2;
		}
		return cnt;
	}

    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ret;
		map<int, vector<int>> hash;
		//插入
		for (int i = 0; i < arr.size(); ++i) {
			hash[count_1(arr[i])].push_back(arr[i]);
		}
		//遍历图
		for (map<int, vector<int>>::iterator it = hash.begin(); it != hash.end(); ++it) {
			//排序并遍历
            sort(it->second.begin(),it->second.end());
			for(int i=0;i<it->second.size();++i)
              ret.push_back(it->second[i]);
           
		}
		return ret;
    }
};