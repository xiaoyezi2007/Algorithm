#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define min2(a,b) ((a)<(b)?(a):(b))
#define M 1000000007
long long int ksm(long long int a, long long int b){
    long long int  res = 1;
    while(b) {
        if(b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
int main()
{
    long long int a,b;
    long long int ans=a*ksm(b,M-2)%M; //ans=(a/b)%M;
}
