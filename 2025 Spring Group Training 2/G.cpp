#include<bits/stdc++.h>
using namespace std;
char s[1000007];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int dp1=0,dp2=0;
        int n,cnt0=0;
        cin>>n;
        scanf("%s",s);
        int i=0;
        while(s[i]=='0') {
            i++;
            cnt0++;
        }
        if(s[i+1]=='1') {
            dp1=dp2=cnt0;
            while(s[i+1]=='1') i++;
        } else {
            dp1 =cnt0;
            if(cnt0==0) {
                dp2=0;
            } else {
                dp2 = cnt0+1;
            }
        }
        cnt0=0,i++;
        while(s[i]){
            if(s[i]=='0') {
                cnt0++;
            } else {
                int t1,t2;
                if(s[i+1]!='1') {
                    t1 = min(max(dp2,(cnt0+1)/2),max(dp1, (cnt0)/2+1));
                    t2 = min(max(dp2,cnt0/2+1),max(dp1,(cnt0+1)/2+1));
                } else {
                    t1 = t2 =  min(max(dp1,cnt0/2+1),max(dp2,(cnt0+1)/2));
                    while(s[i+1]=='1') i++;
                }
                dp1 = t1;
                dp2 = t2;
                cnt0 = 0;
            }
            i++;
        }
        if(cnt0) {
            cout<<min(max(dp1,cnt0+1),max(dp2,cnt0))<<endl;
        } else {
            cout<<min(dp1,dp2)<<endl;
        }
    }
    return 0;
}
