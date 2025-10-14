#include<bits/stdc++.h>
using namespace std;
int tot,tag[1001],vis[1001],ma[1001],pre[1001],f[1001],n,m,ans; // ans is sum of pipei, ma[i] save which node pipei with i.
vector<int> v[1001]; queue<int> q;
inline int find(int x){while (x!=f[x]) x=f[x]=f[f[x]]; return x;}
inline int lca(int x,int y){
	++tot;
	while (1){
		if (x){
			x=find(x); if (tag[x]==tot) return x;
			tag[x]=tot; x=pre[ma[x]];
		}
		swap(x,y);
	}
}
inline void flower(int x,int y,int p){
	while (find(x)!=p){
		pre[x]=y; y=ma[x]; vis[y]=1; q.push(y);
		if (find(x)==x) f[x]=p;
		if (find(y)==y) f[y]=p;
		x=pre[y];
	}
}
inline void bfs(int st){
	for (int i=1;i<=n;++i) pre[i]=vis[i]=0,f[i]=i;
	while (!q.empty()) q.pop();
	vis[st]=1; q.push(st);
	while (!q.empty()){
		int x=q.front(); q.pop();
		for (int y:v[x]) if (find(y)!=find(x) && vis[y]!=2){
			if (vis[y]==1){
				int l=lca(x,y); flower(x,y,l); flower(y,x,l); continue;
			}
			vis[y]=2; pre[y]=x;
			if (!ma[y]){
				int px=y;
				while (px){
					int py=pre[px],pz=ma[py];
					ma[px]=py; ma[py]=px; px=pz;
				}
				++ans; return;
			}
			vis[ma[y]]=1; q.push(ma[y]);
		}
	}
}
void clear()
{
    tot = ans = 0;
    for(int i=0;i<=n;i++) tag[i] = vis[i] = ma[i] = pre[i] = f[i] = 0;
}
void init() {for (int i=1;i<=n;++i) if (!ma[i]) bfs(i);}
char s[105][105];
int an[105][100005];
int main(){
	cin>>n>>m;
	clear();
	for (int i=1;i<=m;++i){
		int x,y; cin>>x>>y;
		v[x].push_back(y),v[y].push_back(x);
	}
	init();
	cout<<ans<<'\n'; for (int i=1;i<=n;++i) cout<<ma[i]<<' ';
	return 0;
}
