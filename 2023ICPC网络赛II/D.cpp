#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 1e9+7;
constexpr int inf = 1e16+5;
int n,m,k;

void solve()
{
    std::cin >> n;
    std::vector<int>visx(n + 1, 0);
    std::vector<int>visy(n + 1, 0);
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1, 0));

    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
            std::cin >> a[i][j];

    int res = 0;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
            if(a[i][j] <= 0)
            {
                visx[i] = 1;
                visy[j] = 1;
                res += a[i][j];
            }

    //考虑row
    int ansx = 0, ansy = 0;
    for(int i = 1;i <= n;i ++)
    {
        if(!visx[i])
        {
            int mn = inf;
            for(int j = 1;j <= n;j ++)
                mn = std::min(mn, a[i][j]);
            ansx += mn;
        }
    }

    for(int i = 1;i <= n;i ++)
    {
        if(!visy[i])
        {
            int mn = inf;
            for(int j = 1;j <= n;j ++)
                mn = std::min(mn, a[j][i]);
            ansy += mn;
        }
    }

    std::cout << res + std::min(ansx, ansy) << "\n";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    std::cin>>T;
    while(T--)
    {
        solve();
    }
    return  0;
}

