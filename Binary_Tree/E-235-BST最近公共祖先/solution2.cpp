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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(root->val > p->val && root->val >q->val)  //p q 都在 root 左子树
                root = root->left;
            else if(root->val <p->val && root->val <q->val) //p q 都在 root 右子树
                root = root->right;
            else 
                return root;
        }
        return nullptr;
    }

    
};