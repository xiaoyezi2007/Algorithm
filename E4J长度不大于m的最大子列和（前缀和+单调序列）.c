#include<stdio.h>
#include<math.h>
long long int s[2000020];//��¼ǰ���������֮��
int p[1000020];//��¼��Ӧ����
int main()
{
    int n,m,i,k,top=0,tail=0,t,flag;
    long long int ans=0,ans1=-10000000;
    scanf("%d%d",&n,&m);
    if(m>n)//�ռ����Ե����ռ�����
        m=n;

    for(i=1;i<=n;i++)//����
    {
        scanf("%lld",&s[i]);//ֱ�Ӽ����ܺ�
        s[i]+=s[i-1];
        if(i<=m&&s[i]>ans1)//��ans�ĳ����ж�
            ans1=s[i];
    }
    for(i=(n+1);i<=(n+m);i++)//��Χ��һ��Ȧ����ǰ����������ֳ�����һ��
    {
        s[i]=s[n]+s[i-n];
    }

    for(k=1;k<=(m+n);k++)//�������ݲ���
    {
        if((s[k]-s[p[top]])>=ans1)//������õ�һ���ϵĺͣ�������p[top]һ���ǿ��Լ�������С��Ӷ�������
            ans1=s[k]-s[p[top]];
        while(tail&&tail>top&&s[p[tail-1]]>=s[k])//������ϣ�����ͽ������У�topһ��С���˴���whileѰ�Ҳ����λ�ã��ȸ����Ŀ���ֱ�Ӻ��ԡ���tail<top�������¿��ǡ�
        {
            tail--;
        }


            p[tail++]=k;//��k��Ϊ�Ǳ긳ֵ����Ӧλ�ã�tail++�Ӷ����ǵ���һ���������
        while(p[top]<=(k-m))//��֤����С��m
        {
            top++;
        }

    }

    printf("%lld",ans1);//������
}
