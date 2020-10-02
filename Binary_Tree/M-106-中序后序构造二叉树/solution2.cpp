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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       if(postorder.size() == 0)
         return nullptr;
       TreeNode* root = new TreeNode(postorder[postorder.size()-1]); //构建根节点
       auto s = stack<TreeNode*>(); //当前节点的所有还没有考虑过左儿子的祖先节点
       s.push(root);
       int inorderIndex = inorder.size()-1; //辅助指针，初始指向中序遍历最后一个结点 这个结点一定没有右孩子
       for(int i = int(postorder.size()) - 2; i >= 0; i--){
          int postorderVal = postorder[i];
          TreeNode* node = s.top(); //栈顶元素
          if(node->val != inorder[inorderIndex]){ //将根节点右方向的所有孩子结点连起来并入栈
              node->right = new TreeNode(postorderVal);
              s.push(node->right);
          }else{//栈顶元素没有右结点，那么当前查到的结点一定是某个结点的左孩子
              while (!s.empty() && s.top()->val == inorder[inorderIndex]) {  //栈中的节点的顺序和它们在反向前序遍历中出现的顺序是一致的
                    node = s.top();
                    s.pop();
                    inorderIndex--;
                }
                node->left = new TreeNode(postorderVal);
                s.push(node->left);
                
          }
         
       }
       return root;
    }
};

