#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define ep 1e-7
#define mod  998244353
#define ll long long int
#define MAXN 300005
int fa[MAXN];
vector<int> son[MAXN];
int sum[MAXN]; // sum[i]:the sum of node of subtree of i
int weight[MAXN]; // weight[i]: the maximum of size of all the subtree of i ,include 'upper subtree'.
int n; // the sum of node on the whole tree
int Centroid;
int ans[MAXN];
void GetCentroid(int current) // find the Centroid of whole tree
{
    sum[current]=1;
    weight[current]=0;
    for(int x:son[current])
    {
        GetCentroid(x);
        sum[current]+=sum[x];
        weight[current]=max2(weight[current],sum[x]);
    }
    weight[current]=max2(weight[current],n-sum[current]);
    if(weight[current] <= n/2) // Centroid is equal to the weight of i is no more than half of all sum of node
    {
        if(Centroid !=0)
        {
            Centroid = current;
        }
    }

}

void dfs(int node) // get Centroid of subtree of every node
{
    sum[node] = 1;
    ans[node]=node;
    for(int x:son[node])
    {
        dfs(x);
        sum[node]+=sum[x];
        weight[node]=max2(weight[node],sum[x]);
    }
    for(int x:son[node])
    {
        int p=ans[x];
        while(p!=node)  //when two trees are connected, the Centroid of new tree is on the path of two Centroids of two old trees.
        {
            if(max2(weight[p],sum[node]-sum[p]) <= sum[node]/2)
            {
                ans[node]=p;
                break;
            }
            else p=fa[p];
        }
    }
    return;
}

int main()
{
    scanf("%d",&n);
    int q;
    scanf("%d",&q);
    for(int i=2;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        fa[i]=x;
        son[x].push_back(i);
    }
    dfs(1);
    while(q--)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",ans[x]);
    }

}
//by xiaoyezi2007
