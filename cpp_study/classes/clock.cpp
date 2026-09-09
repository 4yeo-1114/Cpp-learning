/* C++ | classes: clock. */
#include<iostream>
using namespace std;
class Clock {
public:
    Clock(int NewH=0, int NewM=0, int NewS=0);
    void ShowTime();
    Clock operator++();          //前置单目成员运算符重载
    friend Clock operator++(Clock& op,int);    //后置单目友元运算符重载
private:
    int Hour, Minute, Second;
};
Clock::Clock(int NewH, int NewM, int NewS) {
    Hour=NewH;
    Minute=NewM;
    Second=NewS;
}
void Clock::ShowTime() {
    cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
}

Clock Clock:: operator++(){
    Second++;
    if(Second>=60){
        Second = 0;
        Minute++;
        if(Minute>=60){
            Minute=0;
            Hour++;
            if(Hour>=24){
                Hour = 0;
            }
        }
    }
    //前缀自增返回自己
    return *this ;
}



//后置单目友元运算符重载 要带int
Clock operator++(Clock& op,int){
    //先保存对象自增前的状态
    Clock temp = op;
    ++op;
    //返回旧状态
    return temp;
}


int main() {
  int h, m, s;
  cin>>h>>m>>s;
  Clock a(h,m,s);
  (++a).ShowTime();
  (a++).ShowTime();
  a.ShowTime();
  return 0;
}