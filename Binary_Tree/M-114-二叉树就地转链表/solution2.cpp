/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *curr = root;
        while(curr){
             if(curr->left){
                 auto next = curr->left; //记录左结点
                 //找到左子树前序最右结点
                 auto predecessor = next; 
                 while(predecessor->right){
                     predecessor = predecessor->right;
                 }
                 //将curr的右结点设为左子树的根节点
                 curr->left = nullptr;
                 //将左子树的最右结点与右子树根节点相连
                 predecessor->right = curr->right; 
                 curr->right = next; 
             }
             //处理下一个结点
             curr = curr->right;
        }
    } 
};