class Solution {
public:
    int ans = INT_MIN;
    int maxGain(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = max(maxGain(root->left),0);  
        int right = max(maxGain(root->right),0);
        int priceNewPath = left + right + root->val;  //当前节点的贡献值
        ans = max(ans,priceNewPath);  //更新答案
        return max(left,right) + root->val; // 以该节点为子节点的路径
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return ans;
    }
};