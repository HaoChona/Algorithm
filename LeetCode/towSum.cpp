//
//  main.cpp
//  C++_Project
//
//  Created by 康伟豪 on 2017/9/21.
//  Copyright © 2017年 康伟豪. All rights reserved.
//
// 题目
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:
// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

//
//  main.cpp
//  C++_Project
//
//  Created by 康伟豪 on 2017/9/21.
//  Copyright © 2017年 康伟豪. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        //Key is the number and value is its index in the vector.
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++) {
            int numberToFind = target - numbers[i];
            
            //if numberToFind is found in map, return them
            if (hash.find(numberToFind) != hash.end()) {
                //+1 because indices are NOT zero based
                result.push_back(hash[numberToFind]);
                result.push_back(i);
                return result;
            }
            
            //number was not found. Put it in the map.
            hash[numbers[i]] = i;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
//    freopen("/Users/kangweihao/Desktop/C/in.txt","r",stdin);
    Solution ans;
    vector<int> numbers;
    vector<int> result;
    int a,num;
    cin>>num;
    for(int i=0; i<num; i++){
        cin>>a;
        cout<<a<<endl;
        numbers.push_back(a);
    }
    int target;
    cin>>target;
    result=ans.twoSum(numbers, target);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }
    return 0;
}
