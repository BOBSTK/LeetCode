/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,nullptr,nullptr);
    }
    
    //min - 右边最大节点    max - 左边最小节点
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root == nullptr)
          return true;
        if(min!=nullptr && root->val <= min->val) return false;
        if(max!=nullptr && root->val >= max->val) return false;
        return isValidBST(root->left,min,root) && isValidBST(root->right,root,max);           
    }
};