#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 200005
int cmp(const void *p1,const void *p2)
{
    double *a1=(double *)p1;
    double *a2=(double *)p2;
    if(a1[0]>a2[0]) return -1;
    if(a1[0]<a2[0]) return 1;
    return 0;
}
double utr[40][2];
int ans[10];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%lf",&utr[i][0]);
    }
    int girlcnt=0;
    for(int i=0; i<n; i++)
    {
        scanf("%lf",&utr[i][1]);

    }
    qsort(utr,n,sizeof(utr[0]),cmp);
    double ansout=-1;
    for(ans[0]=0; ans[0]<n-7; ans[0]++)
    {
        for(ans[1]=ans[0]+1; ans[1]<n-6; ans[1]++)
        {
            for(ans[2]=ans[1]+1; ans[2]<n-5; ans[2]++)
            {
                for(ans[3]=ans[2]+1; ans[3]<n-4; ans[3]++)
                {
                    for(ans[4]=ans[3]+1; ans[4]<n-3; ans[4]++)
                    {
                        for(ans[5]=ans[4]+1; ans[5]<n-2; ans[5]++)
                        {
                            for(ans[6]=ans[5]+1; ans[6]<n-1; ans[6]++)
                            {
                                for(ans[7]=ans[6]+1; ans[7]<n; ans[7]++)
                                {
                                    int num=0;
                                    for(int t=0; t<8; t++)
                                    {
                                        if(utr[ans[t]][1]>=1-ep&&utr[ans[t]][1]<=1+ep)
                                        {
                                            num++;
                                        }
                                    }
                                    if(utr[ans[0]][0]-utr[ans[1]][0]<=4+ep&&utr[ans[0]][0]<=12+ep&&utr[ans[1]][0]<=12+ep
                                            && utr[ans[2]][0]-utr[ans[3]][0]<=4+ep&&utr[ans[2]][0]<=10.5+ep&&utr[ans[3]][0]<=10.5+ep
                                            && utr[ans[4]][0]-utr[ans[5]][0]<=4+ep&&utr[ans[4]][0]<=9+ep&&utr[ans[5]][0]<=9+ep
                                            && utr[ans[6]][0]-utr[ans[7]][0]<=4+ep&&utr[ans[6]][0]<=8+ep&&utr[ans[7]][0]<=8+ep && num>=2)
                                    {
                                        double out=0;
                                        for(int t=0;t<8;t++)
                                        {
                                            out+=utr[ans[t]][0];
                                        }
                                        if(ansout<out) ansout=out;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(ansout<0) printf("-1");
    else printf("%.2f",79-ansout);
    return 0;

}
