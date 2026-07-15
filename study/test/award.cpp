#include<iostream>
#include <string>
using namespace std;

class Student{
    protected:
        string num,name;
        static double  award;
    public:
        Student(string _num,string _name):num(_num),name(_name){};
        virtual void display() = 0;
};
double  Student::award = 0;

class GroupA:public Student{
    private:
        int s1,s2;
        float avg;
    public:
        GroupA(string _num,string _name,int _s1,int _s2):Student(_num,_name),s1(_s1),s2(_s2){
            avg = (s1+s2)/2.0;
            if(avg>award) award =  avg;
        }
        void display(){
            if(avg==award){
                cout<<num<<" "<<name<<endl;
            }
        }
};

class GroupB:public Student{
    private:
        int s1,s2;
        char gs;
        float avg;
    public:
        GroupB(string _num,string _name,int _s1,int _s2,char _gs):Student(_num,_name),s1(_s1),s2(_s2),gs(_gs){
            avg = (s1+s2)/2.0;
            if (avg > award) award = avg;
        }
        void display(){
            if(avg==award||(avg>=award*0.7&&gs=='A')){
                cout<<num<<" "<<name<<endl;
            }
        }
};
class GroupC:public Student{
    private:
        int s1,s2,s3,s4,s5;
        float avg;
    public:
        GroupC(string _num,string _name,int _s1,int _s2,int _s3,int _s4,int _s5):Student(_num,_name){
            s1 = _s1;
            s2 = _s2;
            s3 = _s3;
            s4 = _s4;
            s5 = _s5;
            avg = (s1+s2+s3+s4+s5)/5.0;
        }
        void display(){
            if(avg>=award*0.9){
                cout<<num<<" "<<name<<endl;
            }
        }


};

int main()
{
    const int Size=50;
    string num, name;
    int i,ty,s1,s2,s3,s4,s5;
    char gs;
    Student *pS[Size];
    int count=0;
    for(i=0;i<Size;i++){
        cin>>ty;
        if(ty==0) break;
        cin>>num>>name>>s1>>s2;
        switch(ty){
             case 1:pS[count++]=new GroupA(num, name, s1, s2); break;
             case 2:cin>>gs; pS[count++]=new GroupB(num, name, s1,s2, gs); break;
             case 3:cin>>s3>>s4>>s5; pS[count++]=new GroupC(num, name, s1,s2,s3,s4,s5); break;
        }            
    }
    for(i=0;i<count;i++) {
        pS[i]->display();
        delete pS[i];
    }
    return 0;
}
