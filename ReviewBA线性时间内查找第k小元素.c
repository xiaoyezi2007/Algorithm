#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a[4000005];
int partition(int *a,int p,int r)
{
    int x=a[r];
    int i=p-1;
    int temp,j;
    for(j=p;j<=(r-1);j++)
    {
        if(a[j]<=x)
        {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    return i+1;
}
int select(int *a,int p,int r,int i)
{
    if(p==r) return a[p];
    int q=partition(a,p,r);
    int k=q-p+1;
    if(i==k) return a[q];
    else if(i<k) return select(a,p,q-1,i);
    else return select(a,q+1,r,i-k);
}
int main()
{
    int i,n,k;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=select(a,1,n,k);
    printf("%d",ans);

}
