#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int, int>;
using TIII = std::tuple<int, int, int>;
constexpr int inf = 1e18 + 5;
constexpr int mod = 1e9 + 7;
int n, m, k;
std::vector<PII> a;

void solve()
{
    std::cin >> n;

    a.assign(n + 1, {0, 0});

    for (int i = 1; i <= n; i ++)
    {
        int x, y;
        std::cin >> x >> y;
        a[i] = {x, y};
    }

    double ans = inf;

    for (int i = 1; i <= n; i ++)
    {
        for (int j = i + 1; j <= n; j ++)
        {
            for (int k = j + 1; k <= n; k ++)
            {
                auto [x1, y1] = a[i];
                auto [x2, y2] = a[j];
                auto [x3, y3] = a[k];

                double xx1 = x2 - x1, yy1 = y2 - y1;
                double xx2 = x3 - x1, yy2 = y3 - y1;

                if (xx1 * yy2 - xx2 * yy1 == 0) continue ;

                ans = std::min(ans, std::abs(xx1 * yy2 - xx2 * yy1));
            }
        }
    }

    std::cout << (ans == inf ? -1 : ans / 2) << "\n";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T --)
    {
        solve();
    }
    return  0;
}
