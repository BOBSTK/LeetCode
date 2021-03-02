// 二维前缀和
//matrix 以(i,j) 为右下角的子矩阵的元素之和：
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row>0){
            int col = matrix[0].size();
            vector<vector<int>> new_presums = vector<vector<int>> (row+1,vector<int>(col+1));
            presums.swap(new_presums);
             
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    presums[i + 1][j + 1] = presums[i][j + 1] + presums[i + 1][j] - presums[i][j] + matrix[i][j];
                }
            }
        }
    }

    
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return presums[row2 + 1][col2 + 1] - presums[row1][col2 + 1] - presums[row2 + 1][col1] + presums[row1][col1];
    }
private:
    vector<vector<int>> presums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */



