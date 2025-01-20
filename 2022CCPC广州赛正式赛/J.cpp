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
    int st, en;
    std::cin >> n;
    std::cin >> st >> en;

    std::cin >> m;

    //f[i][j]，从起点出发，走到i，且路径长度为j
    std::vector<int>vis(n + 1, 0);
    std::vector<int>dis(n + 1, inf);
    std::vector<std::vector<int>>G(n + 1);
    std::vector f(n + 1,std::vector<int>(m + 1, 0));

    for(int i = 1;i <= m;i ++)
    {
        int x, y;
        std::cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    auto dijkstra = [&]()
    {
        dis[st] = 0;
        f[st][0] = 1;
        std::priority_queue<PII,std::vector<PII>,std::greater<PII>>q;
        q.emplace(0,st);
        while(!q.empty())
        {
            auto u = q.top().second;q.pop();
            if(vis[u])continue;
            vis[u] = 1;
            for(auto v:G[u])
            {
                if(dis[v] >= dis[u] + 1)
                {
                    dis[v] = dis[u] + 1;
                    f[v][dis[v]] = (f[v][dis[v]] + f[u][dis[u]]) % mod;
                    q.emplace(dis[v],v);
                }
            }
        }
    };

    dijkstra();

    std::cout << f[en][dis[en]] << "\n";
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
