#include<stdio.h>//返回值为读入的第一个整数
#include<math.h>
#include<string.h>
#include<stdlib.h>
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
