#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#define min2(a,b) (a)<(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 200005
int gcdf(int a,int b)
{
    int i;
    if(a<b)
        {
            i=a;
            a=b;
            b=i;
        }
    if(b==0)
        return a;
    while(a%b!=0)
    {
        i=a%b;
        a=b;
        b=i;

    }
    return b;
}
int zi,mu;
double ans=0;
char s[100005];
int cnt[30];
int main()
{
    scanf("%s",s);
    int n=strlen(s);
    for(int i=1;i<=26;i++)
    {
        int l=0,r=0;
        int k=0,max=1000000;
        while(r<n)
        {
                cnt[s[r]-'a']++;
                if(cnt[s[r]-'a']==1) k++;

            while(k>i)
            {
                cnt[s[l]-'a']--;
                if(cnt[s[l]-'a']==0)
                {
                    k--;
                }
                l++;
            }
            while(k==i&&cnt[s[l]-'a']>1)
            {
                cnt[s[l]-'a']--;
                l++;
            }
            r++;
            if(max>r-l&&k==i) max=r-l;
        }
        if(max!=1000000 && 1.0*i*i/max>ans+ep)
        {
            ans=1.0*i*i/max;
            zi=i*i;
            mu=max;
        }
        for(int i=0;i<26;i++)
        {
            cnt[i]=0;
        }
    }
    int g=gcdf(zi,mu);
    printf("%d %d",zi/g,mu/g);

}
