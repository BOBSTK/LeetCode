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
    vector<int> findMode(TreeNode* root) {
        if(!root)
          return result;
        traverse(root);
        return result;
    }

    void traverse(TreeNode *node){
        if(!node)
          return;
        traverse(node->left);
        if(node->val != current){  //遇到一个新数字
           count = 1;
           current = node->val; 
        }else{
            ++count;
        }
            if(count == maxcount){  //当前数字已经达到当前最大计数
                result.push_back(current);
            }else if(count > maxcount){  //当前数字已经超过当前最大计数
                maxcount = count; //更新最大计数
                result.clear();   //清空之前的结果集
                result.push_back(current); //将当前数加入结果集
            }
        traverse(node->right);
    }
private:
int current = 0; //当前的数字
int count = 0;   //当前计数
int maxcount = 0; //数字出现的最大的计数
vector<int> result;
    
};