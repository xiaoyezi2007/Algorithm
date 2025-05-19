#include <bits/stdc++.h>
using namespace std;
#define max2(a,b) (a)>(b)?(a):(b)
#define xiaoyezi2007 0
#define by return
#define ep 1e-7
#define mod  (1llu<<63)
#define ll long long int
#define ull unsigned long long int
#define MAXN 3000
char s[100005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    cin >> n;
    cin >> s;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[0])
        {
            cout << "Wrong Answer";
            return 0;
        }
    }
    cout << "Correct";

    by xiaoyezi2007;
}
