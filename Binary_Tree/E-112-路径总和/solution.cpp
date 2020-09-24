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
    bool hasPathSum(TreeNode* root, int sum) {
        int pathVal = 0;
        return traverse(root,sum,pathVal);
    }

    bool traverse(TreeNode *node,int &sum,int pathVal){
        if(!node)
          return false;
        pathVal += node->val;
        if(!node->left && !node->right && pathVal == sum){ //如果是叶子节点且符合要求
          return true;
        }
        return traverse(node->left,sum,pathVal) || traverse(node->right,sum,pathVal); //左右子树如果有符合条件的路径，返回true
    }
};