// 层次遍历
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode*> Q;
        Q.push(root);
        int ans = 0;
        while(!Q.empty()){
            TreeNode* temp = Q.front();
            Q.pop();
            int val = temp->val;
            if(val > high){
                if(temp->left)
                    Q.push(temp->left); // 右子树不用考虑
            } else if(val < low){
                if(temp->right)
                     Q.push(temp->right); // 左子树不用考虑
            } else{
                ans += val;
                if(temp->left)
                    Q.push(temp->left);
                if(temp->right)
                     Q.push(temp->right);
            }
        }
        return ans;
    }
};