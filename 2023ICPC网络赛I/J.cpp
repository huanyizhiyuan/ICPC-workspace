#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 1e9+7;
constexpr int inf = 1e9+5;
constexpr double s2 = std::sqrt(2);
int n,m,k;

void solve()
{
    int x11, y11, x12, y12;
    int x21, y21, x22, y22;
    std::cin >> x11 >> y11 >> x12 >> y12;
    std::cin >> x21 >> y21 >> x22 >> y22;

    double ans = (std::abs((x12 + x11) - (x22 + x21)) + std::abs((y12 + y11) - (y22 + y21))) / 2.0;

    double res = std::sqrt((x21 - x22) * (x21 - x22) + (y21 - y22) * (y21 - y22)) / 2.0;

    std::cout << std::fixed << std::setprecision(12) << ans - res * s2 << "\n";
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

