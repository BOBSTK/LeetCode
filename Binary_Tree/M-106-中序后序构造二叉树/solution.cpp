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
        int length = inorder.size();
        pos = length-1; //根节点在后序最后
        for(int i=0;i<length;i++){
            hash[inorder[i]] = i; //记录各结点在中序序列中的位置
        }
        return build(inorder,postorder,0,length-1);
    }
    //构建子树,返回子树的根节点
    TreeNode* build(vector<int>& inorder,vector<int> &postorder,int left,int right){
        if(left >right) //左/右子树为空
          return nullptr;
        int val = postorder[pos]; //根节点的值
        TreeNode *root = new TreeNode(val);//创建根节点
        int index = hash[val]; //根据root所在位置将中序数组分成两部分
        --pos;
        //先构建右子树
        root->right = build(inorder,postorder,index+1,right);
        root->left = build(inorder,postorder,left,index-1);
        return root;
    }
private:
   map<int,int> hash;  //存储中序位置
   int pos;  //存储当前根节点在中序序列的位置
};