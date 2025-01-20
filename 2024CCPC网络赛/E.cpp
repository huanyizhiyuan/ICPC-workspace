#include<bits/stdc++.h>
#define i64 long long
#define int i64
using PII = std::pair<int,int>;
using TIII = std::tuple<int,int,int>;
constexpr int mod = 998244353;
constexpr int inf = 1e9+5;
int n,m,k;

int ksm(int a, int b)
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
    std::cin >> n >> m;

    // 默认根结点存在。
    int ans1 = 1, ans2 = 1;
    bool ok = false;
    for(int i = 1;i <= m;i ++)
    {
        if(ok or ksm(26ll, i) > n)
            ok = true, ans1 = (ans1 + n) % mod;
        else
            ans1 = (ans1 + ksm(26ll, i)) % mod;
    }

    // 我们用二项分布
    int inv26 = ksm(26ll, mod - 2), now26 = 26ll; // 逆元


    for(int i = 1;i <= m;i ++)
    {
        // //前缀不出现的概率。
        // int p1 = ksm(inv26, i);
        // //前缀出现的概率。
        // int p2 = (1 - p1 + mod) % mod;

        ans2 += (now26 * ((1ll - ksm((1ll - ksm(inv26, i) + mod) % mod, n) + mod) % mod) % mod) % mod;
        ans2 %= mod;
        now26 = (now26 * 26ll) % mod;
    }

    std::cout << ans1 << " " << ans2 << "\n";
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

