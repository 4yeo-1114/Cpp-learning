/* C++ | memory: string. */
#include <iostream>
#include <cstring>
using namespace std;

class MyString {
public:
    // 无参构造函数
    // 空字符串可以考虑使用new char[1]，并设置字符串结束符
    MyString();
    // 构造函数，传入一个C语言风格字符串
    MyString(const char *s);
    // 拷贝构造函数
    MyString(const MyString &s);
    // 析构函数
    ~MyString();
    // 返回子串 [pos, pos+count)
    // 若pos不在字符串的下标范围内，返回空的MyString对象
    // 若请求的子串越过字符串的结尾，即count大于size() - pos，则返回的子串为[pos, size()) 
    // 若count == -1，返回子串[pos, size())
    // 可以考虑使用strncpy
    MyString substr(int pos = 0, int count = -1);
    // 返回下标为pos的字符的引用
    char& at(int pos);
    // 字符串的长度
    int size();
    // 返回C语言风格的字符串
    const char* c_str();
private:
    char *m_buf;
    int m_size;
};

// 请将答案填写在这里

int main() {
    char s[101];
    cin.getline(s, 101);//cin.getline
    int pos, count;
    cin >> pos >> count;
    // 创建、拷贝、空字符串
    MyString s1(s), s2(s1), s3;
    s1.at(0) = 'x';
    s2.at(0) = 'X';
    cout << "s1: " << s1.c_str() << endl;
    cout << "s2: " << s2.c_str() << endl;
    cout << "s3: " << s3.c_str() << endl;
    // 取子串
    cout << "substr: " << s2.substr(pos, count).c_str() << endl;
    // 以后还可以直接使用<<输出一个MyString对象哦 TODO
    // cout << s1 << endl;
    return 0;
}
MyString::MyString(){
    m_buf = new char[1];
    m_buf[0] = '\0';
    m_size = 0;
}
MyString::MyString(const char*s){
         int len = strlen(s);
        //要先分配地址！！
        m_buf = new char[len+1];
        strcpy(m_buf,s); 
        m_buf[len] = '\0';
        m_size = len;
}
MyString::MyString(const MyString &s){
    m_buf = new char[s.m_size+1];
    strcpy(m_buf,s.m_buf); 
    m_buf[s.m_size] = '\0';
    m_size = s.m_size;
}

MyString::~MyString(){
        delete[] m_buf;
}
//默认参数只在声明中写
MyString MyString::substr(int pos,int count){
    if(pos<0||pos>=m_size){
        return MyString();
    }
    //计算真正要截取的长度
    int actual_count= count;
    if(count<0||count>m_size-pos){
        actual_count = m_size  - pos;
    }
    //加一是为了装结尾的\0
    char* temp = new char[actual_count+1];
    strncpy(temp,m_buf+pos,actual_count); 
    temp[actual_count] = '\0';
    //构建一个新的MYString返回
    MyString result(temp);
    delete[] temp;
    return result;
}
//返回引用这样就不用再复制了
char& MyString::at(int pos){
    char& c = m_buf[pos];
    return c;
}
int MyString::size(){
    return m_size;
}
const char* MyString::c_str(){
    return m_buf;
}