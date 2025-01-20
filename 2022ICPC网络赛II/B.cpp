#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define int i64
using PII = std::pair<int, int>;
using TIII = std::tuple<int, int, int>;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e9 + 5;
int n, m, k;

int dp[105][105][105];

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n + 1, 0);
    int res = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i=2;i<=n;i++){
          dp[0][i-1][i]=(a[i]-a[i-1])*(a[i]-a[i-1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int l = 1; l <= n; l++) {
            for (int r = l; r <= n; r++) {

                dp[i][l][r] = max(dp[i][l][r], dp[i - 1][l][r]);
                if(r-l==i) dp[i][l][r] = max(dp[i][l][r], dp[i][l][r-1 ] + (a[r] - a[l]) * (a[r] - a[l]));
                else dp[i][l][r] +=dp[i-1][l][r];
                cerr << i << " " << l << " " << r << " " << dp[i][l][r] << endl;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i][1][n] << endl;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    //std::cin>>T;
    while (T--)
    {
        solve();
    }
    return  0;
}

