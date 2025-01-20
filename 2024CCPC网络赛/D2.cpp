#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 998244353;
constexpr int inf = 1e9+5;
int n,m,k;

void solve()
{
    std::string s, t;
    std::cin >> s >> t;
    n = s.size();
    m = t.size();
    s = " " + s;
    t = " " + t;

    std::vector f(n + 1,std::vector<std::vector<int>>(m + 1,std::vector<int>(m + 1, 0)));

    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            if(s[i] == t[j])
                f[i][j][j] = 1;

    for(int i = 1;i <= n;i ++)
    {
        for(int l = 1;l <= m;l ++)
            for(int r = l;r <= m;r ++)
            {
                //1、继承的。
                f[i][l][r] = (f[i][l][r] + 2 * f[i - 1][l][r]) % mod;

                //2、拼接的。
                for(int k = l;k <= r - 1;k ++)
                    f[i][l][r] = (f[i][l][r] + f[i - 1][l][k] * f[i - 1][k + 1][r]) % mod;
            }

        for(int j = 1;j <= m;j ++)
        {
            if(s[i] == t[j])
            {
                //3、必须要经过中间份子的。
                // f[i][j][j] = 1;
                for(int l = 1;l <= j - 1;l ++)
                    for(int r = j + 1;r <= m;r ++)
                        f[i][l][r] = (f[i][l][r] + f[i - 1][l][j - 1] * f[i - 1][j + 1][r]) % mod;

                for(int l = 1;l <= j - 1;l ++)
                    f[i][l][j] = (f[i][l][j] + f[i - 1][l][j - 1]) % mod;

                for(int r = j + 1;r <= m;r ++)
                    f[i][j][r] = (f[i][j][r] + f[i - 1][j + 1][r]) % mod;
            }
        }
    }

    // for(int i = 1;i <= n;i ++)
    // {
    //     for(int j = 1;j <= m;j ++)
    //     {
    //         for(int k = 1;k <= m;k ++)
    //         {
    //             std::cout << f[i][j][k] << " ";
    //         }
    //         std::cout << " \n--------------------\n";
    //     }
    //     std::cout << "================================\n";
    // }

    std::cout << f[n][1][m] << "\n";
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
