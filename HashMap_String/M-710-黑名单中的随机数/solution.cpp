/**
 * 如何少调用random算法，将黑名单中的数字放到数组尾部
 * **/
class Solution {
public:
    Solution(int n, vector<int>& blacklist) {
        sz  = n - blacklist.size(); 
        for(int x : blacklist){
            mapping[x] = -1; // 为黑名单中的数赋上初值
        }
        int last = n -1;
        for(int x : blacklist){
            if(x >= sz){
                continue; // b已经在[sz,n-1]中，无论值为多少都不可能被选中
            }
            while(mapping.find(last) != mapping.end()){
                // last 也在黑名单中
                --last; //跳过
            }
            mapping[x] = last;
            --last;
        }
    }
    
    int pick() {
        // 随机选择索引
        int index = rand()%sz; // 选择 [0,sz-1]
        if(mapping.find(index) != mapping.end()){
            return mapping[index]; // 映射到其他位置
        }
        return index;
    }
private:
    int sz; //数组的实际长度（去除黑名单）
    unordered_map<int,int> mapping;
};