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
int p[10][3];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int ans=0;
        int aaa=-1;
        for(int i=0; i<8; i++)
        {
            cin >> p[i][0] >> p[i][1] >> p[i][2];
        }
        for(int i=0; i<8; i++)
        {
            int time[10]= {0};
            int sum[10]= {0};
            int cnt=0;
            for(int j=0; j<8; j++)
            {
                if(j==i) continue;
                int d=0;
                for(int k=0; k<3; k++) d+=(p[j][k]-p[i][k])*(p[j][k]-p[i][k]);
                int flag=0;
                for(int k=0; k<cnt; k++)
                {
                    if(sum[k]==d) time[k]++,flag=1;
                }
                if(flag==0)
                {
                    time[cnt]++;
                    sum[cnt++]=d;
                }
            }

            if(cnt!=3)
            {
                ans=1;
                break;
            }
            for(int j=0; j<cnt; j++)
            {
                for(int i=1; i<cnt; i++)
                {
                    if(sum[i-1]>sum[i])
                    {
                        swap(sum[i-1],sum[i]);
                        swap(time[i-1],time[i]);
                    }
                }

            }
            if(time[0]!=3||time[1]!=3||time[2]!=1)
            {
                ans=1;
                break;
            }
            if(aaa=-1) aaa=sum[0];
            if(sum[0]!=aaa||sum[1]!=2*aaa||sum[2]!=3*aaa)
            {
                ans=1;
                break;
            }
        }
        if(ans) cout << "NO\n";
        else cout << "YES\n";
    }

    by xiaoyezi2007;
}
