#include<stdio.h>
long long int mi(long long int k,long long int n)//快速幂计算k的n次方
{
    long long int ans=1;
    while(n)
    {
        if(n&1)        //如果n的当前末位为1
            ans =(ans*k);  //ans乘上当前的a
        k =(k*k);        //a自乘
        n >>= 1;       //n往右移一位
    }
    return ans;
}

int main()
{
    long long int n,k;
    scanf("%lld%lld",&n,&k);
    printf("%lld",mi(n,k));
}
