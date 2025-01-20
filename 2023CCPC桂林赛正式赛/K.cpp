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
    std::vector<std::vector<int>>a(m + 1, std::vector<int>(n + 1, 0));

    // n * m
    for(int i = 1;i <= m;i ++)
        for(int j = 1;j <= n;j ++)
            std::cin >> a[i][j];

    std::vector<int>ve(n + 1, 0);
    std::set<std::vector<int>>se1, se2;

    for(int i = 1;i <= m;i ++)
    {
        // 不需要clear，原先的要保留。
        // 插入一个新的，相当于DP的操作。
        // 相当于每次插入一个新的，然后再考虑之前剩余的每一个不同的排列。
        se2.insert(a[i]);
        for(auto v:se1)
        {
            for(int j = 1;j <= n;j ++)
                ve[j] = v[a[i][j]];
            se2.insert(ve);
        }
        se1 = se2;
    }

    std::cout << se1.size() << "\n";
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

