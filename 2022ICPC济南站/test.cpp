#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 1e9+7;
constexpr int inf = 2e18+5;
int n,m,k;

void solve()
{
    std::cin >> n >> m;

    std::set<int> se;
    std::vector<int> a(n + 1, 0);

    for (int i = 1; i <= n; i ++)
    {
        std::cin >> a[i];
        int x = a[i];
        while(x)
        {
            se.insert(x);
            x >>= 1;
        }
    }

    int ans = inf;

    // 枚举所有的数
    for (auto v : se)
    {
        std::vector<int> tmp;

        auto get = [&](int x)
        {
            if(x <= v) return v - x;

            int res = 0;

            while(x / 2 >= v)
            {
                res ++;
                x >>= 1;
            }

            // 如果后面减。
            int tmp = res + x - v;

            // 变成0不可以操作。
            // 否则可以 / 2再加，多 / 2没意义。
            if(x / 2 > 0)
            {
                x >>= 1;
                return std::min(tmp, res + 1 + v - x);
            }
            else
                return tmp;
        };

        for (int i = 1; i <= n; i ++)
            tmp.push_back(get(a[i]));

        std::sort(tmp.begin(), tmp.end());

        ans = std::min(ans, std::accumulate(tmp.begin(), tmp.begin() + n - m, 0ll));
    }

    std::cout << ans << "\n";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T=1;
    std::cin>>T;
    while(T--)
    {
        solve();
    }
    return  0;
}

