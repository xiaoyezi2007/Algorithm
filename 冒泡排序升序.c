#include<stdio.h>
void bubblesort(int b[],int n)//����Ϊ������ð����������bΪ���������飬nΪ��Ԫ�ظ���
{
    int i,j,temp,flag;
    for(i=1;i<=n;i++)
    {
        flag=0;
        for(j=1;j<=n-i;j++)//ע��ӵ�һλ��ʼ����
        {
            if(b[j]>b[j+1])
            {
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            return;
    }
}
int find(int x[],int key,int SIZE)
{
    int j;
    for(j= 1; j<=SIZE; j++ )
        if( x[j]==key )
            return j;
    return-1;
}
int main()
{
    int n,i,k;
    int t[110]={0};
    int a[110]={0};
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        t[a[i]]=1;
    }
    bubblesort(a,n);
    while(~scanf("%d",&k))
    {
        if(t[k]==0)
            printf("-1\n");
        else
            printf("%d\n",find(a,k,n));
    }
}
