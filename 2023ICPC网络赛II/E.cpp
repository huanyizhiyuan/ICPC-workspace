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
    std::vector<int>pre(n + 1, 0);
    for(int i = 2;i <= n;i ++)
        std::cin >> pre[i];

    std::vector<std::vector<int>>G(n + 1);
    for(int i = 1;i <= m;i ++)
    {
        int x, y;
        std::cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    std::queue<int>q;
    std::vector<int>dist(n + 1, -1);
    dist[1] = 0;
    q.push(1);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(auto y:G[x])
        {
            while(dist[y] == -1)
            {
                dist[y] = dist[x] + 1;
                q.push(y);
                y = pre[y];
            }
        }
    }

    for(int i = 2;i <= n;i ++)
        std::cout << dist[i] << " \n"[i == n];
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

