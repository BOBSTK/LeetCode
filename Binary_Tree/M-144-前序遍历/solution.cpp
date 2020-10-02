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
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> result; //存储结果
       Traverse(root,result);
       return result;
       
    }

    void Traverse(TreeNode* node,vector<int> &result){
         if(!node)
           return;
         result.push_back(node->val);
         Traverse(node->left,result);
         Traverse(node->right,result);
    }
};