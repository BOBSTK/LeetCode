class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;  //存储结果
        vector<int> path; //存储路径
        int path_value = 0;
        traverse(root,path_value,sum,path,result);
        return result;
    }

 private:
    void traverse(TreeNode *node,int &path_value,int sum,vector<int>&path,vector<vector<int>>& result){
        if(!node)
         return;
        //更新路径
        path_value += node->val; 
        path.push_back(node->val);
        //叶子节点
        if(!node->left && !node->right && path_value==sum){
            result.push_back(path);
        }
        traverse(node->left,path_value,sum,path,result);
        traverse(node->right,path_value,sum,path,result);
        //后序操作
        path_value -= node->val;
        path.pop_back();
    }
};