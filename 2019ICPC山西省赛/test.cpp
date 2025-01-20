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

    std::vector<std::string>s(n + 1);
    std::vector<std::vector<int>>G(n * m + 1);
    std::vector<std::vector<int>>a(n + 1, std::vector<int>(m + 1, 0));

    for(int i = 1;i <= n;i ++)
    {
        std::cin >> s[i];
        s[i] = " " + s[i];
    }

    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            std::cin >> a[i][j];

    std::map<char, int>mp;

    mp['u'] = 0;
    mp['d'] = 1;
    mp['l'] = 2;
    mp['r'] = 3;

    std::vector<int> dx = {-1, 1, 0, 0};
    std::vector<int> dy = {0, 0, -1, 1};

    auto get = [&](int x, int y) -> int
    {
        return  (x - 1) * m + y;
    };

    auto check = [&](int x, int y) -> bool
    {
        if(x < 1 || y < 1 || x > n || y > m)
            return true;
        return false;
    };

    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
        {
            char ch = s[i][j];

            int x = i + dx[mp[ch]] * a[i][j];
            int y = j + dy[mp[ch]] * a[i][j];

            if(check(x, y)) continue ;

            G[get(i, j)].push_back(get(x, y));
        }

    std::vector<int>dfn(n * m + 10, 0);
    std::vector<int>low(n * m + 10, 0);
    std::vector<int>bel(n * m + 10, 0);
    std::vector<int>ins(n * m + 10, 0);
    std::vector<int>cnt(n * m + 10, 0);


    int id = 0, scc = 0, ans = 0;
    std::stack<int>stk;

    auto tarjan = [&](auto self,int u) -> void
    {
        dfn[u] = low[u] = ++ id;
        stk.push(u);
        ins[u] = 1;
        for(auto v : G[u])
        {
            if(!dfn[v])
            {
                self(self, v);
                low[u] = std::min(low[u], low[v]);
            }
            else if(ins[v])
                low[u] = std::min(low[u], dfn[v]);
        }
        if(dfn[u] == low[u])
        {
            int v;
            scc ++;
            do
            {
                v = stk.top();stk.pop();
                ins[v] = 0;
                bel[v] = scc;
                cnt[scc]++;
            }while(v!=u);
        }
    };

    for(int i=1;i<=n * m;i++)
        if(!dfn[i])
            tarjan(tarjan, i);

    //拓扑排序。
    std::vector<int>in(scc + 1, 0);
    std::vector<int>out(scc + 1, 0);
    for(int i = 1;i <= n * m;i++)
        for(auto v : G[i])
            if(bel[i] != bel[v])
            {
                in[bel[v]] ++;
                out[bel[i]] ++;
            }

    int cnt1 = 0, cnt2 = 0;

    for(int i = 1;i <= scc;i ++)
    {
        if(out[i] == 1)
            continue ;
        else if(out[i] == 0)
            cnt1 ++;
        else
        {
            std::cout << "No\n";
            return ;
        }
    }

    for(int i = 1;i <= scc;i ++)
    {
        if(in[i] == 1)
            continue ;
        else if(in[i] == 0)
            cnt2 ++;
        else
        {
            std::cout << "No\n";
            return ;
        }
    }

    // std::cout << std::format("cnt1 = {}, cnt2 = {}\n", cnt1, cnt2);

    std::cout << ((cnt1 == 1 and cnt2 == 1) ? "Yes\n" : "No\n");
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T=1;
    std::cin >> T;
    while(T--)
    {
        solve();
    }
    return  0;
}

