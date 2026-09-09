/* C | dp: triangle min path. */
//用动态矩阵 
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
	int f[triangleSize][triangleSize];
	memset(f,0,sizeof(f));
	f[0][0] = triangle[0][0];
	for(int i = 1;i<triangleSize;i++){
		f[i][0] = f[i-1][0]  + triangle[i][0];
		for(int  j = 1;j<i;j++){
			f[i][j] =  fmin(f[i-1][j-1],f[i-1][j]) + triangle[i][j];
		}
		f[i][i] = f[i-1
		][i-1] + triangle[i][i];
	}
	int ret = 0;
	for(int i = 0;i<triangle;i++){
		ret = fmin(ret,f[triangle-1][i]);
	}
 
	return ret;
}







int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
	int f[triangleSize];
	f[0] = triangle[0][0];
	for(int i = 1; i<triangleSize;i++){
		f[i] =   f[i-1] + triangle[i][i];
	
		for(int j = i-1;j>0;j--){
			f[j] =fmin(f[j],f[j-1]) + triangle[i][j];
		} 
	f[0] +=  triangle[i][0];
	}
		
	int ret  = f[0];
	for(int i =1 ;i<trianleSize;i++){
		ret = fmin(f[i],ret);
	}
	return ret;
}
//为什么只有在递减地枚举 j 时，才能省去一个一维数组？当我们在计算位置 (i,j) 时，f[j+1] 到 f[i] 已经是第 i 行的值，
//而 f[0] 到 f[j] 仍然是第 i-1 行的值。此时我们直接通过
//f[j]=min(f[j-1],f[j])+c[i][j]
//进行转移，恰好就是在 (i-1,j-1) 和 (i-1,j) 中进行选择。但如果我们递增地枚举 j，那么在计算位置 (i,j) 时，f[0] 到 f[j-1] 已经是第 i 行的值。
//如果我们仍然使用上述状态转移方程，那么是在 (i,j-1) 和 (i-1,j) 中进行选择，就产生了错误。
//链接：https://leetcode.cn/problems/triangle/solutions/329143/san-jiao-xing-zui-xiao-lu-jing-he-by-leetcode-solu/


//用二维数组来做 因为我们只看前一行 
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
	// fmin函数 
    int f[2][triangleSize];
    memset(f, 0, sizeof(f));
    f[0][0] = triangle[0][0];
    for (int i = 1; i < triangleSize; ++i) {
        int curr = i % 2;
        int prev = 1 - curr;
        f[curr][0] = f[prev][0] + triangle[i][0];
        for (int j = 1; j < i; ++j) {
            f[curr][j] = fmin(f[prev][j - 1], f[prev][j]) + triangle[i][j];
        }
        f[curr][i] = f[prev][i - 1] + triangle[i][i];
    }
    int ret = f[(triangleSize - 1) % 2][0];
    for (int i = 1; i < triangleSize; i++)
        ret = fmin(ret, f[(triangleSize - 1) % 2][i]);
    return ret;
}

// 最佳代码 从底到顶
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
	int *f = (int*)malloc(triangleSize * sizeof(int));
	for(int i = 0;i<triangleSize;i++){
		f[i] = triangle[triangleSize-1][i];//初始数组等于底部的数组 
	} 
	for(int j = triangleSize - 2;j>=0;j--){//从倒数第二行开始到最上面 
		for(int k = 0;k<=j;k++){ 
			f[k] = fmin(f[k],f[k+1]) + triangle[j][k];
		}
	}
	return f[0];
	
}
//原地dp
for(int i = n-2;i>=0;i--){
	for(int j = 0;j<=i;j++){
		triangle[i][j] += fmin(triangle[i+1][j],triangle[i+1][j+1]);
	}
}
return triangle[0][0];
