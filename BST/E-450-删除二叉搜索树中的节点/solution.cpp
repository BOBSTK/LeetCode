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
   

    TreeNode* deleteNode(TreeNode* root,int key){
        if(!root)
          return root;
        if(root->val == key){
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            if(root->left && root->right){
               TreeNode* cur = root->right;
                while(cur->left != NULL) {
                    cur = cur->left;
                }
                cur->left = root->left;//将根节点右子树最小值指向左子树根节点
                root = root->right; 
                return root;
            }
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }
        return root;
    }

    
};