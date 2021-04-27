class Solution {
public:
    //int ans = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        if(root->val > high){
            return rangeSumBST(root->left,low,high); // 只需要考虑左子树
        }
        if(root->val < low){
            return rangeSumBST(root->right,low,high); // 只需要考虑右子树
        }
        return  rangeSumBST(root->right,low,high) + rangeSumBST(root->left,low,high) + root->val;
    }
};