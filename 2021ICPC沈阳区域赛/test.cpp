#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 1e9+7;
constexpr int inf = 1e9+5;
int n,m,k;

std::vector<std::vector<PII>>G;
std::vector<std::vector<int>>c;//颜色

void solve()
{
    std::cin >> n >> m;

    G.resize(n + 1);
    c.assign(n + 1, std::vector<int>(32, -1));

    for(int i = 1;i <= m;i ++)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        G[x].emplace_back(y, z);
        G[y].emplace_back(x, z);
    }

    int ans = 0, sum = 0;

    // 返回连通块1的个数，并给出总结点数。
    auto dfs = [&](auto self, int u, int pos, int color) -> int
    {
        sum ++;

        c[u][pos] = color;

        // 1的个数。
        int res = color;

        for(auto [v, w] : G[u])
        {
            if(c[v][pos] == -1)
                res += self(self, v, pos, (w >> pos & 1) ^ color);

            else if(c[v][pos] != (w >> pos & 1) ^ color)
            {
                std::cout << -1 << "\n";
                std::exit(0);
            }
        }

        return res;
    };

    int p = 1;

    for(int i = 0;i <= 30;i ++)
    {
        for(int j = 1;j <= n;j ++)
        {
            if(c[j][i] == -1)
            {
                // 连通块总共点的个数。
                sum = 0;

                int t = dfs(dfs, j, i, 1);

                ans += p * std::min(t, sum - t);
            }
        }
        p <<= 1ll;
    }

    std::cout << ans << "\n";
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

