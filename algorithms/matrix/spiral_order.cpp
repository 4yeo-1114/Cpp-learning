/* C++ | matrix: spiral order. */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start_row = 0;
        int end_row = m-1;
        int start_col = 0;
        int end_col = n-1;
        int dir = 0;
        vector<int> res(m*n);
        int num = 0;
        while(start_row<=end_row&&start_col<=end_col){
            if(dir%2==0){
                for(int i = start_col;i<=end_col;i++){
                    res[num++] = matrix[start_row][i];
                }
                start_row++;
                for(int i = start_row;i<=end_row;i++){
                    res[num++] = matrix[i][end_col];
                }
                end_col--;
                dir++;
            }
            else{
                for(int i = end_col;i>=start_col;i--){
                    res[num++] = matrix[end_row][i];
                }
                end_row--;
                for(int i = end_row;i>=start_row;i--){
                    res[num++] = matrix[i][start_col];
                }
                start_col++;
                dir++;
            }
            
        }
        return res;
    }
};

//写法二：
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                order.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++) {
                order.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    order.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; row--) {
                    order.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }
};
