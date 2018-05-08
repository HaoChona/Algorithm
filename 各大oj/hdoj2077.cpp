#include<stdio.h>
int main()
{
int t,n;
long a[25]={0,2,4,10,28,82,244,730,2188,6562,19684,59050,177148,531442,1594324,4782970,14348908,43046722,129140164,387420490,1162261468};/*通过打表的，值赋值个数组*/
scanf("%d",&t);
while(t--)
{
scanf("%d",&n);
printf("%ld\n",a[n]);
}
return 0;
}

打表的代码
#include<iostream>
using namespace std;
#include<stdio.h>

int main()
{
freopen("out.txt","w",stdout);
long a[25];
a[1]=2;
a[2]=4;
for(int i=3;i<=20;++i)
{
a[i]=(4*a[i-1])-(3*a[i-2]);
}
for(int i=1;i<=20;++i)
printf("%ld,",a[i]);
return 0;
}