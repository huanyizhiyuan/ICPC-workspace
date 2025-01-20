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
    std::cin >> n;

    m = n + 1 >> 1;

    std::vector<int>b(n + 1, 0);
    std::vector<PII>a(n + 1);
    for(int i = 1;i <= n;i ++)
    {
        int x, y;
        std::cin >> x >> y;
        a[i] = {x, y};
        b[i] = x;
    }

    std::sort(b.begin() + 1, b.end());

    auto check = [&](int x) -> int
    {
        int res = n + 1 - (std::upper_bound(b.begin() + 1, b.end(), x - 1) - b.begin());

        std::vector<int>ve;
        for(int i = 1;i <= n;i ++)
        {
            auto [u, v] = a[i];
            if(u >= x and v < x)
                ve.push_back(-1);
            else if(u < x && v >= x)
                ve.push_back(1);
            else
                ve.push_back(0);
        }

        int sum = 0, mx = 0;
        for(auto v : ve)
        {
            sum += v;
            if(sum < 0)
                sum = 0;
            mx = std::max(mx, sum);
        }

        res += mx;

        // std::cout << res << "\n";

        if(res >= m)
            return true;
        else
            return false;
    };

    // check(6);

    int l = 1, r = inf, ans = l, mid;
    while(l <= r)
    {
        mid = l + r >> 1;
        if(check(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }

    std::cout << ans << "\n";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T=1;
    // std::cin >> T;
    while(T--)
    {
        solve();
    }
    return  0;
}

