#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-10
#define mod  998244353
#define ll long long int
#define MAXN 600
int n;
struct ben
{
    double x,y;
}p[100005],s[100005];
double check(ben a1,ben a2,ben b1,ben b2)
{
    return (a2.x-a1.x)*(b2.y-b1.y)-(b2.x-b1.x)*(a2.y-a1.y);
}
double d(ben p1,ben p2)
{
    return sqrt((p2.y-p1.y)*(p2.y-p1.y)+(p2.x-p1.x)*(p2.x-p1.x));
}
bool cmp(ben p1,ben p2)
{
    double tmp=check(p[1],p1,p[1],p2);
    if(tmp>0)
		return 1;
    if(tmp==0&&d(p[0],p1)<d(p[0],p2))
		return 1;
    return 0;
}
void solve()
{

    cin >> n;
    double mid;
    for(int i=1;i<=n;i++)
    {
        cin >> p[i].x >> p[i].y;
        if(i!=1&&p[i].y<p[1].y)
        {
            mid=p[1].y;p[1].y=p[i].y;p[i].y=mid;
            mid=p[1].x;p[1].x=p[i].x;p[i].x=mid;
        }
    }
    sort(p+2,p+1+n,cmp);
    s[1]=p[1];
    int cnt=1;
    for(int i=2;i<=n;i++)
    {
        while(cnt>1&&check(s[cnt-1],s[cnt],s[cnt],p[i])<0)
			cnt--;
        cnt++;
        s[cnt]=p[i];
    }
    s[cnt+1]=p[1];
    double ans=0;
    for(int i=1;i<=cnt;i++)
		ans+=d(s[i],s[i+1]);//然后s里存好了凸包序列，只需要把两两距离累加就行
    printf("%.2lf\n",ans);

}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    solve();
}

//by xiaoyezi2007
