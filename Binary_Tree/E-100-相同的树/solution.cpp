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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)  //都为空节点
           return true;
        if(p == nullptr || q == nullptr)  //一个为空节点，另一个不为空节点
           return false;
        if(p->val != q->val)  //val不一样
           return false;
         return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};