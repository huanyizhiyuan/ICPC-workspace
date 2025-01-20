#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 1e9+7;
constexpr int inf = 1e9+5;
int n,m,k;

int gcd(int x, int y)
{
    if (x == 0) return y;
    if (y == 0) return x;
    return std::gcd(x, y);
}

void solve()
{
    std::cin >> n >> k;

    std::vector<int>a(n + 1, 0);

    for(int i = 1;i <= n;i ++)
        std::cin >> a[i];

    std::vector<int>pre(n + 1, 0), suf(n + 2, 0);

    for(int i = 1;i <= n;i ++)
        pre[i] = gcd(pre[i - 1], a[i]);
    for(int i = n;i >= 1;i --)
        suf[i] = gcd(suf[i + 1], a[i]);

    int ans = pre[n];

    for(int i = 1;i <= n;i ++)
    {
        if(pre[i] != pre[i - 1])
        {
            int res = pre[i - 1];
            for(int j = i;j <= n;j ++)
            {
                res = gcd(res, a[j] + k);
                ans = std::max(ans, gcd(res, suf[j + 1]));
            }
        }
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

