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
    int countNodes(TreeNode* root) {
      TreeNode *left = root, *right = root;
      //记录左右子树的高度
      int hl = 0,hr = 0;
      while(left){
          left = left->left;
          ++hl;
      }
      while(right){
          right = right->right;
          ++hr;
      }
      if(hl == hr){ //左右子树相同，说明是一颗满二叉树
          return (int)pow(2,hl)-1;
      }
      //按照普通二叉树的逻辑计算
      return 1 + countNodes(root->left) + countNodes(root->right);
    }
};