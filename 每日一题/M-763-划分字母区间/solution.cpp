class Solution {
public:
    vector<int> partitionLabels(string S) {
       vector<int> last(26,-1); //存储每个字符在S中的最后一个位置,初始为-1
       int length = S.length();
       //更新last数组
       for(int i=0;i<length;i++){
           last[S[i]-'a'] = i;
       }
       
       //分段指针
       int start = 0;
       int end = 0; 
       vector<int> partition; //存储结果
       for(int i=0;i<length;i++){
           int endc = last[S[i]-'a']; //记录当前字符最后出现的位置
           end = max(end,endc); //更新end
           if(end == i){  //如果end和i相等，说明需要分组
              partition.push_back(end-start+1);
              start = end+1;
              end = end+1;
           }
       }

       return partition;
    }
};