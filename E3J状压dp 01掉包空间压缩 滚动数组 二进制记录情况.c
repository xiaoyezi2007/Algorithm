#include<stdio.h>
#include<math.h>
#define mod 1000000007
long long int f[2][16777300];//定义数组，表示以第i格结尾的，以二进制表示的该格及前k-1格的涂色情况下的棒棒糖总数
long long int a[301];//用来储存贡献值
long long int d[200000];
int main()
{
    int n,k,i,j,h;
    long long int sum=0,s;
    scanf("%d%d",&n,&k);
    for(i=1; i<=n; i++)//输入贡献值
    {
        scanf("%lld",&a[i]);
    }
    i=0;
    f[1][0]=1;//对开头的情况给出限定，这里默认未涂色格子得到的贡献值为1，乘起来就不产生影响
    f[0][0]=1;
    f[1][1]=a[1];
    f[0][1]=a[2];
    f[0][2]=a[1];
    for(s=0;s<=((1<<k)-1);s++)
    {
        if((s&(s>>1))==0)
        {
            d[i]=s;
            i=i+1;
        }
    }
    j=(i-1);
    for(i=3; i<=n; i++)//进行递推
    {
        for(h=0; h<=j; h++)//枚举每种涂色情况
        {
            if(d[h]%4==3)//若i与i-1格均涂黑，不符合要求
                f[i%2][d[h]]=0;
            else if(d[h]%2==0)//若i格不涂，则相当于前面情况之和
            {
                f[i%2][d[h]]=(f[(i-1)%2][d[h]>>1]+f[(i-1)%2][(d[h]>>1)|(1<<(k-1))])%mod;
            }
            else//若i格涂黑但i-1不涂，则还需剔除k格前为黑的情况
            {
                f[i%2][d[h]]=(f[(i-1)%2][d[h]>>1]*a[i])%mod;
            }

        }
    }
    for(h=0; h<=j; h++)//统计最后的总数
        sum=(sum+f[n%2][d[h]])%mod;
    if(sum)//输出
        printf("%lld",sum-1);
    else//防止余数为负
    {
        sum=mod;
        printf("%lld",sum-1);
    }
}
