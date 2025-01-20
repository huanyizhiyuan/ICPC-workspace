#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 998244353;
constexpr int inf = 1e9+5;
int n,m,k;

void solve()
{
    std::string s, t;
    std::cin >> s >> t;
    n = s.size();
    m = t.size();
    s = " " + s;
    t = " " + t;

    std::vector f(n + 1,std::vector<std::vector<int>>(m + 2,std::vector<int>(m + 1, 0)));

    //不成立的情况。
    for(int i = 0;i <= n;i ++)
        for(int j = 1;j <= m + 1;j ++)
            for(int k = 0;k < j;k ++)
                f[i][j][k] = 1;

    for(int i = 1;i <= n;i ++)
        for(int l = 1;l <= m;l ++)
            for(int r = l;r <= m;r ++)
            {
                for(int k = l - 1;k <= r;k ++)
                    f[i][l][r] = (f[i][l][r] + f[i - 1][l][k] * f[i - 1][k + 1][r]) % mod;
                for(int k = l - 1;k < r;k ++)
                    if(s[i] == t[k + 1])
                        f[i][l][r] = (f[i][l][r] + f[i - 1][l][k] * f[i - 1][k + 2][r]) % mod;
            }

    std::cout << f[n][1][m] << "\n";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T=1;
    // std::cin>>T;
    while(T--)
    {
        solve();
    }
    return  0;
}

