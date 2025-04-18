#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char s1[1000005],s2[1000005];
int kmp[1000005];
int main()
{
    scanf("%s%s",s1,s2);
    int len1=strlen(s1),len2=strlen(s2);
    int k=0;
    kmp[0]=0,kmp[1]=0;
    for(int i=1;i<len2;i++)
    {
        while(k!=0&&s2[i]!=s2[k]) k=kmp[k];
        if(s2[i]==s2[k])
        {
            k++;
            kmp[i+1]=k;
        }
        else
        {
            kmp[i+1]=0;
        }
    }
    k=0;
    for(int i=0;i<len1;i++)
    {
        while(k!=0&&s1[i]!=s2[k]) k=kmp[k];
        if(s1[i]==s2[k]) k++;
        if(k==len2) printf("%d\n",i-len2+2);
    }
    for(int i=1;i<=len2;i++) printf("%d ",kmp[i]);
}
