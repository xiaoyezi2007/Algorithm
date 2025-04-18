#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int p[40];
void clear()
{
    memset(p,0,sizeof(p));
}
void find(int x)
{
    int i;
    for(i=0; i<=31; i++)
    {
        if ((x>>i&1)==0)
            continue;
        if (p[i]==0)
        {
            p[i]=x;
            return;
        }
        x^=p[i];
    }
}
int main()
{
    int n,x,i,flag,ans;
    while(~scanf("%d",&n))
    {
        flag=0;
        ans=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&x);
            if(x==0)
                flag=1;
            else
                find(x);
        }
        for(i=0; i<=31; i++) if(p[i]!=0) ans++;
        if(flag==1&&(1<<ans)==n)
            puts("YaHaHa!");
        else
            puts("DaKiki.");
        clear();
    }
}
