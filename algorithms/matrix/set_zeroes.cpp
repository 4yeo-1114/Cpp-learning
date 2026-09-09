/* C++ | matrix: set zeroes. */
#include <vector>
#include <algorithm>
using namespace std;
//方法一：标记哪行有零 哪列有零
//重复劳动（时间上的浪费）：假设第一行有 5 个 0，你的 numofh 里面就会存 5 个相同的行号。
//在最后清空的时候，同一行会被清空 5 次！
//空间浪费：最坏情况下（矩阵全为 0），你需要存 M * N 个行号和 M * N 个列号。
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int count = 0;
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    count ++;
                }
            }
        }
        vector<int> numofh(count);
        vector<int> numofl(count);
        int numh = 0;
        int numl = 0;
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    numofh[numh++] = i;
                    numofl[numl++] = j;
                }
            }
        }
        //清空行
        for(int i = 0;i<numh;i++){
            for(int j = 0;j<matrix[0].size();j++){
                matrix[numofh[i]][j] = 0;
            }
        }
        //清空列
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0 ;j<numl;j++){
                matrix[i][numofl[j]] = 0;
            }
        }
    }
};

//方法二：用布尔标记数组
//与其去记录坐标
//弄两本“黑名单”：一本记录哪些行有 0，一本记录哪些列有 0。
//只要发现一个 0，就把它的行和列拉黑。最后只要是在黑名单里的行和列，统统清零。
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m   = matrix.size();
        int n = matrix[0].size();
        vector<bool> row_has_zero(m,false);
        vector<bool> col_has_zero(n,false);
        //记录黑名单
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j]==0){
                    row_has_zero[i] = true;
                    col_has_zero[j] = true;

                }
            }
        }
        //置零
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(row_has_zero[i]||col_has_zero[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


//方法三 ：
//直接拿第一行做列黑名单
//第一列做行黑名单
//但是要先查第一行第一列有无零 避免后面数据被覆盖就不知道了
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //两个“记底细”的变量
        bool row0_flag = false;
        bool col0_flag = false;

        //先查底细
        for(int j = 0 ;j<n;j++){
            if(matrix[0][j]==0) row0_flag = true;
        }
        for(int i = 0;i<m;i++){
            if(matrix[i][0]==0) col0_flag = true;
        }
        //从下标1开始扫荡剩下的矩阵 把黑名单记在第一行和第一列上
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0; //这一行被拉黑了
                    matrix[0][j] = 0; //这一列被拉黑了
                }
            }
        }
        //清零 仍从下标1开始
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(matrix[i][0]==0||matrix[0][j]==0){
                        matrix[i][j] = 0;
                }
            }
        }
        //处理第一行和第一列
        if(row0_flag){
            for(int j  = 0;j<n;j++){
                matrix[0][j] = 0;
            }
        }
        if(col0_flag){
            for(int i = 0;i<m;i++){
                matrix[i][0] = 0;
            }
        }
    }
};