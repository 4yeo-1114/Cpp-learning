/* C++ | templates: vector. */

#include <iostream>
using namespace std;

template <typename T>
class Vector{
    private:
        T a[100000];
        int index = 0;
    public:
        int add(T num){
            a[index++]  = num;
            //放回插入位置
            return index-1;
        }
        int get_size(){
            return index;
        }
        T operator[](int i){
            return a[i];
        }
        void remove(int i){
            //越界保护
            if(i < 0 || i >= index) return;
            for(int j = i; j < index - 1; j++){
                a[j] = a[j+1];
            }
            index--;
        }
        Vector& operator=(const Vector& other){
            if(this != &other){
                index = other.index;
                for(int i = 0; i < index; i++){
                    a[i] = other.a[i];
                }
            }
            return *this;
        }
};

int main()
{
    Vector<int> vint;
    int n,m;
    cin >> n >> m;
    for ( int i=0; i<n; i++ ) {
        //    add() can inflate the vector automatically
        vint.add(i);    
    }
    //    get_size() returns the number of elements stored in the vector
    cout << vint.get_size() << endl;
    cout << vint[m] << endl;
    //    remove() removes the element at the index which begins from zero
    vint.remove(m);
    cout << vint.add(-1) << endl;
    cout << vint[m] << endl;
    Vector<int> vv = vint;
    cout << vv[vv.get_size()-1] << endl;
    vv.add(m);
    cout << vint.get_size() << endl;
}
