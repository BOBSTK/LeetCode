// BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> Q;
        int depth = 0;
        Q.push(root);
        while(!Q.empty()){
            depth += 1;
            int sz = Q.size(); //当前层的节点数
            for(int i=0;i<sz;++i){
                TreeNode* temp = Q.front(); // 取出队首节点
                //cout<<temp->val<<endl;
                Q.pop();
                if(!temp->left && !temp->right) return depth; //结束
                if(temp->left) Q.push(temp->left);
                if(temp->right) Q.push(temp->right);
            }
        }
        return depth;
    }
};