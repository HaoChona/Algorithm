//
//  main.cpp
//  C++_Project
//
//  Created by 康伟豪 on 2017/9/21.
//  Copyright © 2017年 康伟豪. All rights reserved.
//
/*
 题目描述
 游戏里面有很多各式各样的任务，其中有一种任务玩家只能做一次，这类任务一共有1024个，任务ID范围[1,1024]。请用32个unsigned int类型来记录着1024个任务是否已经完成。初始状态都是未完成。 输入两个参数，都是任务ID，需要设置第一个ID的任务为已经完成；并检查第二个ID的任务是否已经完成。 输出一个参数，如果第二个ID的任务已经完成输出1，如果未完成输出0。如果第一或第二个ID不在[1,1024]范围，则输出-1。
 输入描述:
 输入包括一行,两个整数表示人物ID.
 输出描述:
 输出是否完成
 示例1
 输入
 
 1024 1024
 输出
 
 1
 */

/*
 知识点：
 运算符 含义        运算对象个数    结合方向    优先级
 
 ~     按位求反     单目运算符     自右向左    1
 
 <<    按位左移     双目运算符     自左向右    2
 
 >>    按位右移     双目运算符     自左向右    2
 
 &     按位与       双目运算符     自左向右    3
 
 |     按位或       双目运算符     自左向右    4
 
 ^     按位异或     双目运算符      自左向右   5
 
 
 */

#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
class Solution {
private:
    unsigned int bitmap[32];
public:
    int function(int x, int y){
        if (!(y>=1 && y<=1024)) return -1;
        memset(bitmap, 0, sizeof(bitmap));
        bitmap[(x-1)>>5] |= 1 << (x&31);
        int flag;
        flag = ((bitmap[(y-1)>>5] & (1 << (y&31))) != 0);
        return flag;
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
