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
    for(int i = 1;i <= n;i ++)
    {
        std::cin >> s[i];
        s[i] = " " + s[i];
    }

    int ans = 0;
    for(int i = 1;i <= n - 1;i ++)
        for(int j = 1;j <= m - 1;j ++)
        {
            if(s[i][j] == 'c' and s[i][j + 1] == 'c' and s[i + 1][j] == 'p' and s[i + 1][j + 1] == 'c')
                ans ++;
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

