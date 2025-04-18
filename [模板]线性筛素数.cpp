#include <bits/stdc++.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
using namespace std;
vector<int> pri;
int notprime[100000005];


int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)
    {
        if(notprime[i]==0) pri.push_back(i);
        for(int x:pri)
        {
            if(i*x>n) break;
            notprime[i*x]=1; //all the i*k is not prime
            if(i%x==0) break; //this mean i*k has already been found by x*k
        }
    }
    while(q--)
    {
        int ask;
        scanf("%d",&ask);
        printf("%d\n",pri[ask-1]);
    }
}

