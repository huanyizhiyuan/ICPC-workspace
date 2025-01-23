#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int, int>;
using TIII = std::tuple<int, int, int>;
constexpr int inf = 1e18 + 5;
constexpr int mod = 1e9 + 7;
int n, m, k;
std::vector<int> a, sum;

void solve()
{
    std::cin >> n;
    a.assign(n + 1, 0);
    sum.assign(n + 1, 0);
    for (int i = 1; i <= n; i ++)
    {
        std::cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int len = 1; len <= n; len ++)
    {
        for (int l = 1, r;l <= n - len + 1; l ++)
        {
            r = l + len - 1;
            int now = sum[r] - sum[l - 1];
            for (int j = 2; j * j <= now; j ++)
            {
                if (now % j == 0)
                {
                    std::cout << len - 1 << "\n";
                    return ;
                }
            }
        }
    }
    std::cout << -1 << "\n";
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
