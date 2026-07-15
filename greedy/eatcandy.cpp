#include <iostream>
using namespace std;
long long n,x;
long long a[100000];
long long ans;
//贪心思想就是有多的就减右边的 因为右边的会影响后面的
int main(){
    cin>>n>>x;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i]+a[i-1]>x){
            ans += (a[i]+a[i-1])-x;
            a[i]  -= (a[i]+a[i-1])-x;
        }
    }
    cout<<ans;
    return 0;
}