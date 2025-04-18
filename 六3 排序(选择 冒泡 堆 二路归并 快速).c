#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define min2(a,b) ((a)<(b)?(a):(b))
int time=0;
int a[10000],tmp[10000];
void adjust(int i,int n)

{

    int j,temp;

    temp=a[i];

    j=2*i+1;

    while(j<n)
    {

        if(j<n-1 && a[j]<a[j+1])

            j++;

        time++;
        if(temp>=a[j])
        {
            break;
        }



        a[(j-1)/2]=a[j];

        j=2*j+1;

    }

    a[(j-1)/2]=temp;

}
void merge(int left,int leftend,int rightend)

{

    int i=left, j=leftend+1, q=left;

    while(i<=leftend && j<=rightend)

    {

        time++;
        if(a[i]<=a[j])

            tmp[q++]=a[i++];

        else

            tmp[q++]=a[j++];

    }

    while(i<=leftend)

        tmp[q++]=a[i++];

    while(j<=rightend)

        tmp[q++]=a[j++];

    for(i=left; i<=rightend; i++)

        a[i]=tmp[i];

}
void msort(int left,int right)
{
    int cen;
    if(left<right)
    {
        cen=(left+right)/2;
        msort(left,cen);
        msort(cen+1,right);
        merge(left,cen,right);
    }
}
void quickSort(int left,int right)

{

    int i, last;

    if(left<right)
    {

        last=left;

        for(i=left+1; i<=right; i++)

        {
            time++;
            if(a[i]<a[left])
            {
                last++;
                int temp=a[last];
                a[last]=a[i];
                a[i]=temp;
            }
        }


        int ttemp=a[left];
        a[left]=a[last];
        a[last]=ttemp;

        quickSort(left,last-1);

        quickSort(last+1,right);

    }

}
int main()
{
    int n,op;
    scanf("%d%d",&n,&op);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    if(op==1)   //Ñ¡ÔñÅÅÐò
    {
        for(int i=0; i<n; i++)
        {
            int min=a[i],mmin=i;
            for(int j=i+1; j<n; j++)
            {
                time++;
                if(a[j]<min)
                {
                    min=a[j];
                    mmin=j;
                }
            }
            int temp=a[i];
            a[i]=a[mmin];
            a[mmin]=temp;
        }
    }
    else if(op==2)   //Ã°ÅÝÅÅÐò
    {
        for(int i=0; i<n; i++)
        {
            int flag=0;
            for(int j=0; j<n-i-1; j++)
            {
                time++;
                if(a[j]>a[j+1])
                {
                    flag=1;
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
            if(flag==0) break;
        }
    }
    else if(op==3)   //¶ÑÅÅÐò
    {
        int temp;
        for(int i=n/2-1; i>=0; i--)
        {
            adjust(i,n);
        }
        for(int i=n-1; i>=1; i--)
        {
            temp=a[i];
            a[i]=a[0];
            a[0]=temp;
            adjust(0,i);
        }
    }
    else if(op==4)
    {
        msort(0,n-1);
    }
    else if(op==5)
    {
        quickSort(0,n-1);
    }
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n%d",time);
}

