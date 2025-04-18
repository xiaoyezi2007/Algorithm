#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int flag=0;
void dfs(int a[9][9],int k)
{
    if(flag==1) return;
    if(k==81)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++) printf("%d ",a[i][j]);
            puts("");
        }
        flag=1;
        return;
    }
    if(a[k/9][k%9]!=0)
    {
        dfs(a,k+1);
        return;
    }
    else
    {
        int re[10]= {0};
        for(int i=0; i<9; i++)
        {
            re[a[k/9][i]]=1;
            re[a[i][k%9]]=1;
        }
        for(int i=3*((k/9)/3); i<=(3*((k/9)/3)+2); i++)
        {
            for(int j=3*((k%9)/3); j<=(3*((k%9)/3)+2); j++)
            {
                re[a[i][j]]=1;
            }
        }
        for(int i=1; i<=9; i++)
        {
            if(re[i]==0)
            {
                int b[9][9]={0};
                for(int h=0;h<9;h++)
                {
                    for(int j=0;j<9;j++)
                    {
                        b[h][j]=a[h][j];
                    }
                }
                b[k/9][k%9]=i;
                dfs(b,k+1);
            }
        }
        return;
    }
}
int main()//输入格式为一行9个数，输入9行，空格以0代替
{
    int a[9][9]= {0};
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    puts("");
    dfs(a,0);
}
