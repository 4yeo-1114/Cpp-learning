#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
class matrix{
    private:
        int rows;//行数
        int cols;//列数
        int data[100][100];
    public:
        //构造函数
        matrix(int r = 0,int c = 0){
            rows  = r;
            cols = c;
        }
        //从控制台读取矩阵数据
        void readData(){
            for(int i = 0;i<rows;i++){
                for(int j = 0;j<cols;j++){
                    cin>>data[i][j];
                }
            }
        }
        //重载运算符 +
        matrix operator+(const matrix& other) const{
            //创建一个新矩阵存放结果
            matrix res(rows,cols);
            for(int i = 0;i<rows;i++){
                for(int j = 0;j<cols;j++){
                    res.data[i][j] = this->data[i][j] + other.data[i][j];
                }
            }
            return res;
        }
        void print(){
            for(int i = 0;i<rows;i++){
                for(int j = 0;j<cols;j++){
                    cout<<data[i][j];
                    if(j!=cols-1){
                        cout<<" ";
                    }
                }
                if(i!=rows-1){
                    cout<<endl;
                }
                
            }
        }
};
int main(){
    int m,n;
    cin>>m>>n;
    matrix A(m,n);
    A.readData();
    matrix B(m,n);
    B.readData();
    matrix C = A+B;
    C.print();
    return  0;
}


//动态分配内存版
#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int** data; // 用双重指针替代固定大小的二维数组 data[100][100]

public:
    // 1. 构造函数：根据传入的行和列动态分配内存
    Matrix(int r = 0, int c = 0) : rows(r), cols(c) {
        if (rows > 0 && cols > 0) {
            data = new int*[rows]; // 先分配存放行指针的数组
            for (int i = 0; i < rows; ++i) {
                data[i] = new int[cols]{0}; // 为每一行分配具体的列数，并初始化为0
            }
        } else {
            data = nullptr; // 如果是0行0列，设为空指针
        }
    }

    // 2. 析构函数：释放内存（极其重要！）
    ~Matrix() {
        if (data != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i]; // 先释放每一行的内存
            }
            delete[] data; // 再释放行指针数组的内存
        }
    }

    // 3. 拷贝构造函数：深拷贝（极其重要！）
    // 当执行 Matrix C = A + B; 时，会调用这个函数来复制对象
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        if (rows > 0 && cols > 0) {
            data = new int*[rows];
            for (int i = 0; i < rows; ++i) {
                data[i] = new int[cols];
                for (int j = 0; j < cols; ++j) {
                    data[i][j] = other.data[i][j]; // 把数据挨个抄过来
                    //只是数值一样 内存地址不一样 实现了深拷贝
                }
            }
        } else {
            data = nullptr;
        }
    }

    // 4. 赋值运算符重载：深拷贝
    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this; // 防止自己赋值给自己 (如 A = A)
        // 如果不加这句，下一步你把自己的内存删了，就再也找不到数据来抄了！

        // 先清理自己原有的内存
        // 这是拷贝构造函数绝对没有的步骤，因为拷贝构造时对象还没分配过内存
        if (data != nullptr) {
            for (int i = 0; i < rows; ++i) delete[] data[i];
            delete[] data;
        }

        // 再根据 new 的大小重新分配并拷贝数据
        rows = other.rows;
        cols = other.cols;
        if (rows > 0 && cols > 0) {
            data = new int*[rows];
            for (int i = 0; i < rows; ++i) {
                data[i] = new int[cols];
                for (int j = 0; j < cols; ++j) {
                    data[i][j] = other.data[i][j];
                }
            }
        } else {
            data = nullptr;
        }
        return *this;
    }

    // 读入数据
    void readData() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    // 重载 + 运算符（逻辑和原来一模一样，但底层已经变成了动态内存）
    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols); 
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result; 
    }

    // 打印矩阵
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j];
                if (j != cols - 1) { 
                    cout << " "; 
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int m, n;
    if (cin >> m >> n) { 
        Matrix A(m, n);
        A.readData();

        Matrix B(m, n);
        B.readData();

        // 这里的 C 是全新创建的，它完美触发了深拷贝，并且在程序结束时会自动清理内存
        Matrix C = A + B;

        C.print();
    }
    return 0;
}
/*拷贝构造函数负责“从无到有”地新建matrix c = a，而赋值运算符负责“推倒重来”地修改。c = a*/




//CMatrix
#include <iostream> 
#include <math.h>
using namespace std;
class CMatrix{
    int row,column;
    float **m_matrix;
public:
    CMatrix(int r=0,int c=0); //通过参数行列值为矩阵分配内存，为矩阵数据元素初始化为0
    void setmatrix(); //通过输入数据为矩阵的数据元素赋值
    void display(); //用行列方式显示矩阵中数据元素的值
    CMatrix(CMatrix &m); //复制构造函数
};
CMatrix::CMatrix(int r,int c){
    row = r;
    column =c;
    m_matrix = new float*[r];
    for(int i = 0;i<r;i++){
        m_matrix[i] = new float[c];
    }
}
void CMatrix::setmatrix(){
    for(int i  =0;i<row;i++){
        for(int j = 0;j<column;j++){
            cin>>m_matrix[i][j];
        }
    }
}
void CMatrix::display(){
    for(int i =0;i<row;i++){
        for(int j = 0;j<column;j++){
            cout<<m_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
CMatrix::CMatrix(CMatrix &m){
    row = m.row;
    column =m.column;
    m_matrix = new float*[row];
    for(int i = 0;i<row;i++){
        m_matrix[i] = new float[column];
        for(int j = 0;j<column;j++){
            m_matrix[i][j] = m.m_matrix[i][j];
        }
    }
    
}

int main(){
    int r1,c1,r2,c2;
    cin>>r1>>c1;
    CMatrix a(r1,c1);
    a.setmatrix();
    cin>>r2>>c2;
    CMatrix b(r2,c2);
    b.setmatrix();
    CMatrix c(a);
    c.display();
    return 0;
}
