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
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++) v[i].push_back(j),v[j].push_back(i),m+=2;
    }
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    int dcnt = 0;
	while(m>0)
    {
        clear();
        init();
        int cnt = 1;
        for(int i=1;i<=n;i++)
        {
            int x = ma[i];
            if(x==0) an[i][2*dcnt] = cnt+dcnt*n*2,an[i][2*dcnt+1] = dcnt*n*2+2*n-cnt+1,cnt++;
            else
            {
                if(s[i][x] == '1')
                {
                    an[i][2*dcnt] = cnt+1+dcnt*n*2,an[i][2*dcnt+1] = dcnt*n*2+2*n-cnt+1;
                    an[x][2*dcnt] = cnt+dcnt*n*2,an[x][2*dcnt+1] = dcnt*n*2+2*n-cnt-1+1;
                    cnt+=2;
                }
                auto iter = remove(v[i].begin(),v[i].end(),x);
                v[i].erase(iter,v[i].end());
                //cout << i << v[i].size() << '\n';
                m--;
            }
        }
        dcnt++;
    }

	for(int i=1;i<=n;i++)
    {
        cout << 2*dcnt << ' ';
        for(int j=0;j<2*dcnt;j++) cout << an[i][j] << ' ';
        cout << '\n';
    }
	return 0;
}
