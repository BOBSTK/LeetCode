
struct cmp {
		bool operator() (const pair<int, int>& x, const pair<int, int>& y) {
			return x.second < y.second;
		}
	};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if(K>=points.size())
          return points;
        for(int i=0;i<points.size();++i){
            int distance = getDistance(points[i][0],points[i][1]); //计算距离
            if(max_heap.size()<K){
                max_heap.push(pair<int,int>(i,distance)); //容量小于k，直接入堆
            }else{
                if(distance < max_heap.top().second){
                    //替换堆顶元素
                    max_heap.pop();
                    max_heap.push(pair<int,int>(i,distance));
                }
            }
        }
        vector<vector<int>> result;
        while(max_heap.size()){
            int index = max_heap.top().first;
            result.push_back(points[index]);
            max_heap.pop();
        }
        return result;
    }

    //返回距离的平方
    int getDistance(int x,int y){
       return x*x + y*y;
    }
private:
    priority_queue<pair<int,int>, vector<pair<int,int>>,cmp> max_heap;  //大根堆，保存index和距离
};