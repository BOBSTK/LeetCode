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
        if(!root)
           return nullptr;
        if(root->val > p->val && root->val >q->val)  //p q 都在 root 左子树
           return lowestCommonAncestor(root->left,p,q);
        else if(root->val <p->val && root->val <q->val) //p q 都在 root 右子树
           return lowestCommonAncestor(root->right,p,q);
        return root; //说明 p,q 都在root一侧或者就是root本身
    }

    
};