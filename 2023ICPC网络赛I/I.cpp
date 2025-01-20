#include<bits/stdc++.h>
constexpr int mod = 998244353;
constexpr int inf = 1e9+5;
int n,m,k;

void solve()
{
    std::string s;
    std::cin >> n >> s;
    s = " " + s;

    int ans = 0;

    /*
        j = 0 全要
        j = 1 不要小写字母
        j = 2 不要大写字母
        j = 3 不要小写字母和大写字母
        j = 4 不要数字
        j = 5
        j = 6
    */

    for(int j = 0;j < 7;j ++)
    {
        //到i个的时候，限制的状压状态。
        std::vector f(n + 1, std::vector<int>(62, 0));

        if(s[1] >= 'a' and s[1] <= 'z')
        {
            int st = s[1] - 'a';
            if(!(j & 1))
                f[1][st] = 1;
            if(!(j & 2))
                f[1][st + 26] = 1;
        }
        else if(s[1] >= 'A' and s[1] <= 'Z')
        {
            //小写字母之上。
            int st = s[1] - 'A' + 26;
            if(!(j & 2))
                f[1][st] = 1;
        }
        else if(s[1] >= '0' and s[1] <= '9')
        {
            //小写字母 + 数字之上。
            int st = s[1] - '0' + 52;
            if(!(j & 4))
                f[1][st] = 1;
        }
        else
        {
            if(!(j & 1))
                for(int i = 0;i < 26;i ++)
                    f[1][i] = 1;
            if(!(j & 2))
                for(int i = 26;i < 52;i ++)
                    f[1][i] = 1;
            if(!(j & 4))
                for(int i = 52;i < 62;i ++)
                    f[1][i] = 1;
        }

        for(int i = 2;i <= n;i ++)
        {
            int sum = 0;
            for(int k = 0;k < 62;k ++)
                sum = (sum + f[i - 1][k]) % mod;

            if(s[i] >= 'a' and s[i] <= 'z')
            {
                //第 i 个位置使用该小写字母的方案数等于前面所有字符方案总数 sum
                //减去与 i-1 位置上使用该小写字母的方案数，确保相邻的字符不相同。
                int st = s[i] - 'a';
                if(!(j & 1))
                    f[i][st] = (sum - f[i - 1][st] + mod) % mod;
                if(!(j & 2))
                    f[i][st + 26] = (sum - f[i - 1][st + 26] + mod) % mod;
            }
            else if(s[i] >= 'A' and s[i] <= 'Z')
            {
                int st = s[i] - 'A' + 26;
                if(!(j & 2))
                    f[i][st] = (sum - f[i - 1][st] + mod) % mod;
            }
            else if(s[i] >= '0' and s[i] <= '9')
            {
                int st = s[i] - '0' + 52;
                if(!(j & 4))
                    f[i][st] = (sum - f[i - 1][st] + mod) % mod;
            }
            else
            {
                if(!(j & 1))
                    for(int k = 0;k < 26;k ++)
                        f[i][k] = (sum - f[i - 1][k] + mod) % mod;
                if(!(j & 2))
                    for(int k = 26;k < 52;k ++)
                        f[i][k] = (sum - f[i - 1][k] + mod) % mod;
                if(!(j & 4))
                    for(int k = 52;k < 62;k ++)
                        f[i][k] = (sum - f[i - 1][k] + mod) % mod;
            }
        }

        int res = 0;
        for(int i = 0;i < 62;i ++)
            res = (res + f[n][i]) % mod;

        if(__builtin_popcount(j) % 2 == 0)
            ans = (ans + res) % mod;
        else
            ans = (ans - res + mod) % mod;
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

