/* C++ | stl: membership check. */
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <set>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    set<string> id;
    vector<string> e;
    for(int i = 0;i<n;i++){
        string name;
        cin>>name;
        id.insert(name); //id.insert(name) set的插入操作
    }
    for(int i = 0;i<k;i++){
        string name;
        cin>>name;
        if(id.find(name)==id.end()){
            m--;
            e.push_back(name);
        }
    }
    if(n%k==0){
        cout<<n/k<<endl;
    }
    else cout<<(n/k)+1<<endl;

    cout<<m<<endl;
    if(e.size()>0){
        for(int i = 0;i<e.size();i++){
        cout<<e[i];
        if(i!=e.size()-1) cout<<" ";
        }

    }
    else cout<<"All Passed!";
   
}