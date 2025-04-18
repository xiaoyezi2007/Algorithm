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

        if(o==0)//白嫖则v=0免费
            v=0;
        if(sum<=0)//此时必然会选取当前这杯奶茶作为新的起点，故更改start与区间和sum
        {
            sum=s;
            value=v;
        }
        else//此时继续统计sum和
        {
            sum+=s;
            value+=v;
        }

        if(sum>maxsum)//假如区间和更大，则认为它是maxsum
        {
            maxsum=sum;
            minvalue=value;//优先取更高快乐值下的奶茶，即便更贵
        }
        if(value<minvalue&&sum==maxsum)//快乐值相同情况下取更便宜
            minvalue=value;

    }
    printf("%lld %lld",maxsum,minvalue);

}
