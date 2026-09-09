/* C++ | classes: student records. */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;
class Student{
    public:
        string name;
        int height;
        int weight;
   
    
};
Student dorms[1000005];
int main(){
    int n;
    cin>>n;
    string name,number;
    int height,weight;
    for(int i = 0;i<n;i++){
        cin>>number>>name>>height>>weight;
        int id = stoi(number);// 巧妙转化为数字下标
        // 如果新来的更高，全面接管该宿舍的信息
        if(height>dorms[id].height){
            dorms[id].height = height;
            dorms[id].weight = weight;
            dorms[id].name = name;
        }
    }
    for(int i = 0 ;i<1000005;i++){
        if(dorms[i].height==0) continue;// 没人住的宿舍跳过
        else{
            cout<<setfill('0')<<setw(6)<<i<<" "<<dorms[i].name<<" "<<dorms[i].height<<" "<<dorms[i].weight<<endl;
    
        }
    }
    return 0;
    
}

//用map
#include <iostream>
#include <string>
#include <map>     // 🌟 引入 map
#include <iomanip>
using namespace std;

class Student{
public:
    string name;
    int height;
    int weight;
};

int main(){

    int n;
    cin >> n;
    
    // 🌟 定义一个 map：键(Key)是宿舍号，值(Value)是学生信息
    map<int, Student> dorms; 
    
    string name, number;
    int height, weight;
    
    for(int i = 0; i < n; i++){
        cin >> number >> name >> height >> weight;
        int id = stoi(number);
        
        // 🌟 核心打擂台逻辑：
        // 1. 如果这个宿舍根本还没登记过人 (dorms.count(id) == 0)
        // 2. 或者新来的人比原来登记的人更高
        if(dorms.count(id) == 0 || height > dorms[id].height){
            dorms[id].height = height;
            dorms[id].weight = weight;
            dorms[id].name = name;
        }
    }
    // 🌟 遍历输出：map 已经按宿舍号从小到大排好序了！
    // 这里的 auto 会自动推导出 map 里的键值对类型
    // pair.first 就是宿舍号(Key)，pair.second 就是学生(Value)
    for(auto& pair : dorms){ 
        cout << setfill('0') << setw(6) << pair.first << " "
             << pair.second.name << " " 
             << pair.second.height << " " 
             << pair.second.weight << "\n";
    }
    return 0;
}