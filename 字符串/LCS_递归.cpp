/*
@author:Hao Chona
@file: LCS_递归.cpp
@time: 2018-01-28 21:03:53
@Contact: hao_chona@163.com
@Description: LCS 通过递归的方式求 最长公共子序列长度
@Explanation:


*/

# include <iostream>
# include <stdio.h>
# include <string>

using namespace std;

string str1,str2;
int LCS(int m, int n){
	if (m == -1 || n == -1)
		return 0;
	if (str1[m] == str2[n]){
		return LCS(m-1, n-1) + 1;
	}
	if (str1[m] != str2[n])
		return LCS(m-1, n) > LCS(m, n-1) ? LCS(m-1, n):LCS(m, n-1);
}
int main(){
	cin >> str1 >> str2;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << LCS(str1.size()-1, str2.size()-1) << endl;
	return 0;
}

