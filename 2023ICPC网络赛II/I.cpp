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
    std::vector<int>a(n + 10, 0);
    std::vector<double>f(n + 10, 0);
    for(int i = 0;i < n;i ++)
        std::cin >> a[i];

    double res = n;
    int p;
    for(int i = 0;i < n;i ++)
    {
        std::cin >> p;
        if(!p)
            continue;
        double q = 1.0 * p / 100000;
        // 先走i步走到 第i位置；
        // 花费1次"赌命"，看是否成功；共花费i + 1
        // 成功的期望次数为1/q次 所以需要1/q-1次失败，
        // 每次失败，需要走 i-a[i]+1次，多的一次是用来"赌命"
        f[i] = 1.0 * i + 1 + (1.0 / q - 1) * (i - a[i] + 1);
        res = std::min(f[i], res);
    }

    std::cout << std::fixed << std::setprecision(12);
    std::cout << res << "\n";
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

