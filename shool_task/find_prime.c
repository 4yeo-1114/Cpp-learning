#include <stdio.h>
int is_prime(int n){
    if(n<2) return 0;
    if(n==2) return 1;
    if(n%2==0){
        return 0;
    }
    for(int i = 2;i*i<=n;i=i+2){
        if(n%i==0){
            return 0;
        }

    }
    return 1;
}
int main(){
    int p;
    scanf("%d",&p);
    for(int i = p+1;;i++){
        if(i%2!=0 && is_prime(i)){
            printf("%d",i);
            break;

        }

    }
    return 0;

}