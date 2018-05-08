//
//  main.cpp
//  C++_Project
//
//  Created by 康伟豪 on 2017/9/21.
//  Copyright © 2017年 康伟豪. All rights reserved.
//
// 题目描述
// 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
    public:
        bool Find(int target, vector<vector<int> > array) {
            long row = 0;
            long col = array[0].size() - 1;
            while(row <= array.size()-1 && col >= 0){
                if(target == array[row][col]) return true;
                else if(target > array[row][col]) row++;
                else if(target < array[row][col]) col--;
            }
            return false;
        }
};

int main(int argc, const char * argv[]) {
// insert code here...
    freopen("/Users/kangweihao/Desktop/C/in.txt","r",stdin);
    Solution ans;
    int target,row,col,num;
    vector< vector<int> > array;
    vector<int> temp;
    cin >> target >> row >> col;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> num;
            temp.push_back(num);
        }
        array.push_back(temp);
        temp.clear();
    }
    cout << ans.Find(target, array) << endl;
    return 0;
}
