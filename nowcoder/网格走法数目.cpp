
//
//  main.cpp
//  C++_Project
//
//  Created by 康伟豪 on 2017/9/21.
//  Copyright © 2017年 康伟豪. All rights reserved.
//
/*
 题目描述
 有一个X*Y的网格，小团要在此网格上从左上角到右下角，只能走格点且只能向右或向下走。请设计一个算法，计算小团有多少种走法。给定两个正整数int x,int y，请返回小团的走法数目。
 输入描述:
 输入包括一行，逗号隔开的两个正整数x和y，取值范围[1,10]。
 输出描述:
 输出包括一行，为走法的数目。
 示例1
 输入
 
 3 2
 输出
 
 10
 */

/*
 知识点：
 dp方程 f(r,c)=f(r-1,c) + f(r,c-1)
 */
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
class Solution {
public:
    int function(int r, int c){
        if (r==0 && c==0) return 0;
        if (r==0 && c==1) return 1;
        if (r==1 && c==0) return 1;
        if (r==0) return function(r, c-1);
        if (c==0) return function(r-1, c);
        else
            return function(r-1, c) + function(r, c-1);
    }
};

int main(int argc, const char * argv[]) {
// insert code here...
//    freopen("/Users/kangweihao/Desktop/C/in.txt","r",stdin);
    Solution ans;
    int r,c;
    cin >> r >> c;
    int sum = ans.function(r, c);
    cout << sum << endl;
    return 0;
}
