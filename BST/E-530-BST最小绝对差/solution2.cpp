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
    int getMinimumDifference(TreeNode* root) {
        if(!root)
          return 0;
       int min = INT_MAX;
       int pre = -1; //保存前驱节点的值 初始设为-1
       traverse(root,pre,min);
       return min;     
    }
    
    void traverse(TreeNode* node,int &pre,int &min){
        if(min == 1)
          return;
        if(!node)
          return;
        traverse(node->left,pre,min);
        if(pre==-1){
           pre = node->val; //说明这是最左结点，没有前驱
        }else{
           int gap = node->val - pre; //前去前驱，一定是正数
           if(min>gap)
             min = gap;
           pre = node->val; //更新前驱
        }
        traverse(node->right,pre,min);
    }

};