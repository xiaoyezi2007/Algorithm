#include <stdio.h>
#include<math.h>
int main()
{
    int n,o,i;
    long long int v,s,sum=0,maxsum=0,value=0,minvalue;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld%lld%d",&v,&s,&o);

        if(o==0)//������v=0���
            v=0;
        if(sum<=0)//��ʱ��Ȼ��ѡȡ��ǰ�Ɑ�̲���Ϊ�µ���㣬�ʸ���start�������sum
        {
            sum=s;
            value=v;
        }
        else//��ʱ����ͳ��sum��
        {
            sum+=s;
            value+=v;
        }

        if(sum>maxsum)//��������͸�������Ϊ����maxsum
        {
            maxsum=sum;
            minvalue=value;//����ȡ���߿���ֵ�µ��̲裬�������
        }
        if(value<minvalue&&sum==maxsum)//����ֵ��ͬ�����ȡ������
            minvalue=value;

    }
    printf("%lld %lld",maxsum,minvalue);

}
