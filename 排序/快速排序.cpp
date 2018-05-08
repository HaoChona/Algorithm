#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<cstdio>
#include<climits>
usingnamespacestd;
 
#define MAXN1005
 
 
classQuickSort {
private:
   
public:
   voidSwap(int&a,int&b)
    {
       inttemp;
        temp=a;
        a=b;
        b=temp;
    }
   intpartition(int*A,intp,intr){
       intx = A[r];
       inti = p -1;
       for(intj = p; j <= r-1; j++){
           if(A[j] <= x){
                i = i +1;
               Swap(A[i], A[j]);
            }
        }
       Swap(A[i+1], A[r]);
       returni+1;
    }
   voidquicksort(int*A,intp,intr){
       if(p < r){
           intq =partition(A, p, r);
           quicksort(A, p, q-1);
           quicksort(A, q+1, r);
        }
    }
};
 
int main(intargc,constchar* argv[]) {
// insert code here...
   freopen("/Users/kangweihao/Desktop/C_OR_C++/in.txt","r",stdin);
   intarr[15];
   for(inti =0; i <=7; i++)
       cin>> arr[i];
   QuickSortans;
    ans.quicksort(arr,0,7);
   for(inti =0; i <=7; i++)
       cout<< arr[i] <<" ";
   cout<<endl;
   return0;
} 