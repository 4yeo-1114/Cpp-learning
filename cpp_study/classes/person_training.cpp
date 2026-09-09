/* C++ | classes: person training. */
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
class information{
    private:
        int age;
        char sex;
    public:
        information(){
            age =  0;
            sex = 'M';
        }
        information(int a,char s){
            age  = a;
            sex = s;
        }
        ~information(){
        }
        void setAge(int a){
            age = a;
        }
        int getAge(){
            return age;
        }
        void setSex(char s){
            sex = s;
        }
        char getSex(){
            return sex;
        }
        void printInfo(){
            cout<<sex<<" "<<age<<endl;
        }
};

class Student{
    private:
        string id;
        string name;
        double mathScore;
        double chineseScore;
        double totalScore;
        information info;
    public:
        //无参构造函数
    Student(){
        mathScore = 0.0;
        chineseScore = 0.0;
        totalScore = 0.0;
    }
    //有参构造函数 内部的info对象要通过初始化列表或内部传参来构造
    Student(string  i,string n,double math,double chinese,int a,char s)
    : id(i),name(n),mathScore(math),chineseScore(chinese),info(a,s){
        totalScore = mathScore+chineseScore;
    }
    //设置信息函数
    void setStudentInfo(string i,string n,double math,double chinese,int a,char s){
        id = i;
        name = n;
        mathScore = math;
        chineseScore = chinese;
        totalScore = math + chinese;
        info.setAge(a);
        info.setSex(s);
    }
    //显示信息函数
    void display(){
        cout<<id<<" "<<name<<" "<<info.getSex()<<" "<<info.getAge()<<" "
        <<fixed<<setprecision(2)<<mathScore<<" "
        <<fixed<<setprecision(2)<<chineseScore<<" "
        <<fixed<<setprecision(2)<<totalScore<<endl;
    }
    //下面三个函数是对所有学生进行操作的 设计为静态成员函数
    //平均分函数
    static double getAverage(const vector<Student>& stuList){
        double sum = 0.0;
        for(int i = 0;i<stuList.size();i++){
            sum += stuList[i].totalScore;
        }
        return sum/stuList.size();
    }
    //返回分数最高学生信息的函数
    static void displayHighest(const vector<Student>& stuList){
        int maxIndex = 0;
        for(int i = 1;i<stuList.size();i++){
            if(stuList[i].totalScore>stuList[maxIndex].totalScore){
                maxIndex =  i ;
            }
        }
        cout<<"最高分学生: ";
        Student highest = stuList[maxIndex];
        highest.display();
    }
    static void SortStudents(vector<Student>&stuList){
        int n = stuList.size();
        for(int i = 0;i<n-1;i++){
            for(int j = 0;j<n-i-1;j++){
                if(stuList[j].totalScore>stuList[j+1].totalScore){
                    Student temp = stuList[j];
                    stuList[j] = stuList[j+1];
                    stuList[j+1] = temp;
                }
            }
        }
    }
};
int main(){
    int N;
    cin>>N;
    vector<Student> students;
    string id,name;
    double math,chinese;
    int age;
    char sex;
    for(int i = 0;i<N;i++){
        cin>>id>>name>>math>>chinese>>age>>sex;
        Student tempStudent(id,name,math,chinese,age,sex);
        students.push_back(tempStudent);
    }
    //调用友元函数还是要说明类名
    cout<<"平均分: "<<fixed<<setprecision(2)<<Student::getAverage(students)<<endl;
    Student::displayHighest(students);
    Student::SortStudents(students);
    cout<<"排序后的学生信息: "<<endl;
    for(int i = 0;i<N;i++){
        students[i].display();
    }
    return 0;
    
}