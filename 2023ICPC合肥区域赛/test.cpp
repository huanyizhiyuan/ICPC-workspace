#include<bits/stdc++.h>
#define i64 long long
// #define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 1e9+7;
constexpr int inf = 2e9+5;
int n,m,k;

std::vector<bool>vis;
std::vector<int>dis;
std::vector<int>dis2;
std::vector<std::vector<PII>>G;
std::vector<TIII>edge;

void solve()
{
    std::cin >> n >> m;

    G.resize(n + 1);
    edge.resize(m + 1);
    dis.assign(n + 1, inf);
    dis2.assign(n + 1, inf);

    for(int i = 1;i <= m;i ++)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        G[x].emplace_back(y, z);
        G[y].emplace_back(x, z);
        edge[i] = {x, y, z};
    }

    auto dijkstra = [&](int st, auto & ve)
    {
        std::priority_queue<PII, std::vector<PII>, std::greater<PII>>q;

        ve[st] = 0;

        q.emplace(0, st);

        vis.assign(n + 1, false);

        while(!q.empty())
        {
            int u = q.top().second; q.pop();

            if(vis[u]) continue ;
            vis[u] = 1;

            for(auto [v, w] : G[u])
            {
                if(std::max(w, ve[u]) < ve[v])
                {
                    ve[v] = std::max(w, ve[u]);
                    q.emplace(ve[v], v);
                }
            }
        }
    };

    dijkstra(1, dis);
    dijkstra(n, dis2);

    // for(int i = 1;i <= n;i ++)
    //     std::cout << std::format("dis[i] = {}, dis2[i] = {}\n", dis[i], dis2[i]);

    int ans = inf;

    for(int i = 1;i <= m;i ++)
    {
        //我们选择当前的边为最大边。
        auto [x, y, z] = edge[i];

        int now = std::max(dis[x], dis2[y]);

        // std::cout << std::format("x = {}, y = {}, dis[x] = {}, dis2[y] = {}, now = {}, z = {}\n", x, y, dis[x], dis2[y], now, z);

        if(now <= z)
            ans = std::min(ans, z + now);

        now = std::max(dis[y], dis2[x]);

        if(now <= z)
            ans = std::min(ans, z + now);
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

