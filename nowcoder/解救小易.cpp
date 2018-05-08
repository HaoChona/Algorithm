//
//  main.cpp
//  C++_Project
//
//  Created by 康伟豪 on 2017/9/21.
//  Copyright © 2017年 康伟豪. All rights reserved.
//
/*
 题目描述
 有一片1000*1000的草地，小易初始站在(1,1)(最左上角的位置)。小易在每一秒会横向或者纵向移动到相邻的草地上吃草(小易不会走出边界)。大反派超超想去捕捉可爱的小易，他手里有n个陷阱。第i个陷阱被安置在横坐标为xi ，纵坐标为yi 的位置上，小易一旦走入一个陷阱，将会被超超捕捉。你为了去解救小易，需要知道小易最少多少秒可能会走入一个陷阱，从而提前解救小易。
 输入描述:
 第一行为一个整数n(n ≤ 1000)，表示超超一共拥有n个陷阱。
 第二行有n个整数xi，表示第i个陷阱的横坐标
 第三行有n个整数yi，表示第i个陷阱的纵坐标
 保证坐标都在草地范围内。
 输出描述:
 输出一个整数,表示小易最少可能多少秒就落入超超的陷阱
 示例1
 输入
 
 3
 4 6 8
 1 2 1
 输出
 
 3
 */

/*
 知识点：
 
 
 */

#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <cstdio>
#include <climits>
using namespace std;

#define MAXN 1005
class Solution {
private:
    int res = INT_MAX;
public:
    int function(int *x, int *y, int n){
        for (int i = 0; i < n; i++){
            res = min(res,x[i]+y[i]-2);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
// insert code here...
//    freopen("/Users/kangweihao/Desktop/C/in.txt","r",stdin);
    Solution ans;
    int n;
    int x[1005];
    int y[1005];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
    for (int i = 0; i < n; i++){
        cin >> y[i];
    }
    int res = ans.function(x, y, n);
    cout << res << endl;
    return 0;
}
