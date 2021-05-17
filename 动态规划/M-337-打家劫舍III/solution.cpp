class Solution {
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        vector<int> ret = dp(root);
        return max(ret[0], ret[1]);
    }

    vector<int> dp(TreeNode* root){
        // ret[0] -- 抢root节点最大值  ret[1] -- 不抢root最大值
        vector<int> ret = vector<int>(2,0);
        if(!root) {
            return ret;
        }
        vector<int> left = dp(root->left);
        vector<int> right = dp(root->right);

        ret[0] = root->val + left[1] + right[1];  //抢这个节点最大值
        ret[1] = max(left[0], left[1]) + max(right[0], right[1]);
        return ret;
    }
};