#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 1e9+7;
constexpr int inf = 1e9+5;
int n,m,k;

void solve()
{
    std::cin >> n >> m;
    std::vector<int>pre(n + 1, 0);
    std::vector<int>siz(n + 1, 0);
    std::iota(pre.begin(), pre.end(), 0);

    auto find = [&](auto self, int u) -> int
    {
        if(u == pre[u])
            return u;
        return pre[u] = self(self, pre[u]);
    };

    for(int i = 1;i <= m;i ++)
    {
        int x, y;
        std::cin >> x >> y;
        pre[find(find, x)] = find(find, y);
    }

    for(int i = 1;i <= n;i ++)
    {
        int zu = find(find, i);
        siz[zu] ++;
    }

    int mn = inf, mn2 = inf, ans = 0;

    for(int i = 1;i <= n;i ++)
    {
        int zu = find(find, i);

        if(zu != i)
            continue;

        if(siz[zu] < mn)
        {
            mn2 = mn;
            mn = std::min(mn, siz[zu]);
        }
        else if(siz[zu] <= mn2)
            mn2 = siz[zu];

        ans += siz[zu] * (siz[zu] - 1) / 2;
    }

    if(ans - m == 0)
        std::cout << mn * mn2 << "\n";
    else
        std::cout << ans - m << "\n";
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

