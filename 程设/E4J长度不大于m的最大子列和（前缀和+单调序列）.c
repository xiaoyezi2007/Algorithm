#include<stdio.h>
#include<math.h>
long long int s[2000020];//记录前面的能量块之和
int p[1000020];//记录对应坐标
int main()
{
    int n,m,i,k,top=0,tail=0,t,flag;
    long long int ans=0,ans1=-10000000;
    scanf("%d%d",&n,&m);
    if(m>n)//空间多可以当做空间正好
        m=n;

    for(i=1;i<=n;i++)//输入
    {
        scanf("%lld",&s[i]);//直接计算总和
        s[i]+=s[i-1];
        if(i<=m&&s[i]>ans1)//对ans的初步判断
            ans1=s[i];
    }
    for(i=(n+1);i<=(n+m);i++)//把围成一个圈当做前面的能量块又出现了一遍
    {
        s[i]=s[n]+s[i-n];
    }

    for(k=1;k<=(m+n);k++)//处理数据部分
    {
        if((s[k]-s[p[top]])>=ans1)//和相减得到一段上的和；这里是p[top]一项是可以减到的最小项，从而结果最大
            ans1=s[k]-s[p[top]];
        while(tail&&tail>top&&s[p[tail-1]]>=s[k])//这里是希望将和降序排列，top一侧小，此处用while寻找插入的位置，比该项大的可以直接忽略。若tail<top则不再往下考虑。
        {
            tail--;
        }


            p[tail++]=k;//将k作为角标赋值给对应位置，tail++从而考虑到下一项更大的情况
        while(p[top]<=(k-m))//保证距离小于m
        {
            top++;
        }

    }

    printf("%lld",ans1);//最后输出
}
