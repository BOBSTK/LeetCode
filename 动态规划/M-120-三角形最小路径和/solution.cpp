class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       if(triangle.size() == 0)
        return 0;
       vector<vector<int>> dp;
       int depth = triangle.size(); 
       //初始化dp数组
       for(int i=0;i<depth;i++){
           dp.push_back(vector<int>());
           for(int j=0;j<depth;j++){
               dp[i].push_back(0);
           }
       }
       for(int i=0;i<dp.size();i++){
           dp[depth-1][i] = triangle[depth-1][i];//初始化最后一层的dp值
       }
       
       for(int i = depth-2;i>=0;i--){
           for(int j = 0;j<triangle[i].size();j++){
            dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + triangle[i][j];
           }
       }

       return dp[0][0];

       
    }
};

//节省空间解法
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> f(n);
        f[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            f[i] = f[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; --j) {
                f[j] = min(f[j - 1], f[j]) + triangle[i][j];
            }
            f[0] += triangle[i][0];
        }
        return *min_element(f.begin(), f.end());
    }
};
