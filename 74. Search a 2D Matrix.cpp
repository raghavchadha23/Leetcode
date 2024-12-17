class Solution {
public:


    pair<int, int> getRowandColumn(vector<vector<int>>& matrix, int index) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int final_row = index/cols;
        int final_cols = index % cols;
        pair<int,int> p1 = make_pair(final_row, final_cols);

        return p1 ;
    }


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int lo = 0, hi = rows*cols - 1;
        int mid;
        pair<int, int> hi_index;
        pair<int, int> lo_index;
        pair<int, int> mid_index;
        
        
        if((hi - lo) <= 1) {
            for(int j = 0; j < matrix.size(); j++) {
                for(int i = 0; i < matrix[j].size(); i++) {
                    if (matrix[j][i] == target ) {
                        return true;
                    }
                    }
                }
                return false;
        }
        
        while(hi - lo > 1) {
            int mid = (hi + lo) / 2;
            mid_index = getRowandColumn(matrix, mid);
            int num = matrix[mid_index.first][mid_index.second];
            if(matrix[mid_index.first][mid_index.second] < target) {
                lo = mid + 1;
            }else{
                hi = mid;
            }
        }
        lo_index = getRowandColumn(matrix, lo);
        hi_index = getRowandColumn(matrix, hi);
        if(matrix[lo_index.first][lo_index.second] == target) {
            return true;
        }else if(matrix[hi_index.first][hi_index.second] == target) {
            return true;
        }else{
            return false;
        }
        
        
    }
};
