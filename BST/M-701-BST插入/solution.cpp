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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
             
            return new TreeNode(val);
        }
        TreeNode* node = root;
        while(node){
            if(val<node->val){
                if(!node->left){
                    TreeNode* new_node = new TreeNode(val);
                    node->left = new_node;
                    break;
                }else{
                    node = node->left;
                }
            }else if(val > node->val){
                 if(!node->right){
                    TreeNode* new_node = new TreeNode(val);
                    node->right = new_node;
                    break;
                }else{
                    node = node->right;
                }
            }
        }
        return root;
    }
};