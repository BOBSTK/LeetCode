class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        if(dominoes.size() <= 1)
           return 0;
        int ret = 0;
        vector<int> hash = vector<int>(100,0);
        // 每一个二元对都变为指定的格式(第一维小于等于第二维)
        // 因为 1 <= dominoes[i][j] <= 9，可以将每一个二元对拼接成一个两位的正整数
        for(int i=0;i<dominoes.size();++i){
            int temp = (dominoes[i][0] <= dominoes[i][1])?dominoes[i][0]*10 + dominoes[i][1] : dominoes[i][1]*10+dominoes[i][0];
            ret += hash[temp];  // *
            ++hash[temp];
        }
        return ret;
    }
};