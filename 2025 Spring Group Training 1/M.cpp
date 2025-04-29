#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+7;
vector<int> G[N];
int d[N];
int ans[N],a[N],cnt[N];

int main() {
    int n,k,m;
    cin>>n>>k>>m;
    std::vector<std::vector<int>> idx(n + 7, std::vector<int>(k + 7));
    int x,y;
    for(int i=0;i<m;i++) {
        cin>>x>>y;
        G[x].push_back(y);
        d[y] ++;
    }

    for(int i=0;i<n*k;i++) {
        cin>>a[i];
        idx[a[i]][cnt[a[i]]]=i;
        cnt[a[i]]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(!d[i]) q.push(i);
    }
    while(!q.empty()) {
        int top = q.front();q.pop();
        for(int i=0;i<k;i++) {
            ans[idx[top][i]] = i+1;
        }
        for(int i=0;i<G[top].size();i++) {
            d[G[top][i]]--;
            if(d[G[top][i]] == 0)
            q.push(G[top][i]);
        }
    }
    for(int i=0;i<n*k;i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}
