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
       vector<TreeNode*> nodes;
       while(root || !nodes.empty()){
         while(root){
             //访问节点
            nodes.push_back(root); 
            result.push_back(root->val);
            root = root->left;
         }
         if(!nodes.empty()){
             root = nodes.back();
             nodes.pop_back();
             root = root->right;
         }
       }
       return result;
    }
};