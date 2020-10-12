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
    int getMinimumDifference(TreeNode* root) {
        if(!root)
          return 0;
       int min = INT_MAX;
       traverse(root);
       for(int i=0;i<value.size()-1;i++){
           int temp = value[i+1] - value[i];
           if(temp<min)
              min = temp;
       }
       return min;     
    }
    
   void traverse(TreeNode* node){
        if(!node)
          return;
        traverse(node->left);
        value.push_back(node->val);
        traverse(node->right);
    }

private:
   vector<int> value;
};