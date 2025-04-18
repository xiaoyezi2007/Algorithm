#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
#define mid ((l+r)/2)
int a[MAXN],b[MAXN],c[MAXN];
struct lmz{int mx,sum,pre,suf;}t[MAXN*4],s[MAXN*4]; // store b[i]-b[i-1] in the leaf of segment tree
void pushupt(int p){
    t[p].sum=t[p<<1].sum+t[p<<1|1].sum; // sum of leaf ,that is b[r]-b[l]
    t[p].pre=max(t[p<<1].pre,t[p<<1].sum+t[p<<1|1].pre); // the max in all segment when the left node is l
    t[p].suf=max(t[p<<1|1].suf,t[p<<1|1].sum+t[p<<1].suf); // the max in all segment when the right node is r
    t[p].mx=max(max(t[p<<1].mx,t[p<<1|1].mx),t[p<<1].suf+t[p<<1|1].pre); // suf + pre is for the segment that cross left and right children simultaneously,mx is ans as well
}
void pushups(int p){
    s[p].sum=s[p<<1].sum+s[p<<1|1].sum;
    s[p].pre=max(s[p<<1].pre,s[p<<1].sum+s[p<<1|1].pre);
    s[p].suf=max(s[p<<1|1].suf,s[p<<1|1].sum+s[p<<1].suf);
    s[p].mx=max(max(s[p<<1].mx,s[p<<1|1].mx),s[p<<1].suf+s[p<<1|1].pre);
}
void build(int l,int r,int p){
    if(l==r) {
        t[p].mx=t[p].sum=t[p].pre=t[p].suf=b[l]-b[l-1];
        s[p].mx=s[p].sum=s[p].pre=s[p].suf=c[l]-c[l-1];
        return;
    }
    build(l,mid,p<<1),build(mid+1,r,p<<1|1);
    pushupt(p),pushups(p);
}
lmz merge_query(lmz x,lmz y){ // make no sense there
    lmz ans;
    ans.sum=x.sum+y.sum;
    ans.pre=max(x.pre,x.sum+y.pre);
    ans.suf=max(y.suf,y.sum+x.suf);
    ans.mx=max(max(x.mx,y.mx),x.suf+y.pre);
    return ans;
}
void updatet(int l,int r,int p,int c,int v){
    if(l==r){t[p].mx=t[p].sum=t[p].pre=t[p].suf=v;return;}
    (mid>=c)?updatet(l,mid,p<<1,c,v):updatet(mid+1,r,p<<1|1,c,v); // update its child and push up to this node
    pushupt(p);
}
void updates(int l,int r,int p,int c,int v){
    if(l==r){s[p].mx=s[p].sum=s[p].pre=s[p].suf=v;return;}
    (mid>=c)?updates(l,mid,p<<1,c,v):updates(mid+1,r,p<<1|1,c,v);
    pushups(p);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--)
    {
        int n,q;
        cin >> n >> q;
        n--;
        for(int i=0;i<=n;i++)
        {
            cin >> a[i];
            b[i]=a[i]-i;
            c[i]=-(a[i]+i);
        }
        if(n==0)
        {
            int p,x;
            cout << "0\n";
            while(q--)
            {
                cin >> p >> x;
                cout << "0\n";
            }
        }
        else
        {
            build(1,n,1);
            int ans = max(0,max(t[1].mx,s[1].mx));
            cout << ans << '\n';
            while(q--)
            {
                int p,x;
                cin >> p >> x;
                p--;
                a[p]=x;
                b[p]=x-p;
                c[p]=-(x+p);
                if(p>0)
                {
                    updatet(1,n,1,p,b[p]-b[p-1]);
                    updates(1,n,1,p,c[p]-c[p-1]);
                }
                if(p<n)
                {
                    updatet(1,n,1,p+1,b[p+1]-b[p]);
                    updates(1,n,1,p+1,c[p+1]-c[p]);
                }

                ans=max(0,max(t[1].mx,s[1].mx));
                cout << ans << '\n';
            }
        }

    }
    return 0;
}
//by xiaoyezi2007
