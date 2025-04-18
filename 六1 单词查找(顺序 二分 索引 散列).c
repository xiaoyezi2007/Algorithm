#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define max2(a,b) ((a)>(b)?(a):(b))
#define NHASH  3001

#define MULT  37
struct list
{
    char w[30];
    struct list *next;
};
unsigned int hash(char *str)

{

    unsigned int h=0;

    char *p;



    for(p=str; *p!='\0'; p++)

        h = MULT*h + *p;

    return h % NHASH;

}
char dictionary[3500][30];
char word[30];
int suoyin[30];
char hashlist[3010][3500][30];
int hashlistlist[3010];
int main()
{
    FILE *in=fopen("dictionary3000.txt","r");

    int n=0,op;
    while(fscanf(in,"%s",dictionary[n])!=EOF)
    {
        n++;
    }
    for(int i=0; i<n; i++) //建立索引
    {
        suoyin[dictionary[i][0]-'a'+1]++;
    }
    for(int i=1; i<=26; i++)
    {
        suoyin[i]+=suoyin[i-1];
    }
    for(int i=0;i<n;i++)//建立hash
    {
        unsigned int k=hash(dictionary[i]);
        strcpy(hashlist[k][hashlistlist[k]],dictionary[i]);
        hashlistlist[k]++;
    }
    while(scanf("%s%d",word,&op)!=EOF)
    {
        int time=0;
        if(op==1)
        {
            for(int i=0; i<n; i++)
            {
                time++;
                if(strcmp(word,dictionary[i])==0)
                {
                    printf("1 %d\n",time);
                    break;
                }
                else if(strcmp(word,dictionary[i])<0)
                {
                    printf("0 %d\n",time);
                    break;
                }
            }
        }
        else if(op==2)
        {
            int left=0,right=n-1,mid;
            while(left<=right)
            {
                mid=(left+right)/2;
                time++;
                if(strcmp(word,dictionary[mid])==0)
                {
                    printf("1 %d\n",time);
                    break;
                }
                else if(strcmp(word,dictionary[mid])>0)
                {
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
            if(left>right) printf("0 %d\n",time);
        }
        else if(op==3)
        {
            int left=suoyin[word[0]-'a'],right=suoyin[word[0]-'a'+1]-1,mid;
            while(left<=right)
            {
                mid=(left+right)/2;
                time++;
                if(strcmp(word,dictionary[mid])==0)
                {
                    printf("1 %d\n",time);
                    break;
                }
                else if(strcmp(word,dictionary[mid])>0)
                {
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
            if(left>right) printf("0 %d\n",time);
        }
        else
        {
            unsigned int k=hash(word);
            int flag=0;
            for(int i=0;i<hashlistlist[k];i++)
            {
                time++;
                if(strcmp(word,hashlist[k][i])==0)
                {
                    printf("1 %d\n",time);
                    flag=1;
                    break;
                }
                else if(strcmp(word,hashlist[k][i])<0)
                {
                    printf("0 %d\n",time);
                    flag=1;
                    break;
                }
            }
            if(flag==0) printf("0 %d\n",time);


        }
    }
    fclose(in);
}

