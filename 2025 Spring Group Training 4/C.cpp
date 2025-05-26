#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define xiaoyezi2007 0
#define by return
#define ep 1e-7
#define mod  (1llu<<63)
#define ll long long int
#define ull unsigned long long int
#define MAXN 3000
char s1[1000005];
char s2[2000];
int kmp[1000005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> s1;
    int ans=0;
    for(int i=0;i<1000;i++)
    {
        s2[i]=s1[i];
    }
    int len1=strlen(s1),len2=strlen(s2);
    int k=0;
    kmp[0]=0,kmp[1]=0;
    for(int i=1;i<len2;i++)
    {
        while(k!=0&&s2[i]!=s2[k]) k=kmp[k];
        if(s2[i]==s2[k])
        {
            k++;
            kmp[i+1]=k;
        }
        else
        {
            kmp[i+1]=0;
        }
    }
    k=0;
    for(int i=0;i<len1;i++)
    {
        while(k!=0&&s1[i]!=s2[k]) k=kmp[k];
        if(s1[i]==s2[k]) k++;
        if(k==len2) ans++;
    }

    if(ans>=100) cout << "No";
    else cout << "Yes";

    by xiaoyezi2007;
}
