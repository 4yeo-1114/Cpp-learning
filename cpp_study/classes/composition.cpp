/* C++ | classes: composition. */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Container{
    protected:
        static double pi;
    public:
        virtual double area() = 0;
        virtual double volume() = 0;
        static double sumofarea(Container*c[],int n){
            double sum = 0.0;
            for(int i = 0;i<n;i++){
                sum += c[i]->area();
            }
            return sum;
        }

        static double sumofvolume(Container*c[],int n){
            double sum = 0.0;
            for(int i = 0;i<n;i++){
                sum += c[i]->volume();
            }
            return sum;
        }
};
double Container::pi = 3.1415926;

class Cube:public Container{
    protected:
         double s;
    public:
        Cube(double _s):s(_s){}
        double area(){
            return s*s*6;
        }
        double volume(){
            return s*s*s;
        }
};

class Cylinder:public Container{
    protected:
        double r;
        double h;
    public:
        Cylinder(double _r, double _h):r(_r),h(_h){}
        double area(){
            return pi*r*r*2+pi*r*2*h;
        }
        double volume(){
            return pi*r*r*h;
        }
};

int main(){
    int n;
    cin >> n;
    vector<Container*> c;
    while (n--) {
        string type;
        cin >> type;
        if (type == "cube") {
            double s;
            cin >> s;
            c.push_back(new Cube(s));
        } else if (type == "cylinder") {
            double r, h;
            cin >> r >> h;
            c.push_back(new Cylinder(r, h));
        }
    }
    int cnt = c.size();
    // .data() 获取 vector 内部底层连续数组的首地址。
    // c 的类型是 vector<Container*>，所以 c.data() 返回 Container**。
    // sumofarea/sumofvolume 的形参是 Container* c[]（本质就是 Container**），
    // 不能直接传 vector 对象，必须用 .data() 掏出裸指针才能匹配。
    //静态函数调用要写类名
    cout << Container::sumofarea(c.data(), cnt) << endl;
    cout << Container::sumofvolume(c.data(), cnt) << endl;
    for (auto p : c)
        delete p;
    return 0;
}

/*
 * 笔记：sumofarea/sumofvolume 形参为何写 Container* c[] 而非 Container** c？
 *   两者完全等价 —— 函数参数中的 T arr[] 必定退化为 T*，
 *   再套一层：Container* c[] → Container** c。
 *   用 [] 只是语义提示："这是一个数组，不是随便的二级指针"。
 *   调用方 c.data() 返回 Container**，两种写法都能接。
 */

#if 0
// === 不用 vector 的版本 ===
int main(){
    int n;
    cin >> n;
    Container** c = new Container*[n];  // 动态分配指针数组
    int cnt = 0;                        // 用 cnt 记录实际数量，不动 n
    while (n--) {
        string type;
        cin >> type;
        if (type == "cube") {
            double s;
            cin >> s;
            c[cnt++] = new Cube(s);
        } else if (type == "cylinder") {
            double r, h;
            cin >> r >> h;
            c[cnt++] = new Cylinder(r, h);
        }
    }
    cout << Container::sumofarea(c, cnt) << endl;
    cout << Container::sumofvolume(c, cnt) << endl;
    for (int i = 0; i < cnt; i++)
        delete c[i];                    // 释放每个对象
    delete[] c;                         // 释放指针数组
    return 0;
}
#endif
