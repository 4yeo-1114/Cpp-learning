#include <iostream>
#include <cstring>
using namespace std;


class MyString{
    private:
        char* m_str;
         int m_size;
    public:
        MyString(){
            m_str = new char[1];
            m_str[0] = '\0';
            m_size = 0;
        }
        MyString(const char* buf){
            int len = strlen(buf);
            m_str = new char[len+1];
            strcpy(m_str,buf);
            m_str[len] = '\0';
            m_size = len;
        }
        MyString(MyString& s){
            m_str = new char[s.m_size+1];
            m_str[s.m_size]  = '\0';
            strcpy(m_str,s.m_str);
            m_size = s.m_size;
        }
        MyString operator+(const MyString& s){
            MyString ans;
            //释放掉默认申请的1字节
            delete[] ans.m_str;
            ans.m_size = this->m_size+s.m_size;
            ans.m_str = new char[ans.m_size+1];
            strcpy(ans.m_str,this->m_str);
            strcat(ans.m_str,s.m_str);
            //用strcat了就不用补零了
            return ans;
        }
        MyString& operator=(const MyString& s){
            //如果自己等于自己 不用赋值
            if(this==&s){
                return *this;
            }
            else{
                delete[] m_str;
                m_str = new char[s.m_size+1];
                m_size = s.m_size;
                strcpy(m_str,s.m_str);
                m_str[s.m_size] = '\0';
            }
            return *this;
        }
        friend ostream& operator<<(ostream&out,const MyString& s){
            out<<s.m_str;
            return out;
        }
        ~MyString(){
            if(m_str!=NULL){
                delete[]  m_str;
                m_str = NULL;
            }
        }


};

int main() {
    char buf1[100], buf2[100];
    // 读取两行输入
    cin.getline(buf1, 100);
    cin.getline(buf2, 100);

    MyString s1(buf1);
    MyString s2(buf2);

    // 依次输出：s1, s2, s1+s2, 以及拷贝构造的s3(s1)
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s1 + s2 << endl;
    
    MyString s3(s1);
    cout << s3 << endl;

    return 0;
}

//MyStirng 实现字符串提取
#include <iostream>
#include <string>
using namespace std;

class MyString: public string{
    public:
    //默认构造函数
     MyString():string(){}
     //接收c语言风格字符串 const兼容“Hello”这种字面量
     MyString(const char* str):string(str){}
     MyString(const string& str):string(str){}

     //重载（）
    MyString operator()(int start,int len)const{
        //直接调用父类substr方法
        //substr会返回一个string 再用他构造一个MyString返回
        return MyString(this->substr(start,len));
    }


};

int main() {
    string inputStr;
    // 读取包含空格的整行字符串
    getline(cin, inputStr);
    
    int start, len;
    cin >> start >> len;

    // 将输入字符串转为自定义的 MyString 对象
    MyString ms = inputStr;
    
    // 调用重载的 operator() 并输出结果
    cout << ms(start, len) << endl;

    return 0;
}