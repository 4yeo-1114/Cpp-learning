#include <string.h>
class IntArray{
    int *a;
    int n;
    public:
        IntArray(int n = 1):n(n){
            a = new int[n];
            for(int i= 0 ;i<n;i++) a[i] = i;
        }
        ~IntArray(){
            delete[] a;
        }
        IntArray& operator = (const IntArray&other){
            if(this!=&other){
                delete[]a;
                n = other.n;
                a = new int[n];
                memcpy(a,other.a,sizeof(int)*n);
            }
            return *this;
        }
        //拷贝构造函数
        IntArray(IntArray& other):n(other.n){
            a = new int[n];
            memcpy(a,other.a,sizeof(int)*n);
           
        } 
        

};


/*// 1. 高效实现 += 
赋值重载 一定要返回引用
Integer& operator+=(const Integer& other) {
    this->x += other.x; // 直接操作，没有临时对象
    return *this;
}

// 2. 让 + 去复用 +=
Integer operator+(const Integer& other) {
    Integer temp = *this; // 必须产生一个临时副本（因为加法不能改变原来对象的值）
    temp += other;        // 复用上面高效的 +=
    return temp;
}

*/

