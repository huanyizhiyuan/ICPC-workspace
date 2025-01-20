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
    std::cin >> n;
    std::vector<int>f(n + 1, 0);
    std::vector<int>a(n + 1, 0);
    std::map<int,int>mp;
    for(int i = 1;i <= n;i ++)
    {
        std::cin >> a[i];
        mp[a[i]] ++;
    }

    int ans = 1, ok = 0, res = 0;
    f[1] = 1;
    for(int i = 2;i <= n;i ++)
        f[i] = (f[i - 1] * i) % mod;

    for(auto [v, u]:mp)
    {
        if(u >= 1)
        {
            ok ++;
            ans = (ans * f[u]) % mod;
        }
    }

    std::sort(a.begin() + 1, a.end());

    for(int i = 1;i <= n;i ++)
        for(int j = i;j <= n;j ++)
            res += (a[j] - a[i]);

    if(ok >= 2)
        std::cout << res << " " << ans * 2 % mod << "\n";
    else
        std::cout << res << " " << ans << "\n";
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

