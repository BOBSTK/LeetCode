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
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> result; //存储结果
       vector<TreeNode*> nodes;
       while(root || !nodes.empty()){
         while(root){
             //访问节点
            nodes.push_back(root); 
           // result.push_back(root->val);
            root = root->left;
         }
         if(!nodes.empty()){
             root = nodes.back();
             result.push_back(root->val);
             nodes.pop_back();
             root = root->right;
         }
       }
       return result;
    }

};