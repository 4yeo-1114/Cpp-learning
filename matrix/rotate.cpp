//旋转矩阵
//两次翻转等于一次旋转
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n  = matrix.size();
        //对角线交换
        for(int i = 0;i<n;i++){
            for(int  j  = 0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //写在上个循环里面也可以
        for(int i = 0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

//一次转
//四个一组
// func rotate(matrix [][]int) {
// 	n := len(matrix)
// 	for i := range (n + 1) / 2 {
// 		for j := range n / 2 {
// 			tmp := matrix[i][j]
// 			matrix[i][j] = matrix[n-1-j][i]
// 			matrix[n-1-j][i] = matrix[n-1-i][n-1-j]
// 			matrix[n-1-i][n-1-j] = matrix[j][n-1-i]
// 			matrix[j][n-1-i] = tmp
// 		}
// 	}
// }