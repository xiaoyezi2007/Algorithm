#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char str[1002];
char *otter[10001];
int main()
{
    int len,n,m,u,v,i;
    scanf("%d%d",&n,&m);
    getchar();
    for(i=1; i<=n; i++)
    {
        gets(str);
        len = strlen(str);
        otter[i] = (char*)malloc(len*sizeof(char) + 1);	// 多开一位是为了存储字符串最后的空字符，直接写 len + 1 也可
        strcpy(otter[i], str);

    }
    for(i=1; i<=m; i++)
    {
        scanf("%d%d",&u,&v);
        char *tem = otter[u];
        otter[u] = otter[v];
        otter[v] = tem;
    }
    for(i=1;i<=n;i++)
    {
        puts(otter[i]);
        free(otter[i]);
    }
}
