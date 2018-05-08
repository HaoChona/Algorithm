
/*
 知识点：
 函数 Swap 对在一个数组中的两个数进行交换
 函数 max_heapify 作用建立最大堆，使其 根节点大于它的左右子节点。
 参数 ”*A“ 传入的数组  参数 ”i“ 为根节点的数值下标索引 参数 ”len“ 为该数组的大小
 “l” 为父节点“i”对左孩子 “r“为父节点”i“对右孩子。
 函数 build_heap 维护最大堆
 参数 ”*A“ 传入的数组 参数 ”len“ 传入数组的大小。
 函数 heapsort 建立一个从小到大的序列。
 参数 “*A” 传入的数组 参数 ”len“ 传入数组的大小。
 通过build_heap函数维护最大堆使其最大根节点为所有节点的最大值。
 之后通过Swap函数与最后一位数交换 之后数组的大小的参数“len” 减 一。
 
 */

#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <cstdio>
#include <climits>
using namespace std;

#define MAXN 1005


class heap_sort {
private:
    
public:
    void Swap(int &a,int &b)
    {
        int temp;
        temp=a;
        a=b;
        b=temp;
    }
    
    void max_heapify(int *A , int i, int len){
        int l = 2 * i;
        int r = 2 * i + 1;
        int largest;
        if (l <= len && A[i] < A[l]){
            largest = l;
        }
        else{
            largest = i;
        }
        if (r <= len && A[largest] < A[r])
            largest = r;
        if (largest != i){
            Swap(A[largest], A[i]);
            max_heapify(A,largest,len);
        }
    }
    
    void build_heap(int *A ,int len){
        for (int i = len/2; i >= 1; i--){
            max_heapify(A, i, len);
        }
    }
    
    void heapsort(int *A,int len){
        build_heap(A, len);
        for ( int i=len; i>=2; i--){
            Swap(A[i], A[1]);
            len = len -1;
            max_heapify(A, 1, len);
        }
    }
};

int main(int argc, const char * argv[]) {
    freopen("/Users/kangweihao/Desktop/C_OR_C++/in.txt","r",stdin);
    int arr[15];
    for(int i = 0; i <= 10; i++)
        cin >> arr[i];
    heap_sort ans;
    ans.heapsort(arr, 10);
    for(int i = 1; i <= 10; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
