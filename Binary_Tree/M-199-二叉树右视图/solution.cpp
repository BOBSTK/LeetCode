class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result; //存储结果
        std::queue<std::pair<TreeNode*,int>> Q; //宽搜队列
        if(root){ //如果根节点存在
            Q.push(std::make_pair(root,0)); //将根节点入队，层数设为1
        }
        while(!Q.empty()){
            TreeNode *node = Q.front().first; //遍历节点
            int layer = Q.front().second; //节点层数
            //出队
            Q.pop();
            //子节点入队
            if(node->left){
                Q.push(std::make_pair(node->left,layer+1));
            }
            if(node->right){
                Q.push(std::make_pair(node->right,layer+1));
            }
            //更新当前层数的最右节点
            if(result.size() == layer){   //如果是新的一层
              result.push_back(node->val);  
            }else{
              result[layer] = node->val; 
            }
            
        }
        return result;
    }
};