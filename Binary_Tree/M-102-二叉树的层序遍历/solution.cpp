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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
          return result;
        Q.push(root);
        while(!Q.empty()){
            result.push_back(vector<int>());
            int qSize = Q.size(); //记录这一层的节点数
            for(int i=0;i<qSize;i++){
              auto node = Q.front();
              Q.pop();
              result.back().push_back(node->val);
              //将子节点入队列
              if(node->left)
                Q.push(node->left);
              if(node->right)
                Q.push(node->right);
            }
        }
        return result;
    }
    private:
    queue<TreeNode*> Q;

};