#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define min2(a,b) ((a)<(b)?(a):(b))
int d[1000][1000];
int line[1000][1000];
char name[1000][100];
int path[1000][1000];
int s[1000];
int id[1000];
int main()
{
    FILE *in=fopen("bgstations.txt","r");
    int n;
    fscanf(in,"%d",&n);
    int k=0;
    for(int i=1;i<=n;i++)
    {
        int l,z;
        fscanf(in,"%d%d",&l,&z);
        int last=-1;
        for(int j=0;j<z;j++)
        {
            char temp[100];

            int op;
            fscanf(in,"%s%d",temp,&op);
            if(op==0)
            {
                strcpy(name[k],temp);
                if(last!=-1)
                {
                    d[last][k]=d[k][last]=1;
                    line[last][k]=line[k][last]=l;
                }

                last=k;
                k++;
            }
            else
            {
                int now=k;
                for(int h=0;h<k;h++)
                {
                    if(strcmp(name[h],temp)==0)
                    {
                        now=h;
                        break;
                    }
                }
                if(now==k)
                {
                    strcpy(name[k],temp);
                    k++;
                }
                if(last!=-1)
                {
                    d[last][now]=d[now][last]=1;
                    line[last][now]=line[now][last]=l;
                }
                last=now;

            }
        }
    }
    char from[100];
    char to[100];
    scanf("%s%s",from,to);
    int a,b;
    for(int i=0;i<k;i++)
    {
        if(strcmp(from,name[i])==0)
        {
            a=i;
        }
        if(strcmp(to,name[i])==0)
        {
            b=i;
        }
    }
    s[a]=1;
    id[a]=0;
    for(int i=0;i<k;i++)
    {
        path[i][0]=1;
        path[i][1]=a;
    }
    for(int i=0;i<k;i++)
    {
        if(d[a][i]==1)
        {
            id[i]=1;
        }
    }
    while(s[b]==0)
    {
        int min=999999;
        int minsta=-1;
        for(int i=0;i<k;i++)
        {
            if(s[i]==0&&id[i]!=0&&id[i]<min)
            {
                min=id[i];
                minsta=i;
            }
        }
        s[minsta]=1;
        path[minsta][0]++;
        path[minsta][path[minsta][0]]=minsta;
        for(int i=0;i<k;i++)
        {
            if(d[minsta][i]==1&&(id[minsta]+1<id[i]||id[i]==0))
            {
                id[i]=id[minsta]+1;
                for(int j=1;j<=path[minsta][0];j++)
                {
                    path[i][j]=path[minsta][j];

                }
                path[i][0]=path[minsta][0];

            }
        }
    }
    int nline;
    int cnt=1;
    printf("%s",name[a]);
    for(int i=2;i<path[b][0];i++)
    {
        if(line[path[b][i]][path[b][i-1]]!=line[path[b][i]][path[b][i+1]])
        {
            printf("-%d(%d)-%s",line[path[b][i]][path[b][i-1]],cnt,name[path[b][i]]);
            cnt=0;
        }
        cnt++;
    }
    printf("-%d(%d)-%s",line[b][path[b][path[b][0]-1]],cnt,name[b]);


}

