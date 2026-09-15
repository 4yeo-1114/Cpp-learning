#include <stdio.h>

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    int c = a%b;
    a = b;
    b = c;
    return gcd(a,b);
}

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int ans = gcd(a,b);
    printf("%d",ans);
    return  0;


}
