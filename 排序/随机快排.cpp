//  main.cpp
//  C++_Project
//
//  Created by 康伟豪 on 2017/9/21.
//  Copyright © 2017年 康伟豪. All rights reserved.
//
///*
// 在大规模数据的情况下，随机快排会优于普通快排
// */
//
///*
// 知识点：
//
//
// */
//

#include <iostream>
#include <cstdio>
#include <ctime>
#include <stdlib.h>
#include <random>
using namespace std;

#define MAXN 1005

class QuickSort {
public:
    void Swap(int &a,int &b){
        int temp;
        temp=a;
        a=b;
        b=temp;
    }
    int randomized_partition(int *A, int p, int r){
        int i = rand()%(r-p+1)+p;
        Swap(A[i], A[r]);
        return partition(A, p, r);
    }
    
    int partition(int *A, int p, int r){
        int x = A[r];
        int i = p - 1;
        for (int j = p; j < r; j++){
            if (A[j] <= x){
                i = i + 1;
                Swap(A[i], A[j]);
            }
        }
        Swap(A[i+1],A[r]);
        return i+1;
    }
    
    void randomized_quicksort(int *A, int p, int r){
        if (p < r){
            int q = randomized_partition(A, p, r);
            randomized_quicksort(A, p, q-1);
            randomized_quicksort(A, q+1, r);
        }
    }
    
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    freopen("/Users/kangweihao/Desktop/C_OR_C++/in.txt","r",stdin);
    int arr[15];
    for(int i = 0; i <=  7; i++)
        cin >> arr[i];
    QuickSort ans;
    ans.randomized_quicksort(arr, 0, 7);
    for(int i = 0; i < 8; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}




