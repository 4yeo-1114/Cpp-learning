/* C++ | enumeration: count rectangles. */
#include <iostream>
using namespace std;
long long n,m,sqr,rec;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j =0;j<m;j++){
			if(i==j) sqr += (n-i)*(m-j);
			else rec += (n-i)*(m-j);
		}
	}
	cout<<sqr<<" "<<rec<<endl;
	return 0;
}

//另外的做法
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	ll n,m,i,j,sum=0,sum1=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
	  for(j=1;j<=m;j++)
	  { //如果固定了正方形右下角（i，j）正方形个数是min(i,j) .
	    sum+=min(i,j);
	    sum1+=i*j;//矩形的个数为i*j. 
	  }
	}
	
	cout<<sum<<" "<<sum1-sum<<endl;
	return 0;
}
 

