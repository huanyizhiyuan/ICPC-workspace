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

    std::vector<int>b;
    std::vector<int>vis(n * m + 1, 0);
    std::vector<int>num(n * m + 1, 0);
    std::vector<std::vector<int>>a(n + 1, std::vector<int>(m + 1, 0));

    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
        {
            std::cin >> a[i][j];
            b.push_back(a[i][j]);
        }

    std::sort(b.begin() + 1, b.end());
    b.erase(std::unique(b.begin() + 1, b.end()), b.end());

    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            a[i][j] = std::lower_bound(b.begin() + 1, b.end(), a[i][j]) - b.begin();

    int ans = 0;

    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
        {
            vis[a[i][j]] += i;
            num[a[i][j]] ++;
            ans += (num[a[i][j]] * i - vis[a[i][j]]);
        }

    vis.assign(n * m + 1, 0);
    num.assign(n * m + 1, 0);

    for(int i = 1;i <= m;i ++)
        for(int j = 1;j <= n;j ++)
        {
            vis[a[j][i]] += i;
            num[a[j][i]] ++;
            // std::cout << std::format("i = {}, j = {}, a[j][i] = {}, num = {}, vis = {}\n", i, j, a[j][i], num[a[j][i]], vis[a[j][i]]);
            ans += (num[a[j][i]] * i - vis[a[j][i]]);
        }

    std::cout << ans * 2 << "\n";
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

