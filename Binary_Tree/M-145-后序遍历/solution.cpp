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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> nodes;
        TreeNode* prev;
        if(!root) return result;
        while(root || !nodes.empty()){
            while(root){
                nodes.push_back(root);
                root = root->left;
            }
            if(!nodes.empty()){
                root = nodes.back();
                nodes.pop_back();
            }
            if(root->right == nullptr || root->right == prev){
                result.push_back(root->val);
                prev = root;
                root = nullptr;
            }else{
                nodes.push_back(root);
                root = root->right;
            }
        }
        return result;
    }
};