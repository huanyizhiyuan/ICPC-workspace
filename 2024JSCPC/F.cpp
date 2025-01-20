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
    std::cin >> n >> k;
    std::vector<int>a(n + 1, 0);
    for(int i = 1;i <= n;i ++)
        std::cin >> a[i];

    int ans = 0;
    std::cout << std::fixed << std::setprecision(10) << "\n";
    for(int i = 1;i <= n;i ++)
    {
        if(i < k)
        {
            ans += a[i];
            continue ;
        }
        ans += a[i];
        ans -= a[i - k];
        int res = ans;
        if(res * 1.0 / k < 1024)
            std::cout << res * 1.0 / k << " KiBps\n";
        else
            std::cout << res * 1.0 / k / 1024 << " MiBps\n";
    }
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

