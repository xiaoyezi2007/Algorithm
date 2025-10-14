#include<stdio.h>
#include<math.h>
void move(int n,char from,char to);
void h(int n,char from,char via,char to);

int main()
{
    char from,via,to;
    int n;
    scanf("%c %c %c",&from,&via,&to);
    scanf("%d",&n);
    h(n,from,via,to);


}

void move(int n,char from,char to)
{
    printf("Eika moved Koishi %02d form the %c to the %c\n",n,from,to);
}
void h(int n,char from,char via,char to)
{
    if(n==1)
    {
        move(n,from,to);
        return;
    }
    h(n-1,from,to,via);
    move(n,from,to);
    h(n-1,via,from,to);
}
