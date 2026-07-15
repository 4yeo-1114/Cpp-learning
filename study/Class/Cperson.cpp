#include <iostream>
#include <string.h> 
using namespace std;
class CPerson
{
public:
 CPerson(char *s)
 {
   //不用补零 memcpy才要
   name=new char[strlen(s)+1];strcpy(name,s);
}
 void Print()
 {  cout<<"name:"<<name<<endl;  }
protected:
  char *name;
};

//虚继承用于棱形继承 
class  CStudent : virtual public CPerson{
    public:
     //这里传的是字符串常量所以在函数参数列表要写const 保证是只读s
     CStudent(char *s,const char *_grade):CPerson(s){
        grade = new char[strlen(_grade)+1];
        strcpy(grade,_grade);
     }
     void Print(){
      //Cperson::print();
        CPerson::Print();
        cout<<"grade:"<<grade<<endl;
     }
     protected:
        char* grade;
};
class   CTeacher :virtual public CPerson{ 
    public:
     CTeacher(char *s,const char *_lesson):CPerson(s){
        lesson = new char[strlen(_lesson)+1];
        strcpy(lesson,_lesson);
     }
     void Print(){
        CPerson::Print();
        cout<<"lesson:"<<lesson<<endl;
     }
     protected:
        char* lesson;
 
};

class  CStudentTeacher: public CStudent,public CTeacher{
     public:
     //一定要用到虚基类的构造函数
     //CStudent 构造时不会再构造 CPerson
     CStudentTeacher(char *s,const char* _grade,const char *_lesson,const char* _major):CPerson(s), CStudent(s, _grade), CTeacher(s, _lesson){
        major = new char[strlen(_major)+1];
        strcpy(major,_major);
     }
     void Print(){
        CStudent::Print();
        cout<<"Major:"<<major<<endl;
     }
     protected:
        char* major;
};


int main()
{
 char sname[10],tname[10],stname[10];
 cin>>sname>>tname>>stname;
 //这里传的是字符串常量所以在函数参数列表要写const 保证是只读
 CStudent stu(sname,"16");
 CTeacher tea(tname,"math");
 CStudentTeacher stutea(stname,"17","ds","computer");
 stu.Print();
 tea.Print();
 stutea.Print();
 return 0;
}