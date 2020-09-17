class Solution {
public:
    vector<vector<int>> res;
    int t;
    void helper(vector<int> & candidates, int start, vector<int> & curr, int currSum) {
        if(currSum == t) {
            res.push_back(curr);
            return;
        }
        if(start >= candidates.size()) {
            return ;
        }
        
        if(candidates[start] + currSum > t) {
            return ;
        }
        
        // 选择当前数
        if(candidates[start] + currSum <= t) {
            curr.push_back(candidates[start]);
            helper(candidates, start+1, curr, currSum + candidates[start]);
            curr.pop_back();
        }
        
        // 不选择当前数, 跳过所有 和 当前数相同的数
        while(start+1 < candidates.size() && candidates[start+1] == candidates[start]) {
            start++;
        }
        helper(candidates, start+1, curr, currSum);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        
        t = target;
        vector<int> curr;
        helper(candidates, 0, curr, 0);
        
        return res;
    }
};

