/* C++ | inheritance: award line. */
/*获奖线的动态更新：由于 main 函数是先创建所有对象，再统一调用 display()。
在创建 GroupA 和 GroupB 的过程中，每一个新对象都会通过比较来更新 Student::awardLine。
当最后一个对象创建完毕时，awardLine 存储的就是全局最高分。
多态调用：main 函数中通过 pS[i]->display() 调用，
程序会根据对象的实际类型（A, B 或 C）进入对应的判定逻辑。
*/
#include <iostream>
using namespace std;
class Student{
    protected:
        string num,name;
    public:
        static double awardline;//静态变量 记录最高平均分
        Student(string n,string nm):num(n),name(nm){}
        virtual void display()  =0; 
        virtual ~Student(){} //构析函数要设置为虚函数 virtual ~Student(){}
};


//初始化静态成员 一定要在类外实现
double Student::awardline = 0.0;
class GroupA: public Student{
    int s1,s2;
    public:
     GroupA(string n,string nm,int a,int b ):Student(n,nm),s1(a),s2(b){
        //更新最大值
        double avg = (s1+s2)/2.0;
        if(avg>awardline) awardline = avg;
        }
    void display(){
        if((s1+s2)/2.0==awardline){
            cout<<num<<" "<<name<<endl;
        }
    }
};

class GroupB : public Student {
    int s1, s2;
    char grade;
public:
    GroupB(string n, string nm, int a, int b, char g) : Student(n, nm), s1(a), s2(b), grade(g) {
        double avg = (s1 + s2) / 2.0;
        if (avg > awardline) awardline = avg;
    }
    void display() {
        double avg = (s1 + s2) / 2.0;
        // 条件1：名列第一；条件3：70% 获奖线且表现为 A
        if (avg == awardline || (grade == 'A' && avg >= awardline * 0.7)) {
            cout << num << " " << name << endl;
        }
    }
};

class GroupC:public Student{
    int  s[5];
    public:
     GroupC(string n,string nm,int s1,int s2,int s3,int s4,int s5):Student(n,nm){
        s[0] = s1;
        s[1] = s2;
        s[2] = s3;
        s[3] = s4;
        s[4] = s5;
     }
     void display(){
        double sum = 0;
        for(int i = 0;i<5;i++) sum+=s[i];
        double avg = sum/5.0;
        if(avg>=awardline*0.9){
            cout<<num<<" "<<name<<endl;
        }
     }


};