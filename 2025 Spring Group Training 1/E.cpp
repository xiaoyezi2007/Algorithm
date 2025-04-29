#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+7;
int dp1[N][5],dp2[N][5];
int dp[N][5][5];
int a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[i] %= 3;
    }
    dp1[0][0]=1;
    long long ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<3;j++) {
        for(int k=0;k<3;k++) {
            dp[i][j][k] += dp[i-1][(3-(3-a[i]+k)*a[i]%3+j)%3][(3-a[i]+k)%3];
            /*if(a[i]==0) {
                dp[i][0][k] = dp[i-1][0][(3-a[i]+k)%3];
                dp[i][1][k] = dp[i-1][1][(3-a[i]+k)%3];
                dp[i][2][k] = dp[i-1][2][(3-a[i]+k)%3];
            }
            if(a[i]==1) {
                dp[i][0][k] = dp[i-1][0][(3-a[i]+k)%3];
                dp[i][1][k] = dp[i-1][1][(3-a[i]+k)%3];
                dp[i][2][k] = dp[i-1][2][(3-a[i]+k)%3];

            }
            if(a[i]==2) {
                dp[i][0][k] += dp[i-1][0][(3-a[i]+k)%3];
            }*/
        }}
        dp[i][0][a[i]]++;
        ans += dp[i][0][0]+dp[i][0][1]+dp[i][0][2];
    }
    std::cout<<ans;
    /*while(true) {
        int x,y,z;
        cin>>x>>y>>z;
        cout<<dp[x][y][z];
    }*/
    /*for(int i=1;i<=n;i++) {
        for(int j=0;j<3;j++) {
            dp1[i][j] = dp1[i-1][(3-a[i]+j)%3];
        }
        dp1[i][a[i]]++;
        // dp1[i][0] = dp1[i-1][(3-a[i])%3];
        // dp1[i][1] = dp1[i-1][(1-a[i]+3)%3];

        dp[i][j][k] =  dp[i-1][][(3-a[i]+k)%3] ;



        dp[i][0][a[i]]++;

    }
    dp2[0][0]=1;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<3;j++) {
            dp2[i][0][0] = dp2[i-1][a[i]];
        }
        dp2[i][0]++;
    }*/
    return 0;
}
