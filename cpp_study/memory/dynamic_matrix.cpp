/* C++ | memory: dynamic matrix. */
#include<iostream>
#include<cstring>
using namespace std;
class Matrix;  //类的向前声明
class Vector {
    private:
        int* v;
        int sz;
    public:
        Vector(int n) {            v=new int[sz=n];        }
        Vector(const Vector& t) {
            v=new int[sz=t.sz];
            memcpy(v,t.v,sz*sizeof(int));   //深拷贝
            //memcpy(v,t.v,sz*sizeof(int)) memcpy(v,t.v,sz*sizeof(int)) memcpy(v,t.v,st*sizeof(int))
        }
        ~Vector() {    delete []v;    } // delee[] v;
        int& operator[](int i) {
            if(i>=0 &&i<sz)  //下标越界检查
                return v[i];
            else {
                cout<<"Vector index out of range.\n";    exit(0);
            }
        }
        friend ostream& operator<<(ostream& out,const Vector& x);
        friend Vector operator*(Matrix& m,Vector& v);//重载乘法运算符
};
class Matrix {
    private:
        int* m;
        int szl,szr;
    public:
        Matrix(int a,int b) {
            szl=a;    szr=b;
            m=new int[a*b];   //用一维数组模拟矩阵
        }
        ~Matrix() {    delete []m;    }
        int& operator()(int i,int j) ;
        friend Vector operator*(Matrix& m,Vector& v);
};
int main() {
    int n,m;
    cin>>n>>m;
    Matrix ma(n,m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>ma(i,j);
    cin>>n;
    Vector ve(n);
    for(int i=0; i<n; i++) cin>>ve[i];
    Vector va = ma * ve;
    cout<<va<<endl;
    return 0;
}

int& Matrix::operator()(int i,int j){
    if(i>=0&&i<szl&&j>=0&&j<szr){
        return m[i*szr+j];
    }
    else{
        cout<<"Matrix index out of range."<<endl;
        exit(0);
    }
    
}

ostream& operator<<(ostream& out,const Vector& x){
    for(int i = 0;i<x.sz;i++){
        out<<x.v[i]<<" ";
    }
    return out;
}

Vector operator*(Matrix& mat,Vector& vex){
    if(mat.szr!=vex.sz){
        cout<<"Bad multiplying Matrix with Vector."<<endl;
        exit(0);
    }
    Vector res(mat.szl);
    for(int i = 0;i<mat.szl;i++){
        int sum  =0;
        for(int j  =0;j<mat.szr;j++){
            sum += vex.v[j] * mat(i,j);
        }
        res.v[i] = sum;
    }
    return res;
}