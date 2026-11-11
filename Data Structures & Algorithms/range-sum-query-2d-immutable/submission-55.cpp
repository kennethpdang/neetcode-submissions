class NumMatrix {
private:
    vector<vector<int>> prefix_matrix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        // Variables:
        vector<int> row(matrix[0].size());
        prefix_matrix.assign(matrix.size(), row);

        // Fill out prefix matrix:
        for (int row_index = 0; row_index < matrix.size(); row_index++) {
            for (int col_index = 0; col_index < matrix[0].size(); col_index++) {
                int diagonal_sum = (col_index >= 1 && row_index >= 1) 
                ? prefix_matrix[row_index - 1][col_index - 1]
                : 0;
                int top_sum = (row_index >= 1) ? prefix_matrix[row_index - 1][col_index] : 0;
                int left_sum = (col_index >= 1) ? prefix_matrix[row_index][col_index - 1] : 0;

                prefix_matrix[row_index][col_index] = left_sum + (top_sum - diagonal_sum) 
                + matrix[row_index][col_index];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int whole_area = prefix_matrix[row2][col2];
        int top_area = (row1 >= 1) ? prefix_matrix[row1 - 1][col2] : 0;
        int left_area = (col1 >= 1) ? prefix_matrix[row2][col1 - 1] : 0;
        int diagonal_area = (row1 >= 1 && col1 >= 1) ? prefix_matrix[row1 - 1][col1 - 1] : 0;

        return whole_area - top_area - left_area + diagonal_area;
    }
};