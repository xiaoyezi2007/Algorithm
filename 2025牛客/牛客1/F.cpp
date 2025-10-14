#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.14159265358
double r,d;
struct node
{
    double x,y,z;
}S,T;

double pmul(node a,node b)
{
    return a.x*b.x+a.y*b.y+a.z*b.z;
}
double len(node a)
{
    return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}
double dis(node a,node b)
{
    double sita = acos(pmul(a,b)/len(a)/len(b));
    return r*sita;
}

void solve()
{
    double ans = 0;
    cin >> r >> d;
    cin >> S.x >> S.y >> S.z >> T.x >> T.y >> T.z;
    if(d<pi*r/2)
    {
        ans+=2*pi*r*r*(1-cos(d/r));
        ans+=2*dis(S,T)*r*sin(d/r);
    }
    else if(dis(S,T)+2*d>=2*pi*r) ans = 4*pi*r*r;
    else
    {
        double angle = pi-d/r; // the angle of spherical caps that invalid of one point
        double sita = acos(pmul(S,T)/len(S)/len(T)); // sita between S and T
        double mid = (2*angle+sita)/2;
        double A = 2*asin(sqrt(sin(mid-angle)*sin(mid-sita)/(sin(angle)*sin(sita))));
        double B = 2*asin(sin(mid-angle)/sin(angle));
        ans = 2*2*2*A*sin(angle/2)*sin(angle/2)-2*(2*A+B-pi);
        ans = 4*pi*r*r-ans*r*r;
    }
    printf("%.8f\n",ans);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
