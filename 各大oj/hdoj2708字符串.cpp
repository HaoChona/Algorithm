#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
void print(int num)
{
     for (int i = 0; i < num; i++)
          printf(" ");
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    char str[100],s[100][1000];
    int b[50];
    while(gets(str))
    {
        memset(b,0,sizeof(b));
        memset(s,0,sizeof(s));
        for (int i = 0; str[i]; i++)
        {
               if (str[i] >= 'A'&&str[i] <= 'Z')
               b[str[i] - 'A']++;
          }
          for (int j = 0; j < 3; j++)
        {
               gets(str);
               for (int i = 0; str[i]; i++)
               {
                    if(str[i]>='A'&&str[i]<='Z')
                         b[str[i] - 'A']++;
               }
          }
        int sum=0;
        for(int i=0;i<26;i++)
        {
            if(sum<=b[i])
                sum=b[i];
        }
        for(int i=sum;i>=1;i--)
        {
            int num=0;//精髓，定义num=0；后面调用print函数，来确定有几个空格，来完成'\0';
            for(int j=0;j<=26;j++)
            {
                if(b[j]>=i)
                {
                    print(num);
                    num=0;
                    printf("*");
                }
                else
                    num++;
                if(j!=25)
                    num++;
            }
            printf("\n");
        }
        for(int i='A';i<='Z';i++)
        {
            printf("%c",i);
            if(i!='Z')
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}