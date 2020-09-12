class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *last = nullptr;
        traverse(root,last);
    }
    //              当前访问节点     当前子树先序遍历的最后一个节点
    void traverse(TreeNode* node,TreeNode *&last){
        if(!node)
        return;
        //叶子节点
        if(!node->right && !node->left){
          last = node;  //当前节点是当前子树的最后一个节点
          return;
        }
        //备份左右指针
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        //左右子树的最后一个节点
        TreeNode *left_last = nullptr;
        TreeNode *right_last = nullptr;
      
      
        //如果有左子树
        if(left){
            traverse(left,left_last);  //假设左子树已经展开为链表
            node->left = nullptr;
            node->right = left;
            last = left_last; //当前节点的last保存左子树的last
        }
        //如果有右子树
        if(right){
            traverse(right,right_last); //左右子树都已展开为链表
            if(left_last){  //如果有左子树
            //将左右子树的链表连接
               left_last->right = right;
            }
            //更新当前子树的最后一个节点
            last = right_last;
        }
    }
};