class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> path;
        std::vector<TreeNode*> p_path;
        std::vector<TreeNode*> q_path;
        int finish = 0;
        NodePath(root,p,path,p_path,finish); //求到p的路径
        path.clear();
        finish = 0;
        NodePath(root,q,path,q_path,finish); //求到q的路径
        int path_len = 0;
        path_len = p_path.size() > q_path.size() ? q_path.size() : p_path.size(); //较短路径长度
        TreeNode *result = nullptr;
        for(int i=0;i<path_len;i++){
            if(p_path[i] == q_path[i]){
                result = p_path[i];
            }
        }
        return result;
    }

private:
    //找到给定节点的路径
    void NodePath(TreeNode *node,TreeNode * search,
    std::vector<TreeNode*>&path,  //遍历路径
    std::vector<TreeNode*>&result, //结果路径
    int &finish  //是否找到search
    ) {
    if(!node || finish==1) //如果node为空或已经找到节点，直接返回
    return;
    path.push_back(node);
    if(node == search){
      finish = 1;
      result = path; //存储路径
    }
    NodePath(node->left,search,path,result, finish);
    NodePath(node->right,search,path,result,finish);
    path.pop_back();
    }
};