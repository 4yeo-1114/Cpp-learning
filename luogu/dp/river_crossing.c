/* C | dp: river crossing. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
//马可以走到的位置
int main(){
	int bx,by,mx,my;
	scanf("%d %d %d %d",&bx,&by,&mx,&my);
	//将整张地图都向右上角移动 防止数组下标出现负数 
	bx += 2; by+=2;mx+=2;my+=2;
	long long f[40][40];
	//为什么初始化f[2][1]想一下目的地在原地就只有一种走法 f[2][2] = f[2][1]+f[1][2] = 1
	f[2][1] = 1;
	bool s[40][40];
	s[mx][my] = 1;
	for(int i = 0;i<=8;i++) s[mx+fx[i]][my+fy[i]] = 1; //马可以走到的位置都记为1. 
	for(int i = 2;i<=bx;i++){
		for(int j = 2;j<=by;j++){
			if(s[i][j]) continue;// 如果被马拦住就直接跳过
			f[i][j] = f[i-1][j] + f[i][j-1];
		}
	} 
	
	printf("%lld", f[bx][by]);
	return 0;
}

//改成二维 
#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
//马可以走到的位置
int main(){
	int bx,by,mx,my;
	scanf("%d %d %d %d",&bx,&by,&mx,&my);
	bx+=2; by+=2;mx+=2;my+=2;
	bool s[40][40] ;
	s[mx][my] = 1;
	for(int i = 0 ;i<=8;i++){
		s[mx+fx[i]][my+fy[i]] = 1;
	}
	long long f[2][40];
	f[2][1] = 1;
	for(int i = 2;i<=bx;i++){
		for(int j = 2;j<=by;j++){
			if(s[i][j])  {
				f[i % 2][j] = 0;// 因为是滚动数组 , 所以如果当前位置被马拦住了一定要记住清零。
				continue;
			}
			f[i%2][j] = f[(i-1)%2][j] + f[i%2][j-1]; //这样就不用存储每一个点的情况 只要记两列就好了
			//其实就是分为奇数列和偶数列 因为递推最多用到左边一列 所以开两个数组就好了 
		}
	}
	printf("%lld",f[bx%2][by]);
	return 0;
}

//改成一维
int main(){
    read(bx, by); read(mx, my);
    bx += 2; by += 2; mx += 2; my += 2;
    f[2] = 1;   //初始化
    s[mx][my] = 1;
    for(int i = 1; i <= 8; i++) s[mx + fx[i]][my + fy[i]] = 1;
    for(int i = 2; i <= bx; i++){
        for(int j = 2; j <= by; j++){
            if(s[i][j]){
                f[j] = 0; // 还是别忘了清零
                continue;
            }
            f[j] += f[j - 1];//因为f(j)目前还是上一个i的值即左边的坐标，所以直接加下面的就好了 
            //全新的 简洁的状态转移方程
        }
    }
    printf("%lld\n", f[by]);
    return 0;
}  
 
