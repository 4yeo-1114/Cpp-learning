#include <stdio.h>

int main(){
    int n,m,a,b;
    scanf("%d %d %d %d",&n,&m,&a,&b);
    if(m>n){
        printf("%d",a*n);
        return 0;
    }
    if(a*m<=b){
         printf("%d",a*n);
    }
    else{
        int count  = n/m;
        int cost  = b*count + a*(n-count*m);
        printf("%d",cost);

    }
    return 0;



}