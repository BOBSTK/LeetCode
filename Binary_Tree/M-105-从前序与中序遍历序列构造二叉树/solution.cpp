class Solution {
public:
    TreeNode* MyBuildTree(vector<int>& preorder, vector<int>& inorder,int pre_left,int pre_right,int in_left,int in_right){
        if(pre_left > pre_right) return nullptr;
        int root_pre = pre_left;
        int root_in = index[preorder[root_pre]]; // 根节点在中序遍历中的位置
        TreeNode * node = new TreeNode(preorder[root_pre]); //当前前序队列根节点
        // 得到左子树中的节点数目
        int left_num = root_in - in_left;
        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        node->left = MyBuildTree(preorder,inorder,pre_left+1,pre_left+left_num,in_left,root_in-1);
        // 递归地构造左子树，并连接到根节点
        node->right = MyBuildTree(preorder,inorder,pre_left+left_num+1,pre_right,root_in+1,in_right);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
        for(int i=0;i<n;++i){
            index[inorder[i]] = i;
        }
        return MyBuildTree(preorder,inorder,0,n-1,0,n-1);
    }
private:
    unordered_map <int,int> index;  // 键表示节点值，值表示节点在中序遍历中的位置
};