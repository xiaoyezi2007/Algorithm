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
int h[30];
char s[100005];
int check(int l,int r){
    int flag=1,i,j;
    for(i=l,j=r;i<=j;++i,--j){
        if(s[i]!=s[j]){
            flag=0;
            break;
        }
    }
    return flag;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        int flag=0;
        for(int i=0;i<29;i++) h[i]=0;
        int len = strlen(s);
        char last=s[len-1];
        if(len==1)
        {
            cout << "NaN\n";
            continue;
        }
        for(int i=0;i<len;i++)
        {
            if(i>0&&s[i]==last)
            {
                if(check(i,len-1))
                {
                    flag=1;
                    break;
                }
            }
            h[s[i]-'a']++;
            if(h[s[i]-'a']>1) break;
        }
        if(flag) cout << "HE\n";
        else cout << "NaN\n";
    }


    by xiaoyezi2007;
}
