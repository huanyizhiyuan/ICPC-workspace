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
    std::cin >> n;

    std::vector<int> a(n + 1, 0);

    int ans = 0;

    for (int i = 1; i <= n; i ++)
    {
        std::cin >> a[i];
        ans = (ans + a[i]) % mod;
    }

    std::cout << ans * ksm(n, mod - 2) % mod << "\n";
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

