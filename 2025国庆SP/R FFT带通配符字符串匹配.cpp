#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<limits.h>
extern inline int max(int aa,int bb){return aa>bb?aa:bb;}
extern inline int min(int aa,int bb){return aa>bb?bb:aa;}
extern inline void swapc(char *aa,char *bb){*aa^=*bb,*bb^=*aa,*aa^=*bb;}
extern inline void swap(int *aa,int *bb){*aa^=*bb,*bb^=*aa,*aa^=*bb;}
extern inline void swapll(long long *aa,long long *bb){*aa^=*bb,*bb^=*aa,*aa^=*bb;}
extern inline int read()
{
	int r=0,f=0;char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))r=r*10+(c^'0'),c=getchar();
	return f?-r:r;
}

#define mod 998244353
extern inline long long ksm(long long aa,int p)
{
	long long ans=1;
	while(p)
	{
		if(p&1)(ans*=aa),ans%=mod;
		(aa*=aa),aa%=mod,p>>=1;
	}return ans%mod;
}

int rev[400005];
extern inline void getrev(int n)
{
	for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|(i&1?n>>1:0);
}
const long long g=3;
extern inline void NTT(long long *a,int n,int f)
{
	for(int i=0;i<n;i++)if(i<rev[i])swapll(a+i,a+rev[i]);
	for(int i=1;i<n;i<<=1)
	{
		long long wn=ksm(g,(mod-1)/(i<<1));if(f<0)wn=ksm(wn,mod-2);
		for(int j=0;j<n;j+=(i<<1))
		{
			long long w=1;
			for(int k=0;k<i;k++,(w*=wn),w%=mod)
			{
				long long x=a[j+k],y=w*a[j+k+i]%mod;
				a[j+k]=(x+y)%mod,a[j+k+i]=(x-y)%mod;
			}
		}
	}
	if(f<0)
	{
		long long inv=ksm(n,mod-2);
		for(int i=0;i<n;i++)(a[i]*=inv),a[i]%=mod;
	}
}

int n,m;
char C1[100005],C2[100005];
int a[1<<17|3],b[1<<17|3];

extern inline int toi(char c)
{
	if(c=='#') return 0;
	if(isdigit(c)) return c-'0'+1;
	if(islower(c)) return c-'a'+11;
	if(isupper(c)) return c-'A'+37;
	if(c=='_') return 63;
	if(c=='.') return 64;
	exit(114514);return 0;
}
/*
0~9: 1~11
a~z: 11~36
A~Z: 37~62
_: 63
.: 64
*/

long long A[1<<17|3],B[1<<17|3],P[1<<17|3];

signed main()
{
	getrev(1<<17);
	n=read(),m=read();
	scanf("%s",C1),scanf("%s",C2);
//	reverse(C2,C2+m);
	for(int l=0,r=m-1;l<r;l++,r--) swapc(C2+l,C2+r);
	for(int i=0;i<n;i++) a[i]=toi(C1[i]);
	for(int i=0;i<m;i++) b[i]=toi(C2[i]);

	int len=(1<<17);
	for(int i=0;i<len;i++) A[i]=1ll*a[i]*a[i]%mod*a[i]%mod,B[i]=b[i];
	NTT(A,len,1),NTT(B,len,1);
	for(int i=0;i<len;i++) P[i]+=A[i]*B[i]%mod,P[i]%=mod;

	for(int i=0;i<len;i++) A[i]=a[i],B[i]=1ll*b[i]*b[i]%mod*b[i]%mod;
	NTT(A,len,1),NTT(B,len,1);
	for(int i=0;i<len;i++) P[i]+=A[i]*B[i]%mod,P[i]%=mod;

	for(int i=0;i<len;i++) A[i]=1ll*a[i]*a[i]%mod,B[i]=1ll*b[i]*b[i]%mod;
	NTT(A,len,1),NTT(B,len,1);
	for(int i=0;i<len;i++) P[i]-=A[i]*B[i]%mod*2%mod,P[i]%=mod;

	NTT(P,len,-1);
//	for(int i=0;i<len;i++) printf("%lld ",P[i]); putchar('\n');
	int flag=0;
	for(int i=m-1;i<n;i++)if(P[i]==0) printf("%d ",i-m+1),flag=1;
	if(!flag) printf("FAIL");
	return 0;
}
