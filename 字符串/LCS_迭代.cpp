/*
@author:Hao Chona
@file: LCS_迭代.cpp
@time: 2018-01-24 21:52:43
@Contact: hao_chona@163.com
@Description: LCS迭代DP求最大公共子序列和长度



*/

# include <iostream>
# include <stdio.h>


using namespace std;

int LCS(string str1,string str2,int **a,int **b,int m,int n){
	/*处理特殊的0行和0列*/  
    for(int i=0;i<=m;i++)  
        a[i][0]=0;  
    for(int j=0;j<=n;j++)  
        a[0][j]=0;
	for (int i = 1; i <=m; i++)
		for (int j = 1; j <=n; j++){
			if (str1[i-1] == str2[j-1]){
				a[i][j] = a[i-1][j-1] + 1;
				b[i-1][j-1] = 0;
			}
			else{
				if (a[i-1][j] >= a[i][j-1]){
					a[i][j] = a[i-1][j];
					b[i-1][j-1] = 1;
				}
				else{
					a[i][j] = a[i][j-1];
					b[i-1][j-1] = -1;
				}
			}
		}
	return a[m][n];
}
void Print_LCS(int **b,string x,int i,int j) //输出LCS序列  
{  
    if(i==0 || j==0)  
        return ;  
    if(b[i-1][j-1] == 0)  
    {  
        Print_LCS(b,x,i-1,j-1);  
        cout<<x[i-1];  
    }  
    else if(b[i-1][j-1]==1)  
    {  
        Print_LCS(b,x,i-1,j);  
    }  
    else  
        Print_LCS(b,x,i,j-1);  
}  
int main(){
	freopen("./in.txt","r",stdin);
	string str1,str2;
	cin >> str1 >> str2;
	int m = str1.size(),n = str2.size();
	int **a=new int*[m+1]; //动态分配二维数组  
    for(int i=0;i<=m;i++)  
        a[i]=new int[n+1];  
    int **b=new int*[m]; //动态分配二维数组  
    for(int j=0;j<m;j++)  
        b[j]=new int[n];  
	cout << LCS(str1, str2, a, b, m, n) << endl;
	Print_LCS(b, str1, str1.size(), str2.size());
	cout << endl;
	return 0;
}

