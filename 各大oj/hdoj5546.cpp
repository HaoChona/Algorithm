#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

char maps[10][10];
int vis[10][10];
int vi[10][10];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int sum=0;
int check(int x,int y){
    if(x<0 || y<0 || x>=9 || y>=9)
        return 1;
    else
        return 0;
}
void dfs(int x,int y){

    for(int i=0;i<4;i++){
        int mx=x+dx[i];
        int my=y+dy[i];
        if(check(mx,my)==0 && maps[mx][my]=='.'&&!vis[mx][my]){
            vis[mx][my]=1;
            sum++;
        }
    }
    for(int i=0;i<4;i++){
        int mx=x+dx[i];
        int my=y+dy[i];
        if(check(mx,my)==0 && maps[mx][my]=='o'&&!vi[mx][my]){
            vi[mx][my]=1;
            dfs(mx,my);
        }
    }


}
int main(){

    int T;
    scanf("%d",&T);
    getchar();
    int tot=1;
    while(T--){
        memset(maps,0,sizeof(maps));

        memset(vi,0,sizeof(vi));
        for(int i=0;i<9;i++){
            scanf("%s",maps[i]);
        }
//        for(int i=0;i<9;i++){
//            printf("%s",maps[i]);
//            cout<<endl;
//        }
        int flag=0;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(maps[i][j]=='o'&&!vi[i][j]){
                    memset(vis,0,sizeof(vis));
                    sum=0;
                    vi[i][j]=1;
                    dfs(i,j);
                    if(sum==1){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag)
                break;
        }
        if(flag)
            printf("Case #%d: Can kill in one move!!!\n",tot++);
        else
            printf("Case #%d: Can not kill in one move!!!\n",tot++);


    }
    return 0;
} 