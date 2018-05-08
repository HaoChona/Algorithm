#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cctype>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <climits>
#include <sstream>
#include <cmath>

using namespace std;

typedef struct homework hk;
struct homework {
    int deadline;
    int scores;
};


bool cmp(hk a, hk b){

   if ( a.scores != b.scores )
     {
         return a.scores > b.scores ;
     }
     else
     {
         return a.deadline < b.deadline;
     }

    return false;
}


int main(){
#ifdef ONLINE_JUDGE
#else

    freopen("d:/a.txt","r",stdin);
    //freopen("d:/a.txt","w",stdout);
#endif
    int t;
    hk a[1000];
    int vis[1000];
    cin >> t;
    while( t-- ){

        memset(a,0,sizeof(hk));
        memset(vis,0,sizeof(vis));
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){

            cin >> a[i].deadline;
        }
        for(int i=1;i<=n;i++){

            cin >> a[i].scores;
        }

        sort(a+1,a+n+1,cmp);
//        for(int i=1;i<=n;i++){
//
//            cout << a[i].deadline << " ";
//        }
//        cout << endl;
//        for(int i=1;i<=n;i++){
//
//            cout << a[i].scores << " ";
//        }
//        cout << endl;
//        cout << endl;
        int sum=0;
        for(int i=1;i<=n;i++){

            int j;
            for(j=a[i].deadline;j>=1;--j){

                if(!vis[j]){

                    vis[j]=1;
                    break;
                }
            }

            if(!j){

                sum += a[i].scores;
            }
        }

        cout << sum << endl;
    }

    return 0;
}