/* C++ | classes: complex. */
#include <iostream>
using namespace std;
class CComplex
{  public:
      CComplex() {real=0; imag=0;}
      CComplex(double r, double i) ;
      CComplex(const CComplex &p) ;
      CComplex operator + (CComplex &c);
      friend CComplex operator + (const double &i, CComplex &c);
      friend CComplex operator + (CComplex &c, const double &i );
      void display(){cout<<"("<<real<<","<<imag<<")"<<endl;}
   private:
      double real;
      double imag;
}; 
CComplex::CComplex(double r,double i){
    real = r;
    imag = i;
}
CComplex::CComplex(const CComplex &p) {
    this->real = p.real;
    this->imag = p.imag; 
}
//+运算不能修改this 要弄个新对象
CComplex CComplex:: operator + (CComplex &c){
    CComplex ans;
    ans.real = this->real + c.real;
    ans.imag = this->imag + c.imag;
    return ans;

}
CComplex operator + (const double &i, CComplex &c){
        CComplex ans = c;
        ans.real += i;
        return ans;

}

CComplex operator + (CComplex &c, const double &i ){
        CComplex ans = c;
        ans.real += i;
        return ans;
}

int main()
{
    double x1,y1,x2,y2,z;
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>z;
    CComplex c1(x1,y1),c2(x2,y2),c3;
    c3=c1+c2;
    c3.display();
    c3=c1+z;
    c3.display();
    c3=z+c2;
    c3.display();
    return 0;
}