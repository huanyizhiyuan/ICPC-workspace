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
    std::string s;
    std::cin >> s;
    s = " " + s;

    std::string ans = "";
    std::vector<int>vis(300, 0);
    std::map<char,char>mp;

    // 初始化。
    for(int i = 'a';i <= 'z';i ++)
        mp[i] = '?';

    for(int i = 1;i <= n;i ++)
    {
        char ch = s[i];
        int x = vis[ch];

        if(vis[ch] != 1)
        {
            for(int i = 'a';i <= 'z';i ++)
            {
                if(i == ch)
                    vis[i] = 1;
                else if(vis[i])
                {
                    if(x == 0)
                        vis[i] ++;
                    else
                    {
                        if(vis[i] <= x)
                            vis[i] ++;
                    }
                }
            }
        }

        for(auto & [v, w] : mp)
        {
            if(vis[v])
                w = 'a' + (vis[v] - 1);
        }

        std::string now = s.substr(1, i);

        for(int j = 0;j < i;j ++)
            now[j] = mp[now[j]];

        ans = std::max(ans, now);

        // std::cout << now << "\n";
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

