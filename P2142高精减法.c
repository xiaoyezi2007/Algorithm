#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char a[11000],b[11000],ans[11000];
int main()
{
    int flag=0;
    scanf("%s",a);
    scanf("%s",b);
    int lena=strlen(a);
    int lenb=strlen(b);
    if(lena>lenb) flag=1;
    else if(lena==lenb)
    {
        int i;
        for(i=0; i<lena; i++)
        {
            if(a[i]>b[i])
            {
                flag=1;
                break;
            }
            else if(a[i]<b[i])
            {
                break;
            }
        }
        if(i==lena)
        {
            printf("0");
            return 0;
        }
    }
    if(flag==1)
    {
        for(int i=1; i<=lena; i++)
        {
            if(i>lenb)
            {
                ans[lena-i]=a[lena-i];
            }
            else
            {
                if(a[lena-i]>=b[lenb-i]) ans[lena-i]='0'+(a[lena-i]-b[lenb-i]);
                else
                {
                    ans[lena-i]='0'+(a[lena-i]-b[lenb-i]+10);
                    for(int h=lena-i-1; h>=0; h--)
                    {
                        if(a[h]=='0')
                        {
                            a[h]='9';
                        }
                        else
                        {
                            a[h]-=1;
                            break;
                        }
                    }
                }
            }

        }
        flag=0;
        for(int i=0; i<lena; i++)
        {
            if(flag==0)
            {
                if(ans[i]>='1'&&ans[i]<='9')
                {
                    flag=1;
                    printf("%c",ans[i]);
                }
            }
            else
            {
                printf("%c",ans[i]);
            }
        }
        return 0;
    }
    else
    {
        for(int i=1; i<=lenb; i++)
        {
            if(i>lena) ans[lenb-i]=b[lenb-i];
            else
            {
                if(b[lenb-i]>=a[lena-i]) ans[lenb-i]='0'+(b[lenb-i]-a[lena-i]);
                else
                {
                    ans[lenb-i]='0'+(b[lenb-i]-a[lena-i]+10);
                    for(int h=lenb-i-1; h>=0; h--)
                    {
                        if(b[h]=='0')
                        {
                            b[h]='9';
                        }
                        else
                        {
                            b[h]--;
                            break;
                        }
                    }
                }
            }

        }
        flag=0;
        printf("-");
        for(int i=0; i<lenb; i++)
        {

            if(flag==0)
            {
                if(ans[i]>='1'&&ans[i]<='9')
                {
                    flag=1;
                    printf("%c",ans[i]);
                }
            }
            else
            {
                printf("%c",ans[i]);
            }
        }
        return 0;
    }
}
