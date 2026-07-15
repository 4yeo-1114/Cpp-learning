#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class matrix{
    private:
        int row;
        int column;
        int **mat;
    public:
        matrix(int _row,int _column){
            row = _row;
            column = _column;
            mat = new int*[row];
            for(int i = 0;i<row;i++){
                mat[i] = new int[column];
            }
        }
        void getmatrix(){
            for(int i = 0;i<row;i++){
                for(int j = 0;j<column;j++){
                    cin>>mat[i][j];
                }
            }
        }
        int& at(int n,int m){
            int& c = mat[n][m];
            return c;
        }
        matrix operator*(const matrix& m){
            if(column != m.row){
                cout<<"Invalid Matrix multiplication!"<<endl;
                exit(1); //非0表示程序异常退出
            }
            else{
            matrix res(row,m.column);
                for(int i  =0;i<row;i++){
                    for(int j = 0;j<m.column;j++){
                        long long sum = 0; //long long防止溢出
                        for(int k = 0;k<column;k++){
                            sum += mat[i][k] * m.mat[k][j];
                        }    
                         res.at(i,j) = sum;  
                    }
                       
                    }
                    return res;
                }
                
            }
        //拷贝构造
        matrix(const matrix& other) : row(other.row), column(other.column) {
            mat = new int*[row];
            for(int i = 0; i < row; i++){
                mat[i] = new int[column];
                for(int j = 0; j < column; j++)
                    mat[i][j] = other.mat[i][j];
            }
  }

        void display(){
            for(int i = 0 ;i<row;i++){
                for(int j = 0;j<column;j++){
                    cout<<setw(10)<<mat[i][j];
                }
                if(i!=row-1) cout<<"\n";
            }
        }
        matrix& operator=(const matrix& m){
            if(this == &m) return *this;
            else{
                for(int i = 0;i<row;i++){
                    delete[] mat[i];
                }
                delete[] mat;
                row = m.row;
                column = m.column;
                mat = new int*[row];
                for(int i = 0;i<row;i++){
                mat[i] = new int[column];
                }
                for(int i = 0;i<row;i++){
                    for(int j  =0;j<column;j++){
                        mat[i][j] = m.mat[i][j];
                    }
                }
                return *this;
            }
        }
    ~matrix(){
      for(int i = 0; i < row; i++)
          delete[] mat[i];
      delete[] mat;
  }
};
int main(){
    int r,c;
    cin>>r>>c;
    matrix m1(r,c);
    m1.getmatrix();
    int r1,c1;
    cin>>r1>>c1;
    matrix m2(r1,c1);
    m2.getmatrix();
    matrix m3 = m1*m2;
    m3.display();

}