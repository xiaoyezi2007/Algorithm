#include<stdio.h>
long long int mi(long long int k,long long int n)//�����ݼ���k��n�η�
{
    long long int ans=1;
    while(n)
    {
        if(n&1)        //���n�ĵ�ǰĩλΪ1
            ans =(ans*k);  //ans���ϵ�ǰ��a
        k =(k*k);        //a�Գ�
        n >>= 1;       //n������һλ
    }
    return ans;
}

int main()
{
    long long int n,k;
    scanf("%lld%lld",&n,&k);
    printf("%lld",mi(n,k));
}
