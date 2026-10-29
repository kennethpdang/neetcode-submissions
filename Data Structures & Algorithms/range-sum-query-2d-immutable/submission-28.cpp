class NumMatrix {
private:
    vector<vector<int>> prefix_matrix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        // Make it right size:
        vector<int> rows(matrix[0].size(), 0);
        prefix_matrix.assign(matrix.size(), rows);

        for (int row_index = 0; row_index < matrix.size(); row_index++) {
            for (int col_index = 0; col_index < matrix[0].size(); col_index++) {
                int previous_left = (col_index >= 1) ? prefix_matrix[row_index][col_index - 1] : 0;
                int previous_top = (row_index >= 1) ? prefix_matrix[row_index - 1][col_index] : 0;
                int diagonal = (row_index >= 1 && col_index >= 1) ? prefix_matrix[row_index - 1][col_index - 1] : 0;

                prefix_matrix[row_index][col_index] = matrix[row_index][col_index] + previous_left + (previous_top - diagonal);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int whole_area = prefix_matrix[row2][col2];
        int area_above = (row1 >= 1) ? prefix_matrix[row1 - 1][col2] : 0;
        int area_left = (col1 >= 1) ? prefix_matrix[row2][col1 - 1] : 0;
        int area_diagonal = (row1 >= 1 && col1 >= 1) ? prefix_matrix[row1 - 1][col1 - 1] : 0;

        return whole_area - area_above - (area_left - area_diagonal);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */